/*
 * @lc app=leetcode.cn id=213 lang=cpp
 *
 * [213] 打家劫舍 II
 *
 * https://leetcode-cn.com/problems/house-robber-ii/description/
 *
 * algorithms
 * Medium (37.06%)
 * Likes:    292
 * Dislikes: 0
 * Total Accepted:    38.8K
 * Total Submissions: 101.4K
 * Testcase Example:  '[2,3,2]'
 *
 * 
 * 你是一个专业的小偷，计划偷窃沿街的房屋，每间房内都藏有一定的现金。这个地方所有的房屋都围成一圈，这意味着第一个房屋和最后一个房屋是紧挨着的。同时，相邻的房屋装有相互连通的防盗系统，如果两间相邻的房屋在同一晚上被小偷闯入，系统会自动报警。
 * 
 * 给定一个代表每个房屋存放金额的非负整数数组，计算你在不触动警报装置的情况下，能够偷窃到的最高金额。
 * 
 * 示例 1:
 * 
 * 输入: [2,3,2]
 * 输出: 3
 * 解释: 你不能先偷窃 1 号房屋（金额 = 2），然后偷窃 3 号房屋（金额 = 2）, 因为他们是相邻的。
 * 
 * 
 * 示例 2:
 * 
 * 输入: [1,2,3,1]
 * 输出: 4
 * 解释: 你可以先偷窃 1 号房屋（金额 = 1），然后偷窃 3 号房屋（金额 = 3）。
 * 偷窃到的最高金额 = 1 + 3 = 4 。
 * 
 */
#include "useforme.h"
// @lc code=start
class Solution {
public:
    int rob(vector<int>& nums) {
        if(nums.size()==0){
            return 0;
        }
        int ans = -1;
        if(nums.size()==1){
            return nums[0];
        }
        if(nums.size()==2){
            return max(nums[0], nums[1]);
        }
        nums[2]= nums[2]+nums[0];
        if(nums.size()%2==0){
            for(int i = 3; i<nums.size();i++){
                nums[i]=nums[i]+max(nums[i-2], nums[i-3]);
            }
            ans = max(nums[nums.size()-1], nums[nums.size()-2]);
        }else{
            // nums[0] = max(nums[0], nums[nums.size()-1]);
            for(int i = 3; i<nums.size()-1;i++){
                nums[i]=nums[i]+max(nums[i-2], nums[i-3]);
            }
            ans = max(nums[nums.size()-2],nums[nums.size()-3]);
        }
        return ans;

    }
};
// @lc code=end

