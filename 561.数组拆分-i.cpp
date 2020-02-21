/*
 * @Description: 
 * @Version: 2.0
 * @Author: yunruowu
 * @Date: 2020-02-21 10:27:59
 * @LastEditors: yunruowu
 * @LastEditTime: 2020-02-21 10:32:35
 */
/*
 * @lc app=leetcode.cn id=561 lang=cpp
 *
 * [561] 数组拆分 I
 *
 * https://leetcode-cn.com/problems/array-partition-i/description/
 *
 * algorithms
 * Easy (69.37%)
 * Likes:    141
 * Dislikes: 0
 * Total Accepted:    29.1K
 * Total Submissions: 41.9K
 * Testcase Example:  '[1,4,3,2]'
 *
 * 给定长度为 2n 的数组, 你的任务是将这些数分成 n 对, 例如 (a1, b1), (a2, b2), ..., (an, bn) ，使得从1 到
 * n 的 min(ai, bi) 总和最大。
 * 
 * 示例 1:
 * 
 * 
 * 输入: [1,4,3,2]
 * 
 * 输出: 4
 * 解释: n 等于 2, 最大总和为 4 = min(1, 2) + min(3, 4).
 * 
 * 
 * 提示:
 * 
 * 
 * n 是正整数,范围在 [1, 10000].
 * 数组中的元素范围在 [-10000, 10000].
 * 
 * 
 */
#include "useforme.h"
// @lc code=start
class Solution {
public:
    int arrayPairSum(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int ans = 0;
        for(int i = 0;i<nums.size();i=i+2){
            ans = ans + nums[i];
        }
        return ans;
    }
    
};
// @lc code=end

