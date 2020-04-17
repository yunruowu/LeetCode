/*
 * @lc app=leetcode.cn id=64 lang=cpp
 *
 * [64] 最小路径和
 *
 * https://leetcode-cn.com/problems/minimum-path-sum/description/
 *
 * algorithms
 * Medium (65.19%)
 * Likes:    440
 * Dislikes: 0
 * Total Accepted:    76.5K
 * Total Submissions: 117.1K
 * Testcase Example:  '[[1,3,1],[1,5,1],[4,2,1]]'
 *
 * 给定一个包含非负整数的 m x n 网格，请找出一条从左上角到右下角的路径，使得路径上的数字总和为最小。
 * 
 * 说明：每次只能向下或者向右移动一步。
 * 
 * 示例:
 * 
 * 输入:
 * [
 * [1,3,1],
 * ⁠ [1,5,1],
 * ⁠ [4,2,1]
 * ]
 * 输出: 7
 * 解释: 因为路径 1→3→1→1→1 的总和最小。
 * 
 * 
 */
#include "useforme.h"
// @lc code=start
class Solution {
public:
    int trace1(vector<vector<int>> grid, int cow, int line, int curSum){
        if(cow >= grid.size()-1&&line>=grid[0].size()-1){
            return curSum+grid[cow][line];
        }
        if(cow >= grid.size()-1){
            return trace1(grid, cow, line+1, curSum+grid[cow][line]);
        }
        if(line>=grid[0].size()-1){
            return trace1(grid, cow+1, line, curSum+grid[cow][line]);
        }
        return min(trace1(grid, cow+1, line, curSum+grid[cow][line]),
        trace1(grid, cow, line+1, curSum+grid[cow][line]));

    }
    int minPathSum(vector<vector<int>>& grid) {
        // cout<<1;
        // return trace1(grid, 0, 0, 0);
        for (int i = grid.size() - 1; i >= 0; i--) {
            for (int j = grid[0].size() - 1; j >= 0; j--) {
                if(i == grid.size() - 1 && j != grid[0].size() - 1)
                    grid[i][j] = grid[i][j] +  grid[i][j + 1];
                else if(j == grid[0].size() - 1 && i != grid.size() - 1)
                    grid[i][j] = grid[i][j] + grid[i + 1][j];
                else if(j != grid[0].size() - 1 && i != grid.size() - 1)
                    grid[i][j] = grid[i][j] + min(grid[i + 1][j],grid[i][j + 1]);
            }
        }
        return grid[0][0];
    }
};
// @lc code=end

