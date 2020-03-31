/*
 * @lc app=leetcode.cn id=78 lang=cpp
 *
 * [78] 子集
 *
 * https://leetcode-cn.com/problems/subsets/description/
 *
 * algorithms
 * Medium (76.10%)
 * Likes:    505
 * Dislikes: 0
 * Total Accepted:    74.1K
 * Total Submissions: 96.3K
 * Testcase Example:  '[1,2,3]'
 *
 * 给定一组不含重复元素的整数数组 nums，返回该数组所有可能的子集（幂集）。
 * 
 * 说明：解集不能包含重复的子集。
 * 
 * 示例:
 * 
 * 输入: nums = [1,2,3]
 * 输出:
 * [
 * ⁠ [3],
 * [1],
 * [2],
 * [1,2,3],
 * [1,3],
 * [2,3],
 * [1,2],
 * []
 * ]
 * 
 */
#include "useforme.h"
// @lc code=start
class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> E;
        ans.push_back(E);
        for(int i = 0; i<nums.size(); i++){
            int len = ans.size();
            for(int j = 0; j<len; j++){
                vector<int> cur = ans[j];
                cur.push_back(nums[i]);
                ans.push_back(cur);
            }
        }
        return ans;
    }
};
// @lc code=end

