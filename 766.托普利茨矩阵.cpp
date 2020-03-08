/*
 * @Description: 
 * @Version: 2.0
 * @Author: yunruowu
 * @Date: 2020-03-07 16:24:14
 * @LastEditors: yunruowu
 * @LastEditTime: 2020-03-07 16:31:10
 */
/*
 * @lc app=leetcode.cn id=766 lang=cpp
 *
 * [766] 托普利茨矩阵
 *
 * https://leetcode-cn.com/problems/toeplitz-matrix/description/
 *
 * algorithms
 * Easy (63.11%)
 * Likes:    97
 * Dislikes: 0
 * Total Accepted:    10.9K
 * Total Submissions: 17.1K
 * Testcase Example:  '[[1,2,3,4],[5,1,2,3],[9,5,1,2]]'
 *
 * 如果一个矩阵的每一方向由左上到右下的对角线上具有相同元素，那么这个矩阵是托普利茨矩阵。
 * 
 * 给定一个 M x N 的矩阵，当且仅当它是托普利茨矩阵时返回 True。
 * 
 * 示例 1:
 * 
 * 输入: 
 * matrix = [
 * [1,2,3,4],
 * [5,1,2,3],
 * [9,5,1,2]
 * ]
 * 输出: True
 * 解释:
 * 在上述矩阵中, 其对角线为:
 * "[9]", "[5, 5]", "[1, 1, 1]", "[2, 2, 2]", "[3, 3]", "[4]"。
 * 各条对角线上的所有元素均相同, 因此答案是True。
 * 
 * 
 * 示例 2:
 * 
 * 输入:
 * matrix = [
 * [1,2],
 * [2,2]
 * ]
 * 输出: False
 * 解释: 
 * 对角线"[1, 2]"上的元素不同。
 * 
 * 
 * 说明:
 * 
 * 
 * matrix 是一个包含整数的二维数组。
 * matrix 的行数和列数均在 [1, 20]范围内。
 * matrix[i][j] 包含的整数在 [0, 99]范围内。
 * 
 * 
 * 进阶:
 * 
 * 
 * 如果矩阵存储在磁盘上，并且磁盘内存是有限的，因此一次最多只能将一行矩阵加载到内存中，该怎么办？
 * 如果矩阵太大以至于只能一次将部分行加载到内存中，该怎么办？
 * 
 * 
 */
#include "useforme.h"
// @lc code=start
class Solution {
public:
    bool isToeplitzMatrix(vector<vector<int>>& matrix) {
        int M = matrix.size();
        int N = matrix[0].size();
        
        for(int i = 0;i<N;i++){
            int val = matrix[0][i];
            int m = 1;
            int n = i+1;
            while(m<M&&n<N){
                if(matrix[m][n]!=val){
                    return false;
                }else{
                    m++;
                    n++;
                }
            }
        }
        for(int i = 1;i<M;i++){
            int val = matrix[i][0];
            int n = 1;
            int m = i+1;
            while(m<M&&n<N){
                if(matrix[m][n]!=val){
                    return false;
                }else{
                    m++;
                    n++;
                }
            }454
        }
        return true;
    }
};
// @lc code=end

