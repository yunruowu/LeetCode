/*
 * @Description: 
 * @Version: 2.0
 * @Author: yunruowu
 * @Date: 2020-01-01 12:00:59
 * @LastEditors  : yunruowu
 * @LastEditTime : 2020-02-04 17:34:24
 */
/*
 * @lc app=leetcode.cn id=28 lang=cpp
 *
 * [28] 实现 strStr()
 *
 * https://leetcode-cn.com/problems/implement-strstr/description/
 *
 * algorithms
 * Easy (39.23%)
 * Likes:    333
 * Dislikes: 0
 * Total Accepted:    112.6K
 * Total Submissions: 287K
 * Testcase Example:  '"hello"\n"ll"'
 *
 * 实现 strStr() 函数。
 * 
 * 给定一个 haystack 字符串和一个 needle 字符串，在 haystack 字符串中找出 needle 字符串出现的第一个位置
 * (从0开始)。如果不存在，则返回  -1。
 * 
 * 示例 1:
 * 
 * 输入: haystack = "hello", needle = "ll"
 * 输出: 2
 * 
 * 
 * 示例 2:
 * 
 * 输入: haystack = "aaaaa", needle = "bba"
 * 输出: -1
 * 
 * 
 * 说明:
 * 
 * 当 needle 是空字符串时，我们应当返回什么值呢？这是一个在面试中很好的问题。
 * 
 * 对于本题而言，当 needle 是空字符串时我们应当返回 0 。这与C语言的 strstr() 以及 Java的 indexOf() 定义相符。
 * 
 */
#include<string>
#include<iostream>
using namespace std;

// @lc code=start


class Solution {
public:
    
    
    int strStr(string haystack, string needle) {
        if(needle.empty()==true){
            return 0;
        }
        for(int i = 0; i < haystack.size(); i++){
            int j = 0;
            int m = i; 
            while(haystack[m]==needle[j]&&j<needle.size()&&m<haystack.size()){
                m++;
                j++;
            }
            cout<<j;
            if(j == needle.size()){
                return i;
            }
        }
        return -1;
    }
};
// @lc code=end

