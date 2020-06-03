/*
 * @lc app=leetcode.cn id=77 lang=cpp
 *
 * [77] 组合
 *
 * https://leetcode-cn.com/problems/combinations/description/
 *
 * algorithms
 * Medium (73.42%)
 * Likes:    245
 * Dislikes: 0
 * Total Accepted:    44.4K
 * Total Submissions: 60.4K
 * Testcase Example:  '4\n2'
 *
 * 给定两个整数 n 和 k，返回 1 ... n 中所有可能的 k 个数的组合。
 * 
 * 示例:
 * 
 * 输入: n = 4, k = 2
 * 输出:
 * [
 * ⁠ [2,4],
 * ⁠ [3,4],
 * ⁠ [2,3],
 * ⁠ [1,2],
 * ⁠ [1,3],
 * ⁠ [1,4],
 * ]
 * 
 */
#include "useforme.h"
// @lc code=start
class Solution {
public:
    int num;
    int nn;
    vector<vector<int>> ans;
    void dfs(int cur,int pos,vector<int>temp){
        // cout<<cur<<endl;
        if(cur==num){
            cout<<temp[0];
            ans.push_back(temp);
            return;
        }
        for(int i = pos+1; i<=nn; i++){
            // vector<int> now = temp;
            temp.push_back(i);
            dfs(cur+1, i, temp);
            temp.pop_back();
        }
        return;
    }
    vector<vector<int>> combine(int n, int k) {
        // vector<vector<int>> ans;
        vector<int> ins;
        num = k;
        nn = n;
        dfs(0, 0, ins);
        cout<<ans.size();
        return ans;
    }
};
// @lc code=end

