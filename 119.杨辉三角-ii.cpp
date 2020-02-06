/*
 * @lc app=leetcode.cn id=119 lang=cpp
 *
 * [119] 杨辉三角 II
 *
 * https://leetcode-cn.com/problems/pascals-triangle-ii/description/
 *
 * algorithms
 * Easy (59.72%)
 * Likes:    112
 * Dislikes: 0
 * Total Accepted:    37.1K
 * Total Submissions: 62.1K
 * Testcase Example:  '3'
 *
 * 给定一个非负索引 k，其中 k ≤ 33，返回杨辉三角的第 k 行。
 * 
 * 
 * 
 * 在杨辉三角中，每个数是它左上方和右上方的数的和。
 * 
 * 示例:
 * 
 * 输入: 3
 * 输出: [1,3,3,1]
 * 
 * 
 * 进阶：
 * 
 * 你可以优化你的算法到 O(k) 空间复杂度吗？
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

    vector<int> getRow(int rowIndex) {
        vector<vector<int>> ans = generate(rowIndex+1);
        return ans[rowIndex];
    }
};
// @lc code=end

