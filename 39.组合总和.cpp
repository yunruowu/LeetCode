/*
 * @lc app=leetcode.cn id=39 lang=cpp
 *
 * [39] 组合总和
 *
 * https://leetcode-cn.com/problems/combination-sum/description/
 *
 * algorithms
 * Medium (68.67%)
 * Likes:    597
 * Dislikes: 0
 * Total Accepted:    80.9K
 * Total Submissions: 117.7K
 * Testcase Example:  '[2,3,6,7]\n7'
 *
 * 给定一个无重复元素的数组 candidates 和一个目标数 target ，找出 candidates 中所有可以使数字和为 target 的组合。
 * 
 * candidates 中的数字可以无限制重复被选取。
 * 
 * 说明：
 * 
 * 
 * 所有数字（包括 target）都是正整数。
 * 解集不能包含重复的组合。 
 * 
 * 
 * 示例 1:
 * 
 * 输入: candidates = [2,3,6,7], target = 7,
 * 所求解集为:
 * [
 * ⁠ [7],
 * ⁠ [2,2,3]
 * ]
 * 
 * 
 * 示例 2:
 * 
 * 输入: candidates = [2,3,5], target = 8,
 * 所求解集为:
 * [
 * [2,2,2,2],
 * [2,3,3],
 * [3,5]
 * ]
 * 
 */
#include "useforme.h"
// @lc code=start
class Solution {
public:
    set< vector<int> > ans;
    void cal(vector<int>cans, int target, vector<int> cur){
        if(target == 0){
            sort(cur.begin(), cur.end());
            ans.insert(cur);
            return;
        }
        for(int i = 0; i<cans.size(); i++)
        {
            if(target-cans[i]>=0){
                cur.push_back(cans[i]);
                cal(cans, target-cans[i],cur);
                cur.pop_back();
            }else{
                return;
            }
        }
        return ;
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<int> cur;
        sort(candidates.begin(), candidates.end());
        cal(candidates, target, cur);
        set< vector<int> >::iterator it;
        vector<vector<int> >out;
        for(it=ans.begin ();it!=ans.end ();it++)
        {
            // vector<int> m = *it;
            // Prinetvec(m);
            out.push_back(*it);
        }
        return out;
    }
};
// @lc code=end

