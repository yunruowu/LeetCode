/*
 * @Description: 
 * @Version: 2.0
 * @Author: yunruowu
 * @Date: 2020-02-05 11:03:44
 * @LastEditors  : yunruowu
 * @LastEditTime : 2020-02-05 11:20:26
 */
/*
 * @lc app=leetcode.cn id=118 lang=cpp
 *
 * [118] 杨辉三角
 *
 * https://leetcode-cn.com/problems/pascals-triangle/description/
 *
 * algorithms
 * Easy (65.47%)
 * Likes:    236
 * Dislikes: 0
 * Total Accepted:    56.4K
 * Total Submissions: 86.2K
 * Testcase Example:  '5'
 *
 * 给定一个非负整数 numRows，生成杨辉三角的前 numRows 行。
 * 
 * 
 * 
 * 在杨辉三角中，每个数是它左上方和右上方的数的和。
 * 
 * 示例:
 * 
 * 输入: 5
 * 输出:
 * [
 * ⁠    [1],
 * ⁠   [1,1],
 * ⁠  [1,2,1],
 * ⁠ [1,3,3,1],
 * ⁠[1,4,6,4,1]
 * ]
 * 
 */
#include "useforme.h"
// @lc code=start
class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> ans;
        vector<int> temp ;
        temp.push_back(1);
        
        if(numRows==0){
            return ans;
        }
        ans.push_back(temp);        
        for(int row = 1; row < numRows;row++){
            vector<int> inner;
            inner.push_back(1);
            vector<int> Previous = ans[row-1];
            int len = Previous.size();
            for(int j = 0; j < len-1; j++){
                inner.push_back(Previous[j]+Previous[j+1]);
            }
            inner.push_back(1);
            ans.push_back(inner);
        }
        return ans;
    }
};
// @lc code=end

