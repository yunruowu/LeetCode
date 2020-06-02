/*
 * @lc app=leetcode.cn id=200 lang=cpp
 *
 * [200] 岛屿数量
 *
 * https://leetcode-cn.com/problems/number-of-islands/description/
 *
 * algorithms
 * Medium (47.85%)
 * Likes:    479
 * Dislikes: 0
 * Total Accepted:    80.8K
 * Total Submissions: 167.6K
 * Testcase Example:  '[["1","1","1","1","0"],["1","1","0","1","0"],["1","1","0","0","0"],["0","0","0","0","0"]]'
 *
 * 给你一个由 '1'（陆地）和 '0'（水）组成的的二维网格，请你计算网格中岛屿的数量。
 * 
 * 岛屿总是被水包围，并且每座岛屿只能由水平方向和/或竖直方向上相邻的陆地连接形成。
 * 
 * 此外，你可以假设该网格的四条边均被水包围。
 * 
 * 示例 1:
 * 
 * 输入:
 * 11110
 * 11010
 * 11000
 * 00000
 * 输出: 1
 * 
 * 
 * 示例 2:
 * 
 * 输入:
 * 11000
 * 11000
 * 00100
 * 00011
 * 输出: 3
 * 解释: 每座岛屿只能由水平和/或竖直方向上相邻的陆地连接而成。
 * 
 * 
 */
#include "useforme.h"
// @lc code=start
class Solution {
public:
    struct DSU{
        vector<int> data;

        void makeSet(int n){
            data.resize(n);
            for (int i = 0; i < n; i++) data[i] = i;
        };

        bool unionSet(int i, int j){
            int p1 = parent(i);
            int p2 = parent(j);
            if ( p1 != p2 ){
                data[p1] = p2;
            } 
            return p1 != p2;

        };

        int parent(int i){
            int root = i;
            while ( data[root] != root){
                root = data[root];
            }
            return root;

        };
    };

    int numIslands(vector<vector<char>>& grid) {
        if (grid.size() == 0 ) 
            return  0;

        int m = grid.size();
        int n = grid[0].size();
        int ans = 0;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++){
                if (grid[i][j] == '1') ans++;
            }
        }
        DSU dsu;
        dsu.makeSet( m * n);
        for (int i = 0 ; i < m ; i++){
            for ( int j = 0; j < n ; j++){
                if ( i > 0 && grid[i][j] == '1' && grid[i-1][j] == '1'){
                    ans -= dsu.unionSet(i*n +j, (i-1)*n+j);
                }
                if ( j > 0 && grid[i][j] == '1' && grid[i][j-1] == '1'){
                    ans -= dsu.unionSet(i*n +j, i*n+j-1);
                }
            }
        }
        return ans;
    }
};
// @lc code=end

