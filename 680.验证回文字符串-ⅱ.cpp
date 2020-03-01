/*
 * @Description: 
 * @Version: 2.0
 * @Author: yunruowu
 * @Date: 2020-03-01 10:35:07
 * @LastEditors: yunruowu
 * @LastEditTime: 2020-03-01 11:00:35
 */
/*
 * @lc app=leetcode.cn id=680 lang=cpp
 *
 * [680] 验证回文字符串 Ⅱ
 *
 * https://leetcode-cn.com/problems/valid-palindrome-ii/description/
 *
 * algorithms
 * Easy (34.79%)
 * Likes:    121
 * Dislikes: 0
 * Total Accepted:    13.9K
 * Total Submissions: 39.2K
 * Testcase Example:  '"aba"'
 *
 * 给定一个非空字符串 s，最多删除一个字符。判断是否能成为回文字符串。
 * 
 * 示例 1:
 * 
 * 
 * 输入: "aba"
 * 输出: True
 * 
 * 
 * 示例 2:
 * 
 * 
 * 输入: "abca"
 * 输出: True
 * 解释: 你可以删除c字符。
 * 
 * 
 * 注意:
 * 
 * 
 * 字符串只包含从 a-z 的小写字母。字符串的最大长度是50000。
 * 
 * 
 */
#include "useforme.h"
// @lc code=start
class Solution {
public:
    bool isPalindrom(string s){
        int i = 0;
        while(i<s.size()/2){
            if(s[i]==s[s.size()-1-i]){
                i++;
            }
            else{
                return false;
            }
        }
        return true;
    }

    bool validPalindrome(string s) {
        int l = 0;
        int r = s.size()-1;
        while(l<r&&s[l]==s[r]){
            l++;
            r--;
        }
        if(l>=r)
            return true;
        if(l<r){
            cout<<1;
            int ll = l;
            l++;
            int rr = r;
            while(l<r&&s[l]==s[r]){
                l++;
                r--;
            }
            if(l>=r)
                return true;
            // cout<<l<<r;
            l = ll;
            r = rr-1;
            cout<<l<<r;
            while(l<r&&s[l]==s[r]){
                l++;
                r--;
            }
            if(l>=r)
                return true;
            cout<<l<<r;
        }
        return false;
    }
};
// @lc code=end

