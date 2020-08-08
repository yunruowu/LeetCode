/*
 * @lc app=leetcode.cn id=152 lang=cpp
 *
 * [152] 乘积最大子数组
 *
 * https://leetcode-cn.com/problems/maximum-product-subarray/description/
 *
 * algorithms
 * Medium (37.69%)
 * Likes:    622
 * Dislikes: 0
 * Total Accepted:    74.7K
 * Total Submissions: 188.3K
 * Testcase Example:  '[2,3,-2,4]'
 *
 * 给你一个整数数组 nums ，请你找出数组中乘积最大的连续子数组（该子数组中至少包含一个数字），并返回该子数组所对应的乘积。
 * 
 * 
 * 
 * 示例 1:
 * 
 * 输入: [2,3,-2,4]
 * 输出: 6
 * 解释: 子数组 [2,3] 有最大乘积 6。
 * 
 * 
 * 示例 2:
 * 
 * 输入: [-2,0,-1]
 * 输出: 0
 * 解释: 结果不能为 2, 因为 [-2,-1] 不是子数组。
 * 
 */
#include "useforme.h"
// @lc code=start
class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int ans = nums[0];
        // int n = nums.size();
        // vector<int> dp=nums;
        int maxval = ans;
        int minval = ans;
        int a,b;
        for(int i = 1; i<nums.size();i++){
            a = nums[i]*maxval;
            b = nums[i]*minval;
            // cout<<a<<" "<<b<<endl;
            maxval = max(nums[i], max(a, b));
            minval = min(nums[i], min(a, b));
            ans = max(ans, maxval);
        }


        
        return ans;
    }
};
// @lc code=end

