/*
 * @Description: 
 * @Version: 2.0
 * @Author: yunruowu
 * @Date: 2020-02-22 22:31:16
 * @LastEditors: yunruowu
 * @LastEditTime: 2020-02-22 22:50:53
 */
/*
 * @lc app=leetcode.cn id=566 lang=cpp
 *
 * [566] 重塑矩阵
 *
 * https://leetcode-cn.com/problems/reshape-the-matrix/description/
 *
 * algorithms
 * Easy (63.41%)
 * Likes:    98
 * Dislikes: 0
 * Total Accepted:    13.3K
 * Total Submissions: 20.8K
 * Testcase Example:  '[[1,2],[3,4]]\n1\n4'
 *
 * 在MATLAB中，有一个非常有用的函数 reshape，它可以将一个矩阵重塑为另一个大小不同的新矩阵，但保留其原始数据。
 * 
 * 给出一个由二维数组表示的矩阵，以及两个正整数r和c，分别表示想要的重构的矩阵的行数和列数。
 * 
 * 重构后的矩阵需要将原始矩阵的所有元素以相同的行遍历顺序填充。
 * 
 * 如果具有给定参数的reshape操作是可行且合理的，则输出新的重塑矩阵；否则，输出原始矩阵。
 * 
 * 示例 1:
 * 
 * 
 * 输入: 
 * nums = 
 * [[1,2],
 * ⁠[3,4]]
 * r = 1, c = 4
 * 输出: 
 * [[1,2,3,4]]
 * 解释:
 * 行遍历nums的结果是 [1,2,3,4]。新的矩阵是 1 * 4 矩阵, 用之前的元素值一行一行填充新矩阵。
 * 
 * 
 * 示例 2:
 * 
 * 
 * 输入: 
 * nums = 
 * [[1,2],
 * ⁠[3,4]]
 * r = 2, c = 4
 * 输出: 
 * [[1,2],
 * ⁠[3,4]]
 * 解释:
 * 没有办法将 2 * 2 矩阵转化为 2 * 4 矩阵。 所以输出原矩阵。
 * 
 * 
 * 注意：
 * 
 * 
 * 给定矩阵的宽和高范围在 [1, 100]。
 * 给定的 r 和 c 都是正数。
 * 
 * 
 */
#include "useforme.h"
// @lc code=start
class Solution {
public:
    vector<vector<int>> matrixReshape(vector<vector<int>>& nums, int r, int c) {
        int h = nums.size();
        int l = nums[0].size();
        vector<vector<int>> ans(r, vector<int>(c));
        if(h * l != r * c)
            return nums;
        vector<int> temp;
        for(int i = 0; i<h;i++){
            for(int j = 0;j<l;j++){
                int pos = i*l+j;
                int newRow = pos/c;
                int newLine = pos%c;
                ans[newRow][newLine] = nums[i][j];
                // temp.push_back(nums[i][j]);
                // if (newLine == c-1)
                // {
                //     ans.push_back(temp);
                //     temp.clear();
                // }
                
            }
        }
        return ans;
    }
};
// @lc code=end

