/*
 * @lc app=leetcode.cn id=303 lang=cpp
 *
 * [303] 区域和检索 - 数组不可变
 *
 * https://leetcode-cn.com/problems/range-sum-query-immutable/description/
 *
 * algorithms
 * Easy (60.74%)
 * Likes:    163
 * Dislikes: 0
 * Total Accepted:    42.4K
 * Total Submissions: 68.6K
 * Testcase Example:  '["NumArray","sumRange","sumRange","sumRange"]\n[[[-2,0,3,-5,2,-1]],[0,2],[2,5],[0,5]]'
 *
 * 给定一个整数数组  nums，求出数组从索引 i 到 j  (i ≤ j) 范围内元素的总和，包含 i,  j 两点。
 * 
 * 示例：
 * 
 * 给定 nums = [-2, 0, 3, -5, 2, -1]，求和函数为 sumRange()
 * 
 * sumRange(0, 2) -> 1
 * sumRange(2, 5) -> -1
 * sumRange(0, 5) -> -3
 * 
 * 说明:
 * 
 * 
 * 你可以假设数组不可变。
 * 会多次调用 sumRange 方法。
 * 
 * 
 */
#include "useforme.h"
// @lc code=start
class NumArray {
public:
    vector<int> dp;
    NumArray(vector<int>& nums) {
        
        if(nums.size()!=0){
            vector<int> dp1(nums.size(), 0);
            dp1[0] = nums[0];
            for (int  i = 1; i < nums.size(); i++)
            {
                dp1[i] = dp1[i-1]+nums[i];
            }
            dp = dp1;
            // dp.assign(dp1.begin(),dp1.end());
        }
        
    }
    
    int sumRange(int i, int j) {
        if(i == 0)
            return dp[j];
        return dp[j]-dp[i-1];
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * int param_1 = obj->sumRange(i,j);
 */
// @lc code=end

