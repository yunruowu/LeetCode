/*
 * @lc app=leetcode.cn id=90 lang=cpp
 *
 * [90] 子集 II
 *
 * https://leetcode-cn.com/problems/subsets-ii/description/
 *
 * algorithms
 * Medium (58.58%)
 * Likes:    176
 * Dislikes: 0
 * Total Accepted:    27.1K
 * Total Submissions: 45.7K
 * Testcase Example:  '[1,2,2]'
 *
 * 给定一个可能包含重复元素的整数数组 nums，返回该数组所有可能的子集（幂集）。
 * 
 * 说明：解集不能包含重复的子集。
 * 
 * 示例:
 * 
 * 输入: [1,2,2]
 * 输出:
 * [
 * ⁠ [2],
 * ⁠ [1],
 * ⁠ [1,2,2],
 * ⁠ [2,2],
 * ⁠ [1,2],
 * ⁠ []
 * ]
 * 
 */
#include "useforme.h"
// @lc code=start
class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> E;
        ans.push_back(E);
        sort(nums.begin(), nums.end());
        // cout<<1;
        
        for(int i = 0; i<nums.size(); i++){
            int len = ans.size();
            if(i!=nums.size()-1 && nums[i]==nums[i+1])
            {
                // cout<<1;
                vector<vector<int>> repeat;
                vector<int> cur;
                cur.push_back(nums[i]);
                repeat.push_back(cur);
                while(i<nums.size()-1&&nums[i]==nums[i+1]){
                    cur.push_back(nums[i]);
                    repeat.push_back(cur);
                    i++;
                }
                for(int k = 0; k<repeat.size(); k++){
                    for(int j = 0; j<len; j++){
                        vector<int> ins = ans[j];
                        ins.insert(ins.end(), repeat[k].begin(), repeat[k].end());
                        ans.push_back(ins);
                    }
                }
                
            }else{
                // int len  = 0;
                vector<int> cur;
                for(int j = 0; j<len; j++){
                    vector<int> cur = ans[j];
                    cur.push_back(nums[i]);
                    ans.push_back(cur);
                }
            }
        }
        
        
        return ans;

    }
};
// @lc code=end

