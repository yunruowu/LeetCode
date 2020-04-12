/*
 * @lc app=leetcode.cn id=74 lang=cpp
 *
 * [74] 搜索二维矩阵
 *
 * https://leetcode-cn.com/problems/search-a-2d-matrix/description/
 *
 * algorithms
 * Medium (37.69%)
 * Likes:    163
 * Dislikes: 0
 * Total Accepted:    38.9K
 * Total Submissions: 103.2K
 * Testcase Example:  '[[1,3,5,7],[10,11,16,20],[23,30,34,50]]\n3'
 *
 * 编写一个高效的算法来判断 m x n 矩阵中，是否存在一个目标值。该矩阵具有如下特性：
 * 
 * 
 * 每行中的整数从左到右按升序排列。
 * 每行的第一个整数大于前一行的最后一个整数。
 * 
 * 
 * 示例 1:
 * 
 * 输入:
 * matrix = [
 * ⁠ [1,   3,  5,  7],
 * ⁠ [10, 11, 16, 20],
 * ⁠ [23, 30, 34, 50]
 * ]
 * target = 3
 * 输出: true
 * 
 * 
 * 示例 2:
 * 
 * 输入:
 * matrix = [
 * ⁠ [1,   3,  5,  7],
 * ⁠ [10, 11, 16, 20],
 * ⁠ [23, 30, 34, 50]
 * ]
 * target = 13
 * 输出: false
 * 
 */
#include "useforme.h"
// @lc code=start
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        if(matrix.empty()||matrix[0].empty())
            return false;
        int M = matrix.size()-1;
        int N = matrix[0].size()-1;
        int row = 0;
        int col = N;
        while(row<=M && col>=0){
            if(matrix[row][col]==target)
                return true;
            if(matrix[row][col]>target){
                col--;
            }
            else
                row++;
        }
        return false;
        //w 两次的二分法
        /* //eg 法一：
        int midRow ;
        int LRow = 0;
        int RRow = M;
        while(LRow<=RRow){
            midRow = (RRow+LRow)/2;
            // cout<<midRow<<endl;

            if(target<matrix[midRow][0]){
                RRow = midRow-1;
            }
            else if(target>matrix[midRow][N]){
                LRow = midRow+1;
            }else{
            // cout<<midRow<<endl;

                int l = 0;
                int r = N;
                int m; 
                // cout<<l<<r;
                while(l<=r){
                    // cout<<midRow<<m<<endl;
                    m=(l+r)/2;
                    if(target<matrix[midRow][m]){
                        r = m-1;
                    }
                    if(target>matrix[midRow][m]){
                        l = m+1;
                    }else{
                        if(target==matrix[midRow][m])
                            return true;
                    }
                }
                return false;
            }
        }
        return false;*/
    }
};
// @lc code=end

