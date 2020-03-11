/*
 * @Description: 
 * @Version: 2.0
 * @Author: yunruowu
 * @Date: 2020-03-11 10:09:38
 * @LastEditors: yunruowu
 * @LastEditTime: 2020-03-11 10:27:08
 */
/*
 * @lc app=leetcode.cn id=832 lang=cpp
 *
 * [832] 翻转图像
 *
 * https://leetcode-cn.com/problems/flipping-an-image/description/
 *
 * algorithms
 * Easy (73.99%)
 * Likes:    149
 * Dislikes: 0
 * Total Accepted:    28.5K
 * Total Submissions: 38.4K
 * Testcase Example:  '[[1,1,0],[1,0,1],[0,0,0]]'
 *
 * 给定一个二进制矩阵 A，我们想先水平翻转图像，然后反转图像并返回结果。
 * 
 * 水平翻转图片就是将图片的每一行都进行翻转，即逆序。例如，水平翻转 [1, 1, 0] 的结果是 [0, 1, 1]。
 * 
 * 反转图片的意思是图片中的 0 全部被 1 替换， 1 全部被 0 替换。例如，反转 [0, 1, 1] 的结果是 [1, 0, 0]。
 * 
 * 示例 1:
 * 
 * 
 * 输入: [[1,1,0],[1,0,1],[0,0,0]]
 * 输出: [[1,0,0],[0,1,0],[1,1,1]]
 * 解释: 首先翻转每一行: [[0,1,1],[1,0,1],[0,0,0]]；
 * ⁠    然后反转图片: [[1,0,0],[0,1,0],[1,1,1]]
 * 
 * 
 * 示例 2:
 * 
 * 
 * 输入: [[1,1,0,0],[1,0,0,1],[0,1,1,1],[1,0,1,0]]
 * 输出: [[1,1,0,0],[0,1,1,0],[0,0,0,1],[1,0,1,0]]
 * 解释: 首先翻转每一行: [[0,0,1,1],[1,0,0,1],[1,1,1,0],[0,1,0,1]]；
 * ⁠    然后反转图片: [[1,1,0,0],[0,1,1,0],[0,0,0,1],[1,0,1,0]]
 * 
 * 
 * 说明:
 * 
 * 
 * 1 <= A.length = A[0].length <= 20
 * 0 <= A[i][j] <= 1
 * 
 * 
 */
#include "useforme.h"
// @lc code=start
class Solution {
public:
    vector<vector<int>> flipAndInvertImage(vector<vector<int>>& A) {
        for(int i = 0;i<A.size();i++){
            // vector<int> A[i] = A[i];
            for(int j = 0; j<A[i].size()/2;j++){
                int temp = A[i][j];
                A[i][j] = A[i][A[i].size()-1-j];
                A[i][A[i].size()-1-j] = temp;
                // swap(A[i][j], A[i][A[i].size()-1-j]);
            }
            for(int j = 0; j<A[i].size();j++){
                A[i][j] =( A[i][j]+1)%2;
            }
        }
        return A;
    }
};
// @lc code=end

