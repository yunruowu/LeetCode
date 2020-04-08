/*
 * @lc app=leetcode.cn id=46 lang=cpp
 *
 * [46] 全排列
 *
 * https://leetcode-cn.com/problems/permutations/description/
 *
 * algorithms
 * Medium (74.56%)
 * Likes:    594
 * Dislikes: 0
 * Total Accepted:    99.5K
 * Total Submissions: 133.3K
 * Testcase Example:  '[1,2,3]'
 *
 * 给定一个 没有重复 数字的序列，返回其所有可能的全排列。
 * 
 * 示例:
 * 
 * 输入: [1,2,3]
 * 输出:
 * [
 * ⁠ [1,2,3],
 * ⁠ [1,3,2],
 * ⁠ [2,1,3],
 * ⁠ [2,3,1],
 * ⁠ [3,1,2],
 * ⁠ [3,2,1]
 * ]
 * 
 */
#include "useforme.h"
// @lc code=start
class Solution {
public:
    vector<vector<int>> ans;
    void back(vector<int> nums, vector<int>cur, vector<int> tags){
        int l = ans.size();
        bool zero = 0;
        for(int i = 0; i<tags.size(); i++){
            vector<int> now(cur);
            vector<int> next(tags);
            if(tags[i]==0){
                zero = 1;
                next[i] = 1;
                now.push_back(nums[i]);
                back(nums, now, next);
            }
        }
        // cout<<zero;
        if(zero == 0){
            ans.push_back(cur);
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        int len = nums.size();
        vector<int> kong;
        // ans.push_back(kong);
        vector<int> tags(len, 0);
        back(nums, kong, tags);
        return ans;
    }
};
// @lc code=end

