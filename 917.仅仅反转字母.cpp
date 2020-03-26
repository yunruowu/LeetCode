/*
 * @Description: 
 * @Version: 2.0
 * @Author: yunruowu
 * @Date: 2020-03-26 10:17:54
 * @LastEditors: yunruowu
 * @LastEditTime: 2020-03-26 10:20:20
 */
/*
 * @lc app=leetcode.cn id=917 lang=cpp
 *
 * [917] 仅仅反转字母
 *
 * https://leetcode-cn.com/problems/reverse-only-letters/description/
 *
 * algorithms
 * Easy (53.01%)
 * Likes:    43
 * Dislikes: 0
 * Total Accepted:    9.9K
 * Total Submissions: 18.5K
 * Testcase Example:  '"ab-cd"'
 *
 * 给定一个字符串 S，返回 “反转后的” 字符串，其中不是字母的字符都保留在原地，而所有字母的位置发生反转。
 * 
 * 
 * 
 * 
 * 
 * 
 * 示例 1：
 * 
 * 输入："ab-cd"
 * 输出："dc-ba"
 * 
 * 
 * 示例 2：
 * 
 * 输入："a-bC-dEf-ghIj"
 * 输出："j-Ih-gfE-dCba"
 * 
 * 
 * 示例 3：
 * 
 * 输入："Test1ng-Leet=code-Q!"
 * 输出："Qedo1ct-eeLg=ntse-T!"
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * S.length <= 100
 * 33 <= S[i].ASCIIcode <= 122 
 * S 中不包含 \ or "
 * 
 * 
 */
#include "useforme.h"
// @lc code=start
class Solution {
public:
    string reverseOnlyLetters(string S) {
        int i = 0;
        int j = S.size();
        while(i<j){
            while(i<j&&!isalpha(S[i]))
                i++;
            while(i<j&&!isalpha(S[j]))
                j--;
            char temp = S[i];
            S[i] = S[j];
            S[j] = temp;
            i++;
            j--;
        }
        return S;
    }
};
// @lc code=end

