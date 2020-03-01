/*
 * @Description: 
 * @Version: 2.0
 * @Author: yunruowu
 * @Date: 2020-03-01 10:16:11
 * @LastEditors: yunruowu
 * @LastEditTime: 2020-03-01 10:23:52
 */
/*
 * @lc app=leetcode.cn id=674 lang=cpp
 *
 * [674] 最长连续递增序列
 *
 * https://leetcode-cn.com/problems/longest-continuous-increasing-subsequence/description/
 *
 * algorithms
 * Easy (43.61%)
 * Likes:    68
 * Dislikes: 0
 * Total Accepted:    17.6K
 * Total Submissions: 39.9K
 * Testcase Example:  '[1,3,5,4,7]'
 *
 * 给定一个未经排序的整数数组，找到最长且连续的的递增序列。
 * 
 * 示例 1:
 * 
 * 
 * 输入: [1,3,5,4,7]
 * 输出: 3
 * 解释: 最长连续递增序列是 [1,3,5], 长度为3。
 * 尽管 [1,3,5,7] 也是升序的子序列, 但它不是连续的，因为5和7在原数组里被4隔开。 
 * 
 * 
 * 示例 2:
 * 
 * 
 * 输入: [2,2,2,2,2]
 * 输出: 1
 * 解释: 最长连续递增序列是 [2], 长度为1。
 * 
 * 
 * 注意：数组长度不会超过10000。
 * 
 */
#include "useforme.h"
// @lc code=start
class Solution {
public:
    int findLengthOfLCIS(vector<int>& nums) {
        int len = 0;
        int i = 0;
        while(i<nums.size()){
            int j = i;
            int temp_len = 1;
            while(j+1<nums.size()&&nums[j]<nums[j+1]){
                temp_len++;
                j++;
            }
            len = max(temp_len,len);
            i = j+1;
            if(len+i>nums.size()){
                return len;
            }
        }
        return len;
    }
};
// @lc code=end

