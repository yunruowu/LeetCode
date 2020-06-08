/*
 * @lc app=leetcode.cn id=47 lang=cpp
 *
 * [47] 全排列 II
 *
 * https://leetcode-cn.com/problems/permutations-ii/description/
 *
 * algorithms
 * Medium (57.84%)
 * Likes:    300
 * Dislikes: 0
 * Total Accepted:    61.3K
 * Total Submissions: 104.2K
 * Testcase Example:  '[1,1,2]'
 *
 * 给定一个可包含重复数字的序列，返回所有不重复的全排列。
 * 
 * 示例:
 * 
 * 输入: [1,1,2]
 * 输出:
 * [
 * ⁠ [1,1,2],
 * ⁠ [1,2,1],
 * ⁠ [2,1,1]
 * ]
 * 
 */
#include "useforme.h"
// @lc code=start
class Solution {
public:
    set<vector<int>> ans;
    int size;
    
    void dfs(int cur,  vector<int> ins, vector<int> nums){
        if(cur == size){
            ans.insert(ins);
            return ;
        }
        for(int i = 0; i<size; i++){
            if(nums[i]==-11111)
                continue;
            ins.push_back(nums[i]);
            int temp = nums[i];
            nums[i]=-11111;
            dfs(cur + 1, ins, nums);
            nums[i] = temp;
            ins.pop_back();
        }
        return;
    }
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        size = nums.size();
        vector<int> ins;
        vector<vector<int>> t;
        dfs(0,ins, nums);
        t.assign(ans.begin(), ans.end());
        return t;
    }
};
// @lc code=end

