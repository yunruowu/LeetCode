/*
 * @Description: 
 * @Version: 2.0
 * @Author: yunruowu
 * @Date: 2020-02-26 23:05:55
 * @LastEditors: yunruowu
 * @LastEditTime: 2020-02-26 23:29:04
 */
/*
 * @lc app=leetcode.cn id=594 lang=cpp
 *
 * [594] 最长和谐子序列
 *
 * https://leetcode-cn.com/problems/longest-harmonious-subsequence/description/
 *
 * algorithms
 * Easy (44.83%)
 * Likes:    75
 * Dislikes: 0
 * Total Accepted:    8K
 * Total Submissions: 17.7K
 * Testcase Example:  '[1,3,2,2,5,2,3,7]'
 *
 * 和谐数组是指一个数组里元素的最大值和最小值之间的差别正好是1。
 * 
 * 现在，给定一个整数数组，你需要在所有可能的子序列中找到最长的和谐子序列的长度。
 * 
 * 示例 1:
 * 
 * 
 * 输入: [1,3,2,2,5,2,3,7]
 * 输出: 5
 * 原因: 最长的和谐数组是：[3,2,2,2,3].
 * 
 * 
 * 说明: 输入的数组长度最大不超过20,000.
 * 
 */
#include <useforme.h>
// @lc code=start
class Solution {
public:
    int findLHS(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        // cout<<nums[1];
        int i = 0;
        int ans = 0;
        while(i<nums.size()){
            int j = i+1;
            int len = 1;
            int equallen = 0;
            while((j<nums.size())){
                // cout<<nums[j];
                if(nums[j]-nums[i]==0)
                {
                    equallen++;
                }
                if(nums[j]-nums[i]==1)
                {
                    ans = max(ans,j-i+1);
                    
                }
                if(nums[j]-nums[i]>1)
                {
                    break;
                    
                }
                j++;
            }
            if(i + ans>nums.size()){
                        return ans;
                    }
            i+=equallen+1;
        }
        return ans;
    }
};
// @lc code=end

