/*
 * @Description: 
 * @Version: 2.0
 * @Author: yunruowu
 * @Date: 2020-02-08 11:33:25
 * @LastEditors  : yunruowu
 * @LastEditTime : 2020-02-08 11:37:27
 */
/*
 * @lc app=leetcode.cn id=217 lang=cpp
 *
 * [217] 存在重复元素
 *
 * https://leetcode-cn.com/problems/contains-duplicate/description/
 *
 * algorithms
 * Easy (51.42%)
 * Likes:    212
 * Dislikes: 0
 * Total Accepted:    106.5K
 * Total Submissions: 207.1K
 * Testcase Example:  '[1,2,3,1]'
 *
 * 给定一个整数数组，判断是否存在重复元素。
 * 
 * 如果任何值在数组中出现至少两次，函数返回 true。如果数组中每个元素都不相同，则返回 false。
 * 
 * 示例 1:
 * 
 * 输入: [1,2,3,1]
 * 输出: true
 * 
 * 示例 2:
 * 
 * 输入: [1,2,3,4]
 * 输出: false
 * 
 * 示例 3:
 * 
 * 输入: [1,1,1,3,3,4,3,2,4,2]
 * 输出: true
 * 
 */
#include "useforme.h"
// @lc code=start
class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        if(nums.empty()==true){
            return false;
        }
        sort(nums.begin(),nums.end());
        for (int i = 0; i < nums.size() - 1; ++i) {
            if (nums[i] == nums[i + 1]) 
                return true;
        }
        return false;
    }
};
// @lc code=end

