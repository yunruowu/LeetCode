/*
 * @lc app=leetcode.cn id=216 lang=cpp
 *
 * [216] 组合总和 III
 *
 * https://leetcode-cn.com/problems/combination-sum-iii/description/
 *
 * algorithms
 * Medium (70.55%)
 * Likes:    116
 * Dislikes: 0
 * Total Accepted:    21.5K
 * Total Submissions: 30.2K
 * Testcase Example:  '3\n7'
 *
 * 找出所有相加之和为 n 的 k 个数的组合。组合中只允许含有 1 - 9 的正整数，并且每种组合中不存在重复的数字。
 * 
 * 说明：
 * 
 * 
 * 所有数字都是正整数。
 * 解集不能包含重复的组合。 
 * 
 * 
 * 示例 1:
 * 
 * 输入: k = 3, n = 7
 * 输出: [[1,2,4]]
 * 
 * 
 * 示例 2:
 * 
 * 输入: k = 3, n = 9
 * 输出: [[1,2,6], [1,3,5], [2,3,4]]
 * 
 * 
 */
#include "useforme.h"
// @lc code=start
class Solution {
public:
    vector<vector<int>> ans;
    int nn;
    int kk;
    void dfs(int cur_k, int cur_n, vector<int> ins, int pos){
        if(cur_k==kk&&cur_n==nn){
            ans.push_back(ins);
            return;
        }
        for(int i = pos+1; i<10;i++){
            ins.push_back(i);
            if(cur_n+i>nn){
                break;
            }
            dfs(cur_k+1, cur_n+i, ins, i);
            ins.pop_back();
        }
        return ;
    }
    vector<vector<int>> combinationSum3(int k, int n) {
        kk = k;
        nn = n;
        vector<int> ins;
        vector<int> used(10,0);
        dfs(0, 0, ins, 0);
        return ans;
    }
};
// @lc code=end

