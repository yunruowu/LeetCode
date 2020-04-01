/*
 * @lc app=leetcode.cn id=3 lang=cpp
 *
 * [3] 无重复字符的最长子串
 *
 * https://leetcode-cn.com/problems/longest-substring-without-repeating-characters/description/
 *
 * algorithms
 * Medium (32.71%)
 * Likes:    3134
 * Dislikes: 0
 * Total Accepted:    340.8K
 * Total Submissions: 1M
 * Testcase Example:  '"abcabcbb"'
 *
 * 给定一个字符串，请你找出其中不含有重复字符的 最长子串 的长度。
 * 
 * 示例 1:
 * 
 * 输入: "abcabcbb"
 * 输出: 3 
 * 解释: 因为无重复字符的最长子串是 "abc"，所以其长度为 3。
 * 
 * 
 * 示例 2:
 * 
 * 输入: "bbbbb"
 * 输出: 1
 * 解释: 因为无重复字符的最长子串是 "b"，所以其长度为 1。
 * 
 * 
 * 示例 3:
 * 
 * 输入: "pwwkew"
 * 输出: 3
 * 解释: 因为无重复字符的最长子串是 "wke"，所以其长度为 3。
 * 请注意，你的答案必须是 子串 的长度，"pwke" 是一个子序列，不是子串。
 * 
 * 
 */
#include "useforme.h"
#include <iostream>
// @lc code=start
class Solution {
public:
    bool inBefore(string s , int pos, int i){
        for(int j = pos; j<i; j++){
            if(s[j] == s[i]){
                return true;
            }
        }
        return false;
    }
    int lengthOfLongestSubstring(string s) {
        if(s.size()<=1){
            return s.size();
        }
        // vector<int> alpha(26, 0);
        int subLen = 1;
        int len = s.size();
        int i = 1;
        int pos = 0;
        // alpha[s[0]-'a']++;
        while (i<len)
        {
            if(inBefore(s, pos, i)==false){
                // alpha[s[i]-'a']++;
                subLen = max(subLen, i-pos+1);
                i++;
                
                cout<<pos<<' '<<i<<" "<<subLen<<endl;
            }else{
                while(s[pos]!=s[i])
                {    
                    // alpha[s[pos]-'a']--;
                    pos++;
                }
                pos++;
                i++;
                cout<<pos<<' '<<i<<endl;
                // if(pos == i){
                //     i++;
                // }
                // alpha[s[i]-'a']++;
            }
        }
        return subLen;
    }
};
// @lc code=end

