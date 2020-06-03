/*
 * @lc app=leetcode.cn id=131 lang=cpp
 *
 * [131] 分割回文串
 *
 * https://leetcode-cn.com/problems/palindrome-partitioning/description/
 *
 * algorithms
 * Medium (66.54%)
 * Likes:    295
 * Dislikes: 0
 * Total Accepted:    33.1K
 * Total Submissions: 49K
 * Testcase Example:  '"aab"'
 *
 * 给定一个字符串 s，将 s 分割成一些子串，使每个子串都是回文串。
 * 
 * 返回 s 所有可能的分割方案。
 * 
 * 示例:
 * 
 * 输入: "aab"
 * 输出:
 * [
 * ⁠ ["aa","b"],
 * ⁠ ["a","a","b"]
 * ]
 * 
 */
#include "useforme.h"
// @lc code=start
class Solution {
public:
    string mystr;
    vector<vector<string>> ans;
    int len;
    bool isPar(string str){
        int i=0,j = str.size()-1;
        while(i<j){
            if(str[i]!=str[j])
                return false;
            i++;
            j--;
        }
        return true;
    }
    void dfs(int cur, vector<string> mem){
        if(cur>=len)
        {
            ans.push_back(mem);
            return;
        }
        for (int i = cur; i < len; i++)
        {
            if(isPar(mystr.substr(cur, i-cur+1))){
                mem.push_back(mystr.substr(cur, i-cur+1));
                dfs(i+1,mem);
                mem.pop_back();
            }
        }
        return;
    }
    vector<vector<string>> partition(string s) {
        mystr = s;
        len = s.size();
        vector<string> m;
        dfs(0,m);
        return ans;
    }
};
// @lc code=end

