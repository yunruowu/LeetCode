/*
 * @lc app=leetcode.cn id=54 lang=cpp
 *
 * [54] 螺旋矩阵
 *
 * https://leetcode-cn.com/problems/spiral-matrix/description/
 *
 * algorithms
 * Medium (39.26%)
 * Likes:    337
 * Dislikes: 0
 * Total Accepted:    51K
 * Total Submissions: 129.3K
 * Testcase Example:  '[[1,2,3],[4,5,6],[7,8,9]]'
 *
 * 给定一个包含 m x n 个元素的矩阵（m 行, n 列），请按照顺时针螺旋顺序，返回矩阵中的所有元素。
 * 
 * 示例 1:
 * 
 * 输入:
 * [
 * ⁠[ 1, 2, 3 ],
 * ⁠[ 4, 5, 6 ],
 * ⁠[ 7, 8, 9 ]
 * ]
 * 输出: [1,2,3,6,9,8,7,4,5]
 * 
 * 
 * 示例 2:
 * 
 * 输入:
 * [
 * ⁠ [1, 2, 3, 4],
 * ⁠ [5, 6, 7, 8],
 * ⁠ [9,10,11,12]
 * ]
 * 输出: [1,2,3,4,8,12,11,10,9,5,6,7]
 * 
 * 
 */
#include "useforme.h"
// @lc code=start
class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> ans;
        if(matrix.empty()){
            return ans;
        }
        int M = matrix.size();
        int N = matrix[0].size();
        int curM = 0;
        int curN = 0;
        vector<vector<int>>tags(matrix.size(), vector<int>(matrix[0].size(),0));
        for(int i = 0; i<matrix.size()*matrix[0].size();i++){
            // 右
            while(curN<N&&tags[curM][curN]==0){
                ans.push_back(matrix[curM][curN]);
                tags[curM][curN] = 1;
                curN++;
                // tags[curM][curN] = 1;
            }
            curN--;
            curM++;
            // 下
            while(curM<M&&tags[curM][curN]==0){
                ans.push_back(matrix[curM][curN]);
                tags[curM][curN] = 1;
                curM++;
                
            }
            curM--;
            curN--;
            // 左
            while(curN>=0&&tags[curM][curN]==0){
                tags[curM][curN] = 1;
                ans.push_back(matrix[curM][curN]);
                curN--;
            }
            curN++;
            curM--;
            // 上
            while(curM>=0&&tags[curM][curN]==0){
                tags[curM][curN] = 1;
                ans.push_back(matrix[curM][curN]);
                curM--;
            }
            curM++;
            curN++;
        }
        return ans;
    }
};
// @lc code=end

