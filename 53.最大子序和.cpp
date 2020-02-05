/*
 * @Description: 
 * @Version: 2.0
 * @Author: yunruowu
 * @Date: 2020-02-04 17:06:14
 * @LastEditors  : yunruowu
 * @LastEditTime : 2020-02-04 17:22:10
 */
/*
 * @lc app=leetcode.cn id=53 lang=cpp
 *
 * [53] 最大子序和
 *
 * https://leetcode-cn.com/problems/maximum-subarray/description/
 *
 * algorithms
 * Easy (48.88%)
 * Likes:    1565
 * Dislikes: 0
 * Total Accepted:    151.7K
 * Total Submissions: 310.3K
 * Testcase Example:  '[-2,1,-3,4,-1,2,1,-5,4]'
 *
 * 给定一个整数数组 nums ，找到一个具有最大和的连续子数组（子数组最少包含一个元素），返回其最大和。
 * 
 * 示例:
 * 
 * 输入: [-2,1,-3,4,-1,2,1,-5,4],
 * 输出: 6
 * 解释: 连续子数组 [4,-1,2,1] 的和最大，为 6。
 * 
 * 
 * 进阶:
 * 
 * 如果你已经实现复杂度为 O(n) 的解法，尝试使用更为精妙的分治法求解。
 * 
 */
#include "useforme.h"
// @lc code=start
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        vector<int> temp;
        if(nums.empty()==true){
            return NULL;
        }
        if(nums.size()==1){
            return nums[0];
        }
        int maxsum = nums[0];
        temp.push_back(maxsum);
        for(int i = 1; i<nums.size(); i++){
            temp.push_back( max( (temp[i-1]+nums[i]) , nums[i] ) );
            maxsum = max(max( (temp[i-1]+nums[i]) , nums[i] ),maxsum);
        }
        return maxsum;
    }
};
// @lc code=end

