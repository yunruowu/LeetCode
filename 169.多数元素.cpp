/*
 * @Description: 
 * @Version: 2.0
 * @Author: yunruowu
 * @Date: 2020-02-06 11:46:21
 * @LastEditors  : yunruowu
 * @LastEditTime : 2020-02-06 20:49:41
 */
/*
 * @lc app=leetcode.cn id=169 lang=cpp
 *
 * [169] 多数元素
 *
 * https://leetcode-cn.com/problems/majority-element/description/
 *
 * algorithms
 * Easy (61.31%)
 * Likes:    427
 * Dislikes: 0
 * Total Accepted:    104.7K
 * Total Submissions: 170.6K
 * Testcase Example:  '[3,2,3]'
 *
 * 给定一个大小为 n 的数组，找到其中的多数元素。多数元素是指在数组中出现次数大于 ⌊ n/2 ⌋ 的元素。
 * 
 * 你可以假设数组是非空的，并且给定的数组总是存在多数元素。
 * 
 * 示例 1:
 * 
 * 输入: [3,2,3]
 * 输出: 3
 * 
 * 示例 2:
 * 
 * 输入: [2,2,1,1,1,2,2]
 * 输出: 2
 * 
 * 
 */
#include "useforme.h"
// @lc code=start
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int condidate = nums[0];
        int count = 0;
        for(int i = 0 ; i <  nums.size(); i++){
            if(count == 0){
                condidate = nums[i];
            }
            if(condidate != nums[i]){
                count --;
            }else
            {
                count++;
            }
            
        }
        return condidate;
    }
};
// @lc code=end

