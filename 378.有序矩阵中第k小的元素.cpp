/*
 * @lc app=leetcode.cn id=378 lang=cpp
 *
 * [378] 有序矩阵中第K小的元素
 *
 * https://leetcode-cn.com/problems/kth-smallest-element-in-a-sorted-matrix/description/
 *
 * algorithms
 * Medium (58.63%)
 * Likes:    395
 * Dislikes: 0
 * Total Accepted:    49.7K
 * Total Submissions: 79.4K
 * Testcase Example:  '[[1,5,9],[10,11,13],[12,13,15]]\n8'
 *
 * 给定一个 n x n 矩阵，其中每行和每列元素均按升序排序，找到矩阵中第 k 小的元素。
 * 请注意，它是排序后的第 k 小元素，而不是第 k 个不同的元素。
 * 
 * 
 * 
 * 示例：
 * 
 * matrix = [
 * ⁠  [ 1,  5,  9],
 * ⁠  [10, 11, 13],
 * ⁠  [12, 13, 15]
 * ],
 * k = 8,
 * 
 * 返回 13。
 * 
 * 
 * 
 * 
 * 提示：
 * 你可以假设 k 的值永远是有效的，1 ≤ k ≤ n^2 。
 * 
 */
#include <iostream>
#include "useforme.h"   
// @lc code=start
struct pos
{
    int x;
    int y;
};

class Solution {
public:

    int kthSmallest(vector<vector<int>>& matrix, int k) {
        int i = 1;

        pos start;
        start.x = 0;
        start.y = 0;

        pos min1, min2;
        min1.x = start.x + 1;
        min1.y = start.y;
        min2.y = start.y + 1;
        min2.x = start.x;

        pos now;
        if(matrix[min1.x][min2.y]<matrix[min2.x][min2.y])
        {
            now = min1;
        }else{
            now = min2;
        }
        

        int len = matrix[0].size();
        int row = matrix.size();
        while(i<k){
            
            i++;
        }
    }
};
// @lc code=end

