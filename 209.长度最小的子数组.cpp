/*
 * @lc app=leetcode.cn id=209 lang=cpp
 *
 * [209] 长度最小的子数组
 *
 * https://leetcode-cn.com/problems/minimum-size-subarray-sum/description/
 *
 * algorithms
 * Medium (41.82%)
 * Likes:    281
 * Dislikes: 0
 * Total Accepted:    45.3K
 * Total Submissions: 106.4K
 * Testcase Example:  '7\n[2,3,1,2,4,3]'
 *
 * 给定一个含有 n 个正整数的数组和一个正整数 s ，找出该数组中满足其和 ≥ s
 * 的长度最小的连续子数组，并返回其长度。如果不存在符合条件的连续子数组，返回 0。
 * 
 * 示例: 
 * 
 * 输入: s = 7, nums = [2,3,1,2,4,3]
 * 输出: 2
 * 解释: 子数组 [4,3] 是该条件下的长度最小的连续子数组。
 * 
 * 
 * 进阶:
 * 
 * 如果你已经完成了O(n) 时间复杂度的解法, 请尝试 O(n log n) 时间复杂度的解法。
 * 
 */
#include "useforme.h"
// @lc code=start
class Solution {
public:
    // 双指针滑窗
    int minSubArrayLen(int s, vector<int>& nums) {
        int i = 0;
        int j = 0;
        
        int ans = INT_MAX;
        int len = 1;
        if(nums.size()==0){
            return 0;
        }
        int sum = nums[i];
        while(j<nums.size()){
            if(sum<s){
                j++;
                if(j<nums.size()){
                    sum+=nums[j];
                    len++;
                }
                // continue;
            }
            else{
                ans = min(ans, len);
                if(ans == 1){
                    return 1;
                }
                sum -= nums[i];
                i++;
                len--;
            }
        }
        return ans==INT_MAX?0:ans;
    }
    // int minSubArrayLen(int s, vector<int>& nums) {
        
    // }/
};
// @lc code=end

