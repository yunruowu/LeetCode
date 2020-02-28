/*
 * @Description: 
 * @Version: 2.0
 * @Author: yunruowu
 * @Date: 2020-02-28 10:27:45
 * @LastEditors: yunruowu
 * @LastEditTime: 2020-02-28 11:04:56
 */
/*
 * @lc app=leetcode.cn id=643 lang=cpp
 *
 * [643] 子数组最大平均数 I
 *
 * https://leetcode-cn.com/problems/maximum-average-subarray-i/description/
 *
 * algorithms
 * Easy (37.29%)
 * Likes:    77
 * Dislikes: 0
 * Total Accepted:    11.3K
 * Total Submissions: 29.8K
 * Testcase Example:  '[1,12,-5,-6,50,3]\n4'
 *
 * 给定 n 个整数，找出平均数最大且长度为 k 的连续子数组，并输出该最大平均数。
 * 
 * 示例 1:
 * 
 * 输入: [1,12,-5,-6,50,3], k = 4
 * 输出: 12.75
 * 解释: 最大平均数 (12-5-6+50)/4 = 51/4 = 12.75
 * 
 * 
 * 
 * 
 * 注意:
 * 
 * 
 * 1 <= k <= n <= 30,000。
 * 所给数据范围 [-10,000，10,000]。
 * 
 * 
 */
#include "useforme.h"
// @lc code=start
class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        int len = nums.size();
        int i = 0;
        double ave = 0;
        double sum = 0;
        // int j =0;
        while(i<k){
            sum+=nums[i];
            i++;
        }
        ave = sum;
        i=k;
        while(i<len){
            sum +=nums[i]-nums[i-k];
            ave = max(ave,sum);
            i++;
        }
        return ave/k;
    }
};
// @lc code=end

