/*
 * @lc app=leetcode.cn id=221 lang=cpp
 *
 * [221] 最大正方形
 *
 * https://leetcode-cn.com/problems/maximal-square/description/
 *
 * algorithms
 * Medium (39.37%)
 * Likes:    460
 * Dislikes: 0
 * Total Accepted:    56.5K
 * Total Submissions: 133K
 * Testcase Example:  '[["1","0","1","0","0"],["1","0","1","1","1"],["1","1","1","1","1"],["1","0","0","1","0"]]'
 *
 * 在一个由 0 和 1 组成的二维矩阵内，找到只包含 1 的最大正方形，并返回其面积。
 * 
 * 示例:
 * 
 * 输入: 
 * 
 * 1 0 1 0 0
 * 1 0 1 1 1
 * 1 1 1 1 1
 * 1 0 0 1 0
 * 
 * 输出: 4
 * 
 */
#include "useforme.h"
// @lc code=start
class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        if(matrix.empty()){
            return 0;
        }
        int ans = 0;
        for(int i = matrix.size()-1 ; i>=0; i--){
            // int a = matrix[i][matrix[0].size()]-'0';
            if(matrix[i][matrix[0].size()-1] == '1'){
                ans = 1;
                break;
            }
        }
        for(int i = matrix[0].size()-1 ; i>=0&&ans!=1; i--){
            if(matrix[matrix.size()-1][i] == '1'){
                ans = 1;
                break;
            }
        }
        for(int i = matrix.size()-2; i>=0; i--){
            for(int j = matrix[0].size()-2; j>=0; j--){
                int a = matrix[i+1][j+1]-'0';
                int b = matrix[i+1][j]-'0';
                int c = matrix[i][j+1]-'0';
                if(matrix[i][j]!='0'&&matrix[i+1][j+1]!='0'&&matrix[i+1][j]!='0'&&matrix[i][j+1]!='0'){
                    int d = min(a, min(b,c))+1;
                    ans = max(d, ans);
                    matrix[i][j] = d +'0';
                }else{
                    ans = max(matrix[i][j]-'0',ans);
                }
            }
        }
        return ans*ans;
    }
};
// @lc code=end

