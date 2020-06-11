/*
 * @lc app=leetcode.cn id=287 lang=cpp
 *
 * [287] 寻找重复数
 *
 * https://leetcode-cn.com/problems/find-the-duplicate-number/description/
 *
 * algorithms
 * Medium (63.57%)
 * Likes:    704
 * Dislikes: 0
 * Total Accepted:    78.7K
 * Total Submissions: 119.8K
 * Testcase Example:  '[1,3,4,2,2]'
 *
 * 给定一个包含 n + 1 个整数的数组 nums，其数字都在 1 到 n 之间（包括 1 和
 * n），可知至少存在一个重复的整数。假设只有一个重复的整数，找出这个重复的数。
 * 
 * 示例 1:
 * 
 * 输入: [1,3,4,2,2]
 * 输出: 2
 * 
 * 
 * 示例 2:
 * 
 * 输入: [3,1,3,4,2]
 * 输出: 3
 * 
 * 
 * 说明：
 * 
 * 
 * 不能更改原数组（假设数组是只读的）。
 * 只能使用额外的 O(1) 的空间。
 * 时间复杂度小于 O(n^2) 。
 * 数组中只有一个重复的数字，但它可能不止重复出现一次。
 * 
 * 
 */
#include "useforme.h"
// @lc code=start
class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int res = 0;
        for (int fast = 0; res != fast || fast == 0;){
            res = nums[res];
            fast = nums[nums[fast]];
        }
        // cout << res;
        for (int i = 0; res != i; i = nums[i]){
            res = nums[res];
        }
        return res;
    }
};
// @lc code=end

