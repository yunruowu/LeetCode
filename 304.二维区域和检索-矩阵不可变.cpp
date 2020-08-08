/*
 * @lc app=leetcode.cn id=304 lang=cpp
 *
 * [304] 二维区域和检索 - 矩阵不可变
 *
 * https://leetcode-cn.com/problems/range-sum-query-2d-immutable/description/
 *
 * algorithms
 * Medium (43.17%)
 * Likes:    89
 * Dislikes: 0
 * Total Accepted:    9.3K
 * Total Submissions: 20.9K
 * Testcase Example:  '["NumMatrix","sumRegion","sumRegion","sumRegion"]\n[[[[3,0,1,4,2],[5,6,3,2,1],[1,2,0,1,5],[4,1,0,1,7],[1,0,3,0,5]]],[2,1,4,3],[1,1,2,2],[1,2,2,4]]'
 *
 * 给定一个二维矩阵，计算其子矩形范围内元素的总和，该子矩阵的左上角为 (row1, col1) ，右下角为 (row2, col2)。
 * 
 * 
 * 上图子矩阵左上角 (row1, col1) = (2, 1) ，右下角(row2, col2) = (4, 3)，该子矩形内元素的总和为 8。
 * 
 * 示例:
 * 
 * 给定 matrix = [
 * ⁠ [3, 0, 1, 4, 2],
 * ⁠ [5, 6, 3, 2, 1],
 * ⁠ [1, 2, 0, 1, 5],
 * ⁠ [4, 1, 0, 1, 7],
 * ⁠ [1, 0, 3, 0, 5]
 * ]
 * 
 * sumRegion(2, 1, 4, 3) -> 8
 * sumRegion(1, 1, 2, 2) -> 11
 * sumRegion(1, 2, 2, 4) -> 12
 * 
 * 
 * 说明:
 * 
 * 
 * 你可以假设矩阵不可变。
 * 会多次调用 sumRegion 方法。
 * 你可以假设 row1 ≤ row2 且 col1 ≤ col2。
 * 
 * 
 */
#include "useforme.h"
// @lc code=start
class NumMatrix {
public:
    vector<vector<int>> dp;
    NumMatrix(vector<vector<int>>& matrix) {
        for(int i = 0; i< matrix.size(); i++){
            vector<int> temp;
            for(int j = 0; j<matrix[0].size(); j++){
                temp.push_back(matrix[i][j]);
            }
            dp.push_back(temp);
        }
        // dp[0][0] = matrix[0][0];
        for(int i = 0; i< matrix.size(); i++){
                for(int j = 0; j < matrix[0].size(); j++){
                    // cout<<dp[i][j]<<" ";
                }
                cout<<endl;
            }
        if(matrix.size()!=0){
            for (int  i = 1; i < matrix[0].size(); i++)
            {
                dp[0][i] += dp[0][i-1];
            }
            for (int  i = 1; i < matrix.size(); i++)
            {
                dp[i][0] += dp[i-1][0];
            }
            for(int i = 1; i< matrix.size(); i++){
                for(int j = 1; j < matrix[0].size(); j++){
                    dp[i][j] += (dp[i-1][j] + dp[i][j-1] - dp[i-1][j-1]);
                }
            }
        }
        // for(int i = 0; i< matrix.size(); i++){
        //         for(int j = 0; j < matrix[0].size(); j++){
        //             cout<<dp[i][j]<<" ";
        //         }
        //         cout<<endl;
        //     }
    }
    
    int sumRegion(int row1, int col1, int row2, int col2) {
        if(row1 == 0){
            if(col1 == 0){
                return dp[row2][col2];
            }else{
                return dp[row2][col2] - dp[row2][col1-1];
            }
        }else{
            if(col1 == 0){
                return dp[row2][col2] - dp[row1-1][col2];
            }else{
                return dp[row2][col2] - dp[row2][col1-1] - dp[row1-1][col2] + dp[row1-1][col1-1];
            }
        }
        return 0;
    }
};

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix* obj = new NumMatrix(matrix);
 * int param_1 = obj->sumRegion(row1,col1,row2,col2);
 */
// @lc code=end

