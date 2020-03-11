/*
 * @Description: 
 * @Version: 2.0
 * @Author: yunruowu
 * @Date: 2020-03-11 11:47:56
 * @LastEditors: yunruowu
 * @LastEditTime: 2020-03-11 11:51:28
 */
/*
 * @lc app=leetcode.cn id=840 lang=cpp
 *
 * [840] 矩阵中的幻方
 *
 * https://leetcode-cn.com/problems/magic-squares-in-grid/description/
 *
 * algorithms
 * Easy (33.15%)
 * Likes:    28
 * Dislikes: 0
 * Total Accepted:    4.7K
 * Total Submissions: 14K
 * Testcase Example:  '[[4,3,8,4],[9,5,1,9],[2,7,6,2]]'
 *
 * 3 x 3 的幻方是一个填充有从 1 到 9 的不同数字的 3 x 3 矩阵，其中每行，每列以及两条对角线上的各数之和都相等。
 * 
 * 给定一个由整数组成的 grid，其中有多少个 3 × 3 的 “幻方” 子矩阵？（每个子矩阵都是连续的）。
 * 
 * 
 * 
 * 示例：
 * 
 * 输入: [[4,3,8,4],
 * ⁠     [9,5,1,9],
 * ⁠     [2,7,6,2]]
 * 输出: 1
 * 解释: 
 * 下面的子矩阵是一个 3 x 3 的幻方：
 * 438
 * 951
 * 276
 * 
 * 而这一个不是：
 * 384
 * 519
 * 762
 * 
 * 总的来说，在本示例所给定的矩阵中只有一个 3 x 3 的幻方子矩阵。
 * 
 * 
 * 提示:
 * 
 * 
 * 1 <= grid.length <= 10
 * 1 <= grid[0].length <= 10
 * 0 <= grid[i][j] <= 15
 * 
 * 
 */
#include "useforme.h"
// @lc code=start
class Solution {
public:
    int numMagicSquaresInside(vector<vector<int>>& grid) {
        int R = grid.size();
        int C = grid[0].size();
        int ans = 0;
        for (int r = 0; r < R-2; ++r)
            for (int c = 0; c < C-2; ++c) {
                if (grid[r+1][c+1] != 5) continue;  // optional skip
                if (magic(grid[r][c], grid[r][c+1], grid[r][c+2],
                          grid[r+1][c], grid[r+1][c+1], grid[r+1][c+2],
                          grid[r+2][c], grid[r+2][c+1], grid[r+2][c+2]))
                    ans++;
            }

        return ans;

作者：LeetCode
链接：https://leetcode-cn.com/problems/magic-squares-in-grid/solution/ju-zhen-zhong-de-huan-fang-by-leetcode-2/
来源：力扣（LeetCode）
著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。
    }
};
// @lc code=end

