/*
 * @Description: 
 * @Version: 2.0
 * @Author: yunruowu
 * @Date: 2020-03-12 20:53:52
 * @LastEditors: yunruowu
 * @LastEditTime: 2020-03-12 21:24:36
 */
/*
 * @lc app=leetcode.cn id=867 lang=cpp
 *
 * [867] 转置矩阵
 *
 * https://leetcode-cn.com/problems/transpose-matrix/description/
 *
 * algorithms
 * Easy (66.78%)
 * Likes:    84
 * Dislikes: 0
 * Total Accepted:    16.8K
 * Total Submissions: 25K
 * Testcase Example:  '[[1,2,3],[4,5,6],[7,8,9]]'
 *
 * 给定一个矩阵 A， 返回 A 的转置矩阵。
 * 
 * 矩阵的转置是指将矩阵的主对角线翻转，交换矩阵的行索引与列索引。
 * 
 * 
 * 
 * 示例 1：
 * 
 * 输入：[[1,2,3],[4,5,6],[7,8,9]]
 * 输出：[[1,4,7],[2,5,8],[3,6,9]]
 * 
 * 
 * 示例 2：
 * 
 * 输入：[[1,2,3],[4,5,6]]
 * 输出：[[1,4],[2,5],[3,6]]
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 1 <= A.length <= 1000
 * 1 <= A[0].length <= 1000
 * 
 * 
 */
#include "useforme.h"
// @lc code=start
class Solution {
public:
    vector<vector<int>> transpose(vector<vector<int>>& A) {
        if (A.empty() || A[0].empty()) {
            return A;
        }
        int row = A.size();
        int column = A[0].size();
        vector<int> temp;
        vector<vector<int>> ans;
        for(int j = 0; j<column; j++){
            temp.clear();
            for(int i = 0; i<row; i++){
                temp.push_back(A[i][j]);
            }
            ans.push_back(temp);
        }

        return ans;
    }
};
// @lc code=end

