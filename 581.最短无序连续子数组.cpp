/*
 * @Description: 
 * @Version: 2.0
 * @Author: yunruowu
 * @Date: 2020-02-23 09:40:44
 * @LastEditors: yunruowu
 * @LastEditTime: 2020-02-23 10:09:19
 */
/*
 * @lc app=leetcode.cn id=581 lang=cpp
 *
 * [581] 最短无序连续子数组
 *
 * https://leetcode-cn.com/problems/shortest-unsorted-continuous-subarray/description/
 *
 * algorithms
 * Easy (33.77%)
 * Likes:    233
 * Dislikes: 0
 * Total Accepted:    18.4K
 * Total Submissions: 54K
 * Testcase Example:  '[2,6,4,8,10,9,15]'
 *
 * 给定一个整数数组，你需要寻找一个连续的子数组，如果对这个子数组进行升序排序，那么整个数组都会变为升序排序。
 * 
 * 你找到的子数组应是最短的，请输出它的长度。
 * 
 * 示例 1:
 * 
 * 
 * 输入: [2, 6, 4, 8, 10, 9, 15]
 * 输出: 5
 * 解释: 你只需要对 [6, 4, 8, 10, 9] 进行升序排序，那么整个表都会变为升序排序。
 * 
 * 
 * 说明 :
 * 
 * 
 * 输入的数组长度范围在 [1, 10,000]。
 * 输入的数组可能包含重复元素 ，所以升序的意思是<=。
 * 
 * 
 */
#include "useforme.h"
// @lc code=start
class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        int l = 0;
        int r = nums.size()-1;
        int redge = 0;
        int ledge = nums.size()-1;
        while(l<nums.size()){
            while(nums[l]<=nums[r]&&r>l){//正常序列
                r--;
            }
            if(l < r){
                
                // cout<<l<<" "<<r<<endl;
                ledge = min(l,ledge);
                redge = max(r,redge);
            }
            l++;
            r = nums.size()-1;
        }
        if(redge - ledge<=0){
            return 0;
        }
        return redge - ledge+1;
    }
};
// @lc code=end

