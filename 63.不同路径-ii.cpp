/*
 * @lc app=leetcode.cn id=63 lang=cpp
 *
 * [63] 不同路径 II
 *
 * https://leetcode-cn.com/problems/unique-paths-ii/description/
 *
 * algorithms
 * Medium (32.63%)
 * Likes:    299
 * Dislikes: 0
 * Total Accepted:    62.7K
 * Total Submissions: 187.7K
 * Testcase Example:  '[[0,0,0],[0,1,0],[0,0,0]]'
 *
 * 一个机器人位于一个 m x n 网格的左上角 （起始点在下图中标记为“Start” ）。
 * 
 * 机器人每次只能向下或者向右移动一步。机器人试图达到网格的右下角（在下图中标记为“Finish”）。
 * 
 * 现在考虑网格中有障碍物。那么从左上角到右下角将会有多少条不同的路径？
 * 
 * 
 * 
 * 网格中的障碍物和空位置分别用 1 和 0 来表示。
 * 
 * 说明：m 和 n 的值均不超过 100。
 * 
 * 示例 1:
 * 
 * 输入:
 * [
 * [0,0,0],
 * [0,1,0],
 * [0,0,0]
 * ]
 * 输出: 2
 * 解释:
 * 3x3 网格的正中间有一个障碍物。
 * 从左上角到右下角一共有 2 条不同的路径：
 * 1. 向右 -> 向右 -> 向下 -> 向下
 * 2. 向下 -> 向下 -> 向右 -> 向右
 * 
 * 
 */




#include "useforme.h"
// @lc code=start
class Solution {
public:
    int fun3(int m, int n, vector<vector<int>> ob){
        vector<vector<long> >mem(m,vector<long>(n,0));
        if(ob[m-1][n-1]==1){
            return 0;
        }
        for(int i = m-1;i>=0;i--){
            for(int j = n-1;j>=0;j--){
                // cout<<i<<" "<<j<<endl;
                if(ob[i][j]==1){
                    mem[i][j] = 0;
                }else
                {
                    if(j==n-1&&i==m-1){
                        mem[i][j]=1;
                    }else{
                        if(j == n-1){
                            mem[i][j] = mem[i+1][j];
                        }
                        else 
                        {
                            if(i==m-1){
                                mem[i][j]=mem[i][j+1];
                            }
                            else{
                                mem[i][j]=mem[i][j+1]+mem[i+1][j];
                            }
                        }
                    } 
                }
            }
        }
        return mem[0][0];
    }
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int n = obstacleGrid[0].size();
        int m =obstacleGrid.size();
        return fun3(m, n, obstacleGrid);
    }
};
// @lc code=end

