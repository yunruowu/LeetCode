/*
 * @lc app=leetcode.cn id=162 lang=cpp
 *
 * [162] 寻找峰值
 *
 * https://leetcode-cn.com/problems/find-peak-element/description/
 *
 * algorithms
 * Medium (45.45%)
 * Likes:    208
 * Dislikes: 0
 * Total Accepted:    43K
 * Total Submissions: 92.6K
 * Testcase Example:  '[1,2,3,1]'
 *
 * 峰值元素是指其值大于左右相邻值的元素。
 * 
 * 给定一个输入数组 nums，其中 nums[i] ≠ nums[i+1]，找到峰值元素并返回其索引。
 * 
 * 数组可能包含多个峰值，在这种情况下，返回任何一个峰值所在位置即可。
 * 
 * 你可以假设 nums[-1] = nums[n] = -∞。
 * 
 * 示例 1:
 * 
 * 输入: nums = [1,2,3,1]
 * 输出: 2
 * 解释: 3 是峰值元素，你的函数应该返回其索引 2。
 * 
 * 示例 2:
 * 
 * 输入: nums = [1,2,1,3,5,6,4]
 * 输出: 1 或 5 
 * 解释: 你的函数可以返回索引 1，其峰值元素为 2；
 * 或者返回索引 5， 其峰值元素为 6。
 * 
 * 
 * 说明:
 * 
 * 你的解法应该是 O(logN) 时间复杂度的。
 * 
 */
#include "useforme.h"
// @lc code=start
class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        
        int left =0, right = nums.size()-1;
        if(right==0){
            return 0;
        }
        if(right == 1){
            return (nums[0]>nums[1]) ? 0:1;
        }
        if(nums[0]>nums[1])
            return 0;
        if(nums[right]>nums[right-1])
            return right;
        int mid = (left+right)/2;
        int l_mid = (left + mid)/2;
        int r_mid = (right + mid)/2;
        // int left_val = INT_MIN;
        // int right_val = INT_MIN;
        // int  j = 0;
        while(left<right){
            // j++;
            if(right -left == 2){
                int maxv = -1;
                int pos;
                for(int i = 0; i<3; i++){
                    if(nums[i+left]>maxv){
                        maxv = nums[i+left];
                        pos = i+left;
                    }
                }
                return pos;
            }
            mid = (left+right)/2;
            l_mid = (left + mid)/2;
            r_mid = (right + mid)/2;
                // cout<<mid<<" "<<l_mid<<" "<<r_mid<<endl;
            if(nums[mid]<nums[l_mid]){//在左边
                right = mid;
                // left_val = nums[left];
                // right_val = nums[right];
                continue;
            }
            if(nums[mid]<nums[r_mid]){//在右边
                left = mid;
                // left_val = nums[left];
                // right_val = nums[right];
                continue;
            }
            else{//在中间
                left = l_mid;
                right = r_mid;
            }
            // left_val = nums[left];
            // right_val = nums[right];
        }
        return left;
    }
};
// @lc code=end

