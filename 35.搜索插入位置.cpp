/*
 * @Description: 
 * @Version: 2.0
 * @Author: yunruowu
 * @Date: 2020-01-01 12:10:01
 * @LastEditors  : yunruowu
 * @LastEditTime : 2020-01-01 12:16:19
 */
/*
 * @lc app=leetcode.cn id=35 lang=cpp
 *
 * [35] 搜索插入位置
 *
 * https://leetcode-cn.com/problems/search-insert-position/description/
 *
 * algorithms
 * Easy (44.74%)
 * Likes:    393
 * Dislikes: 0
 * Total Accepted:    102.6K
 * Total Submissions: 229.2K
 * Testcase Example:  '[1,3,5,6]\n5'
 *
 * 给定一个排序数组和一个目标值，在数组中找到目标值，并返回其索引。如果目标值不存在于数组中，返回它将会被按顺序插入的位置。
 * 
 * 你可以假设数组中无重复元素。
 * 
 * 示例 1:
 * 
 * 输入: [1,3,5,6], 5
 * 输出: 2
 * 
 * 
 * 示例 2:
 * 
 * 输入: [1,3,5,6], 2
 * 输出: 1
 * 
 * 
 * 示例 3:
 * 
 * 输入: [1,3,5,6], 7
 * 输出: 4
 * 
 * 
 * 示例 4:
 * 
 * 输入: [1,3,5,6], 0
 * 输出: 0
 * 
 * 
 */
#include<string>
#include<iostream>
#include<vector>
using namespace std;


// @lc code=start
class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int n = nums.size();
        int i = 0;
        while(i<n){
            if(nums[i]<target){
                i++;
            }
            if(i<n&&nums[i]>target){
                return i;
            }
            if(i<n && nums[i]==target){
                return i;
            }
        }
        return n;
        // return 0;?
    }
};
// @lc code=end

