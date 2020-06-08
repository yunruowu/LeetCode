/*
 * @lc app=leetcode.cn id=40 lang=cpp
 *
 * [40] 组合总和 II
 *
 * https://leetcode-cn.com/problems/combination-sum-ii/description/
 *
 * algorithms
 * Medium (60.98%)
 * Likes:    233
 * Dislikes: 0
 * Total Accepted:    49.8K
 * Total Submissions: 81.5K
 * Testcase Example:  '[10,1,2,7,6,1,5]\n8'
 *
 * 给定一个数组 candidates 和一个目标数 target ，找出 candidates 中所有可以使数字和为 target 的组合。
 * 
 * candidates 中的每个数字在每个组合中只能使用一次。
 * 
 * 说明：
 * 
 * 
 * 所有数字（包括目标数）都是正整数。
 * 解集不能包含重复的组合。 
 * 
 * 
 * 示例 1:
 * 
 * 输入: candidates = [10,1,2,7,6,1,5], target = 8,
 * 所求解集为:
 * [
 * ⁠ [1, 7],
 * ⁠ [1, 2, 5],
 * ⁠ [2, 6],
 * ⁠ [1, 1, 6]
 * ]
 * 
 * 
 * 示例 2:
 * 
 * 输入: candidates = [2,5,2,1,2], target = 5,
 * 所求解集为:
 * [
 * [1,2,2],
 * [5]
 * ]
 * 
 */
#include "useforme.h"
// @lc code=start
class Solution {
public:
    set<vector<int>> ans;
    int target;
    int size;
    vector<int> candidates;
    void dfs(int curSum, int pos, vector<int> ins){
        if(curSum == target)
        {
            // cout<<"sds";
            ans.insert(ins);
            return;
        }
        for(int i = pos+1; i<size; i++){
            if(curSum+candidates[i]>target){
                return;
            }
            ins.push_back(candidates[i]);
            dfs(curSum+candidates[i], i, ins);
            ins.pop_back();
        }
        return;
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        this->target = target;
        this->candidates = candidates;
        this->size = candidates.size();
        vector<int> ins;
        dfs(0,-1,ins);
        vector<vector<int>> t;
        t.assign(ans.begin(), ans.end());
        return t;
    }
};
// @lc code=end

