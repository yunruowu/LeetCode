/*
 * @Description: 
 * @Version: 2.0
 * @Author: yunruowu
 * @Date: 2020-03-01 09:54:05
 * @LastEditors: yunruowu
 * @LastEditTime: 2020-03-01 10:14:54
 */
/*
 * @lc app=leetcode.cn id=665 lang=cpp
 *
 * [665] 非递减数列
 *
 * https://leetcode-cn.com/problems/non-decreasing-array/description/
 *
 * algorithms
 * Easy (21.36%)
 * Likes:    228
 * Dislikes: 0
 * Total Accepted:    14.3K
 * Total Submissions: 65.3K
 * Testcase Example:  '[4,2,3]'
 *
 * 给定一个长度为 n 的整数数组，你的任务是判断在最多改变 1 个元素的情况下，该数组能否变成一个非递减数列。
 * 
 * 我们是这样定义一个非递减数列的： 对于数组中所有的 i (1 <= i < n)，满足 array[i] <= array[i + 1]。
 * 
 * 示例 1:
 * 
 * 
 * 输入: [4,2,3]
 * 输出: True
 * 解释: 你可以通过把第一个4变成1来使得它成为一个非递减数列。
 * 
 * 
 * 示例 2:
 * 
 * 
 * 输入: [4,2,1]
 * 输出: False
 * 解释: 你不能在只改变一个元素的情况下将其变为非递减数列。
 * 
 * 
 * 说明:  n 的范围为 [1, 10,000]。
 * 
 */
#include "useforme.h"
// @lc code=start
class Solution {
public:
    bool isOrder(vector<int> nums){
        for(int i = 0;i<nums.size()-1;i++){
            if(nums[i]<=nums[i+1]){
                continue;
            }else{
                return false;
            }
        }
        return true;
    }
    bool checkPossibility(vector<int>& nums) {
        int min_val = 9999;
        int max_val = -1;
        for(int i = 0; i<nums.size()-1;i++){
            if(nums[i]>nums[i+1]){
                int temp = nums[i];
                nums[i]=nums[i+1];
                if(isOrder(nums)){
                    return true;
                }
                nums[i]=temp;
                nums[i+1]=nums[i];
                if(isOrder(nums)){
                    return true;
                }return false;

            }
        }
        return true;
    }
};
// @lc code=end

