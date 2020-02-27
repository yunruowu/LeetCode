/*
 * @Description: 
 * @Version: 2.0
 * @Author: yunruowu
 * @Date: 2020-02-27 21:35:43
 * @LastEditors: yunruowu
 * @LastEditTime: 2020-02-27 21:50:06
 */
/*
 * @lc app=leetcode.cn id=628 lang=cpp
 *
 * [628] 三个数的最大乘积
 *
 * https://leetcode-cn.com/problems/maximum-product-of-three-numbers/description/
 *
 * algorithms
 * Easy (48.69%)
 * Likes:    112
 * Dislikes: 0
 * Total Accepted:    15K
 * Total Submissions: 30.6K
 * Testcase Example:  '[1,2,3]'
 *
 * 给定一个整型数组，在数组中找出由三个数组成的最大乘积，并输出这个乘积。
 * 
 * 示例 1:
 * 
 * 
 * 输入: [1,2,3]
 * 输出: 6
 * 
 * 
 * 示例 2:
 * 
 * 
 * 输入: [1,2,3,4]
 * 输出: 24
 * 
 * 
 * 注意:
 * 
 * 
 * 给定的整型数组长度范围是[3,10^4]，数组中所有的元素范围是[-1000, 1000]。
 * 输入的数组中任意三个数的乘积不会超出32位有符号整数的范围。
 * 
 * 
 */
#include "useforme.h"
// @lc code=start
class Solution {
public:
    int maximumProduct(vector<int>& nums) {
        int len = nums.size();
        sort(nums.begin(),nums.end());
        // if(nums[len-3]>0)
        return max(nums[len-1]*nums[len-2]*nums[len-3],nums[len-1]*nums[0]*nums[1]);
        // if(nums[len-2]>0)
        //     return nums[len-1]*nums[0]*nums[1];
        // if(nums[len-1]>0)
        //     return nums[len-1]*nums[0]*nums[1];
        // else
        //     return nums[len-1]*nums[len-2]*nums[len-3];
    }
};
// @lc code=end

