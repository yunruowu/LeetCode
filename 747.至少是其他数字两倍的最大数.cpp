/*
 * @Description: 
 * @Version: 2.0
 * @Author: yunruowu
 * @Date: 2020-02-19 16:44:33
 * @LastEditors: yunruowu
 * @LastEditTime: 2020-02-19 16:50:12
 */
/*
 * @lc app=leetcode.cn id=747 lang=cpp
 *
 * [747] 至少是其他数字两倍的最大数
 *
 * https://leetcode-cn.com/problems/largest-number-at-least-twice-of-others/description/
 *
 * algorithms
 * Easy (38.88%)
 * Likes:    51
 * Dislikes: 0
 * Total Accepted:    22.6K
 * Total Submissions: 57.8K
 * Testcase Example:  '[0,0,0,1]'
 *
 * 在一个给定的数组nums中，总是存在一个最大元素 。
 * 
 * 查找数组中的最大元素是否至少是数组中每个其他数字的两倍。
 * 
 * 如果是，则返回最大元素的索引，否则返回-1。
 * 
 * 示例 1:
 * 
 * 输入: nums = [3, 6, 1, 0]
 * 输出: 1
 * 解释: 6是最大的整数, 对于数组中的其他整数,
 * 6大于数组中其他元素的两倍。6的索引是1, 所以我们返回1.
 * 
 * 
 * 
 * 
 * 示例 2:
 * 
 * 输入: nums = [1, 2, 3, 4]
 * 输出: -1
 * 解释: 4没有超过3的两倍大, 所以我们返回 -1.
 * 
 * 
 * 
 * 
 * 提示:
 * 
 * 
 * nums 的长度范围在[1, 50].
 * 每个 nums[i] 的整数范围在 [0, 100].
 * 
 * 
 */
#include "useforme.h"
// @lc code=start
class Solution {
public:
    int dominantIndex(vector<int>& nums) {
        int maxnum = 0;
        int maxindex = -1;
        for(int i = 0; i<nums.size();i++){
            if(nums[i]>maxnum){
                maxnum = nums[i];
                maxindex = i;
            }
        }
        for(int i = 0; i<nums.size();i++){
            if(i != maxindex){
                nums[i]= 2*nums[i];
            }
        }
        int maxtemp = maxnum;
        int index = maxindex;
        for(int i = 0; i<nums.size();i++){
            if(nums[i]>maxnum){
                maxnum = nums[i];
                maxindex = i;
            }
        }
        if(index == maxindex){
            return index;
        }
        return -1;
    }
};
// @lc code=end

