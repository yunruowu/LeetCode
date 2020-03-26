/*
 * @lc app=leetcode.cn id=892 lang=cpp
 *
 * [892] 三维形体的表面积
 *
 * https://leetcode-cn.com/problems/surface-area-of-3d-shapes/description/
 *
 * algorithms
 * Easy (55.34%)
 * Likes:    51
 * Dislikes: 0
 * Total Accepted:    5.6K
 * Total Submissions: 10K
 * Testcase Example:  '[[2]]'
 *
 * 在 N * N 的网格上，我们放置一些 1 * 1 * 1  的立方体。
 * 
 * 每个值 v = grid[i][j] 表示 v 个正方体叠放在对应单元格 (i, j) 上。
 * 
 * 请你返回最终形体的表面积。
 * 
 * 
 * 
 * 
 * 
 * 
 * 示例 1：
 * 
 * 输入：[[2]]
 * 输出：10
 * 
 * 
 * 示例 2：
 * 
 * 输入：[[1,2],[3,4]]
 * 输出：34
 * 
 * 
 * 示例 3：
 * 
 * 输入：[[1,0],[0,2]]
 * 输出：16
 * 
 * 
 * 示例 4：
 * 
 * 输入：[[1,1,1],[1,0,1],[1,1,1]]
 * 输出：32
 * 
 * 
 * 示例 5：
 * 
 * 输入：[[2,2,2],[2,1,2],[2,2,2]]
 * 输出：46
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 1 <= N <= 50
 * 0 <= grid[i][j] <= 50
 * 
 * 
 */

// @lc code=start
class Solution {
public:
    int surfaceArea(vector<vector<int>>& grid) {
        int i, j, ans = 0;
        for (i = 0; i < grid.size(); i++) {
            for (j = 0; j < grid.size(); j++) {
                if (grid[i][j] > 0) {
                    ans += grid[i][j] * 4 + 2;    //累加每个方格内立方体的面积（6个面）
                    if (i > 0)
                        ans -= min(grid[i][j], grid[i - 1][j]) * 2; //再减去重复面积
                    if (j > 0)
                        ans -= min(grid[i][j], grid[i][j - 1]) * 2;
                }
            }
        }
    return ans;
    }
};
// @lc code=end

