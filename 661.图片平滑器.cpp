/*
 * @Description: 
 * @Version: 2.0
 * @Author: yunruowu
 * @Date: 2020-02-29 13:58:34
 * @LastEditors: yunruowu
 * @LastEditTime: 2020-02-29 14:43:36
 */
/*
 * @lc app=leetcode.cn id=661 lang=cpp
 *
 * [661] 图片平滑器
 *
 * https://leetcode-cn.com/problems/image-smoother/description/
 *
 * algorithms
 * Easy (52.00%)
 * Likes:    41
 * Dislikes: 0
 * Total Accepted:    6.3K
 * Total Submissions: 12K
 * Testcase Example:  '[[1,1,1],[1,0,1],[1,1,1]]'
 *
 * 包含整数的二维矩阵 M 表示一个图片的灰度。你需要设计一个平滑器来让每一个单元的灰度成为平均灰度 (向下舍入)
 * ，平均灰度的计算是周围的8个单元和它本身的值求平均，如果周围的单元格不足八个，则尽可能多的利用它们。
 * 
 * 示例 1:
 * 
 * 
 * 输入:
 * [[1,1,1],
 * ⁠[1,0,1],
 * ⁠[1,1,1]]
 * 输出:
 * [[0, 0, 0],
 * ⁠[0, 0, 0],
 * ⁠[0, 0, 0]]
 * 解释:
 * 对于点 (0,0), (0,2), (2,0), (2,2): 平均(3/4) = 平均(0.75) = 0
 * 对于点 (0,1), (1,0), (1,2), (2,1): 平均(5/6) = 平均(0.83333333) = 0
 * 对于点 (1,1): 平均(8/9) = 平均(0.88888889) = 0
 * 
 * 
 * 注意:
 * 
 * 
 * 给定矩阵中的整数范围为 [0, 255]。
 * 矩阵的长和宽的范围均为 [1, 150]。
 * 
 * 
 */
#include "useforme.h"
// @lc code=start
class Solution {
public:
    vector<vector<int>> imageSmoother(vector<vector<int>>& M) {
        int line = M.size();
        int row = M[0].size();
        vector<vector<int>> ans;
        if (line == 1&&row == 1){
            vector<int> temp;
            temp.push_back(M[0][0]);
            ans.push_back(temp);
            return ans;
        }
        if (line == 1){
            vector<int> temp;
            temp.push_back((M[0][0]+M[0][1])/2);
            for(int i = 1;i<row-1;i++){
                temp.push_back((M[0][i-1]+M[0][i]+M[0][i+1])/3);
            }
            temp.push_back((M[0][row-2]+M[0][row-1])/2);
            ans.push_back(temp);
            return ans;
        }
        if (row == 1){
            vector<int> temp;
            temp.push_back((M[0][0]+M[1][0])/2);
            ans.push_back(temp);
            temp.pop_back();
            for(int i = 1;i<line-1;i++){
                temp.push_back((M[i-1][0]+M[i][0]+M[i+1][0])/3);
                ans.push_back(temp);
                temp.pop_back();
            }
            temp.push_back((M[line-2][0]+M[line-1][0])/2);
            ans.push_back(temp);
            return ans;
        }
        for(int i = 0;i<line;i++){
            vector<int>temp;
            for(int j = 0; j<row; j++){
                if(i==0&&j==0){
                    temp.push_back((M[0][0]+M[0][1]+M[1][1]+M[1][0])/4);
                    continue;
                }
                else if(i==0&&j==row-1){
                    temp.push_back((M[0][row-2]+M[0][row-1]+M[1][row-2]+M[1][row-1])/4);
                    continue;
                }
                else if(i==line-1&&j==0){
                    temp.push_back((M[line-1][0]+M[line-1][1]+M[line-2][0]+M[line-2][1])/4);
                    continue;
                }
                else if(i==line-1&&j==row-1){
                    temp.push_back((M[line-2][row-2]+M[line-2][row-1]+M[line-1][row-2]+M[line-1][row-1])/4);
                    continue;
                }else{
                    if(i==0){
                        temp.push_back((M[0][j-1]+M[0][j]+M[0][j+1]+M[1][j-1]+M[1][j]+M[1][j+1])/6);
                        continue;
                    }
                    if(i==line-1){
                        temp.push_back((M[line-1][j-1]+M[line-1][j]+M[line-1][j+1]+M[line-2][j-1]+M[line-2][j]+M[line-2][j+1])/6);
                        continue;
                    }
                    if(j==0){
                        temp.push_back((M[i-1][0]+M[i][0]+M[i+1][0]+M[i-1][1]+M[i][1]+M[i+1][1])/6);
                        continue;
                    }
                    if(j==row-1){
                        temp.push_back((M[i-1][row-1]+M[i][row-1]+M[i+1][row-1]+M[i-1][row-2]+M[i][row-2]+M[i+1][row-2])/6);
                        continue;
                    }else{
                        int t = M[i][j-1]+M[i][j]+M[i][j+1]+M[i-1][j-1]+M[i-1][j]+M[i-1][j+1]+M[i+1][j-1]+M[i+1][j]+M[i+1][j+1];
                        temp.push_back(t/9);
                        continue;
                    }
                }
            }
            ans.push_back(temp);
        }
        return ans;
    }
};
// @lc code=end

