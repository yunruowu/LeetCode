/*
 * @lc app=leetcode.cn id=423 lang=cpp
 *
 * [423] 从英文中重建数字
 *
 * https://leetcode-cn.com/problems/reconstruct-original-digits-from-english/description/
 *
 * algorithms
 * Medium (53.91%)
 * Likes:    48
 * Dislikes: 0
 * Total Accepted:    4.8K
 * Total Submissions: 8.9K
 * Testcase Example:  '"owoztneoer"'
 *
 * 给定一个非空字符串，其中包含字母顺序打乱的英文单词表示的数字0-9。按升序输出原始的数字。
 * 
 * 注意:
 * 
 * 
 * 输入只包含小写英文字母。
 * 输入保证合法并可以转换为原始的数字，这意味着像 "abc" 或 "zerone" 的输入是不允许的。
 * 输入字符串的长度小于 50,000。
 * 
 * 
 * 示例 1:
 * 
 * 
 * 输入: "owoztneoer"
 * 
 * 输出: "012" (zeroonetwo)
 * 
 * 
 * 示例 2:
 * one two three four five six seven eight nine zero
 * 
 * 输入: "fviefuro"
 * 
 * 输出: "45" (fourfive)
 * 
 * 
 */
#include "useforme.h"
// @lc code=start
class Solution {
public:
    string originalDigits(string s) {
        vector<int>mem(10, 0);
        vector<int>alp(26,0);
        for(int i=0; i<s.size(); i++){
            alp[s[i]-'a']++;
        }
        if(alp[25]!=0){//0
            mem[0]=alp[25];
            alp[('e'-'a')] -= alp[25];
            alp[('r'-'a')] -= alp[25];
            alp[('o'-'a')] -= alp[25];
        }
        if(alp['u'-'a']){//4
            mem[4] = alp[('u'-'a')];
            alp[('f'-'a')] -= alp[('u'-'a')];
            alp[('r'-'a')] -= alp[('u'-'a')];
            alp[('o'-'a')] -= alp[('u'-'a')];
        }
        if(alp[('f'-'a')]){//5
            mem[5] = alp[('f'-'a')];
            alp[('i'-'a')] -= alp[('f'-'a')];
            alp[('v'-'a')] -= alp[('f'-'a')];
            alp[('e'-'a')] -= alp[('f'-'a')];
        }
        if(alp[('x'-'a')]){//6
            mem[6]=alp[('x'-'a')];
            alp[('i'-'a')] -= alp[('x'-'a')];
            alp[('s'-'a')] -= alp[('x'-'a')];
        }
        if(alp[('s'-'a')]){//7
            mem[7] = alp[('s'-'a')];
            alp[('e'-'a')] -= 2*alp[('s'-'a')];
            alp[('n'-'a')] -= alp[('s'-'a')];
        }
        if(alp[('g'-'a')]){//8
            mem[8] = alp[('g'-'a')];
            alp[('h'-'a')] -= alp[('g'-'a')];
            alp[('t'-'a')] -= alp[('g'-'a')];
            alp[('i'-'a')] -= alp[('g'-'a')];
            alp[('e'-'a')] -= alp[('g'-'a')];
        }
        if(alp[('i'-'a')]){//9
            mem[9] = alp[('i'-'a')];
            alp[('n'-'a')] -= 2*alp[('i'-'a')];
            alp[('e'-'a')] -= alp[('i'-'a')];
        }
        if(alp[('h'-'a')]){//3
            mem[3] = alp[('h'-'a')];

        }
        if(alp[('w'-'a')]){//2
            mem[2] = alp[('w'-'a')];
        }
        if(alp[('n'-'a')]){//
            mem[1] = alp[('n'-'a')];
        }
        string ans;
        for(int i=0; i<10; i++){
            while(mem[i]!=0){
                ans += (i+'0');
                mem[i]--;
            }
        }
        return ans;
    }
};
// @lc code=end

