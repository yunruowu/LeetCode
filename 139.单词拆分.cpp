/*
 * @lc app=leetcode.cn id=139 lang=cpp
 *
 * [139] 单词拆分
 *
 * https://leetcode-cn.com/problems/word-break/description/
 *
 * algorithms
 * Medium (44.12%)
 * Likes:    461
 * Dislikes: 0
 * Total Accepted:    57.3K
 * Total Submissions: 127.7K
 * Testcase Example:  '"leetcode"\n["leet","code"]'
 *
 * 给定一个非空字符串 s 和一个包含非空单词列表的字典 wordDict，判定 s 是否可以被空格拆分为一个或多个在字典中出现的单词。
 * 
 * 说明：
 * 
 * 
 * 拆分时可以重复使用字典中的单词。
 * 你可以假设字典中没有重复的单词。
 * 
 * 
 * 示例 1：
 * 
 * 输入: s = "leetcode", wordDict = ["leet", "code"]
 * 输出: true
 * 解释: 返回 true 因为 "leetcode" 可以被拆分成 "leet code"。
 * 
 * 
 * 示例 2：
 * 
 * 输入: s = "applepenapple", wordDict = ["apple", "pen"]
 * 输出: true
 * 解释: 返回 true 因为 "applepenapple" 可以被拆分成 "apple pen apple"。
 * 注意你可以重复使用字典中的单词。
 * 
 * 
 * 示例 3：
 * 
 * 输入: s = "catsandog", wordDict = ["cats", "dog", "sand", "and", "cat"]
 * 输出: false
 * 
 * 
 */
#include "useforme.h"
// @lc code=start
class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        int n = s.size();
        vector<bool> dp(n+1,false);
        dp[n]=true;
        int i = n-1;
        // int last = 0;
        while(i>=0){
            // int tag = 0;
            for(int j=i;j<=n;j++){
                if(dp[j]){
                    int len = j-i;
                    string temp = s.substr(i, len);
                    // cout<<temp<<endl;
                    if(find(wordDict.begin(), wordDict.end(), temp)!=wordDict.end()){
                        dp[i] = true;
                        break;
                        // tag=1;
                    }
                }
            }
            i--;
        }
        return dp[0];
    }
};
// @lc code=end

