/*
 * @lc app=leetcode.cn id=120 lang=cpp
 *
 * [120] 三角形最小路径和
 *
 * https://leetcode-cn.com/problems/triangle/description/
 *
 * algorithms
 * Medium (64.16%)
 * Likes:    425
 * Dislikes: 0
 * Total Accepted:    62.4K
 * Total Submissions: 96.2K
 * Testcase Example:  '[[2],[3,4],[6,5,7],[4,1,8,3]]'
 *
 * 给定一个三角形，找出自顶向下的最小路径和。每一步只能移动到下一行中相邻的结点上。
 * 
 * 相邻的结点 在这里指的是 下标 与 上一层结点下标 相同或者等于 上一层结点下标 + 1 的两个结点。
 * 
 * 
 * 
 * 例如，给定三角形：
 * 
 * [
 * ⁠    [2],
 * ⁠   [3,4],
 * ⁠  [6,5,7],
 * ⁠ [4,1,8,3]
 * ]
 * 
 * 
 * 自顶向下的最小路径和为 11（即，2 + 3 + 5 + 1 = 11）。
 * 
 * 
 * 
 * 说明：
 * 
 * 如果你可以只使用 O(n) 的额外空间（n 为三角形的总行数）来解决这个问题，那么你的算法会很加分。
 * 
 */
#include "useforme.h"
// @lc code=start
class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        // int len = triangle.size();
        // if(len == 1){
        //     return triangle[0][0];
        // }

        int i = triangle.size()-2;
        for(;i>=0;i--){
            for(int j = 0; j<i+1; ++j){
                triangle[i][j] += min(triangle[i+1][j],triangle[i+1][j+1]);
            }
            // i--;
        }
        return triangle[0][0];
    }
};
// @lc code=end

