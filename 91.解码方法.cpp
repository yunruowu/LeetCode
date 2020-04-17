/*
 * @lc app=leetcode.cn id=91 lang=cpp
 *
 * [91] 解码方法
 *
 * https://leetcode-cn.com/problems/decode-ways/description/
 *
 * algorithms
 * Medium (23.28%)
 * Likes:    344
 * Dislikes: 0
 * Total Accepted:    42.7K
 * Total Submissions: 182.7K
 * Testcase Example:  '"12"'
 *
 * 一条包含字母 A-Z 的消息通过以下方式进行了编码：
 * 
 * 'A' -> 1
 * 'B' -> 2
 * ...
 * 'Z' -> 26
 * 
 * 
 * 给定一个只包含数字的非空字符串，请计算解码方法的总数。
 * 
 * 示例 1:
 * 
 * 输入: "12"
 * 输出: 2
 * 解释: 它可以解码为 "AB"（1 2）或者 "L"（12）。
 * 
 * 
 * 示例 2:
 * 
 * 输入: "226"
 * 输出: 3
 * 解释: 它可以解码为 "BZ" (2 26), "VF" (22 6), 或者 "BBF" (2 2 6) 。
 * 
 * 
 */
#include "useforme.h"
// @lc code=start
class Solution {
public:
    int sum  = 0;
    void get(string s , int cur){
        if(cur>=s.size()){
            sum ++;
            return ;
        }
        if(s[cur]=='0')
            return ;
        get(s, cur+1);
        if(s[cur]=='1'&&cur+1<s.size()){
            get(s, cur+2);
        }
        if(s[cur]=='2'&&cur+1<s.size()&&(s[cur+1]-'0'<=6)){
            get(s, cur+2);
        }
        return ;
    }
    int numDecodings(string s) {
        //?超时 if(s.empty())
        //     return 0;
        // get(s, 0);
        // return sum;
        int n = s.size();
    if (s[0] == '0')
        return 0;
    if (n == 1)
        return 1;
    vector<int> v(n, 0);
    v[0] = 1;
    if (s.substr(0, 2) <= "26")
        v[1] = s[1] == '0' ? 1 : 2;
    else
        v[1] = s[1] == '0' ? 0 : 1;
    for (int i = 2; i < n; i++)
    {
        if (s[i - 1] != '1'&&s[i - 1] != '2')//s[i]不可能与s[i-1]一起解码
        {
            if (s[i] == '0')//s[i]位置的0无法解码，返回0
                return 0;
            else//s[i]位置独立解码
                v[i] = v[i - 1];
        }
        else//s[i]可能与s[i-1]联合解码
        {
            if (s[i] == '0')
                v[i] = v[i - 2];
            else
                v[i] = (s.substr(i - 1, 2) <= "26") ? (v[i - 1] + v[i - 2]) : v[i - 1];
        }
    }
    return v[n - 1];
    }
};
// @lc code=end

