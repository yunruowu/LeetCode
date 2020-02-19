/*
 * @Description: 
 * @Version: 2.0
 * @Author: yunruowu
 * @Date: 2020-02-14 16:43:21
 * @LastEditors  : yunruowu
 * @LastEditTime : 2020-02-14 17:03:06
 */
/*
 * @lc app=leetcode.cn id=415 lang=cpp
 *
 * [415] 字符串相加
 *
 * https://leetcode-cn.com/problems/add-strings/description/
 *
 * algorithms
 * Easy (49.21%)
 * Likes:    131
 * Dislikes: 0
 * Total Accepted:    23.1K
 * Total Submissions: 46.7K
 * Testcase Example:  '"0"\n"0"'
 *
 * 给定两个字符串形式的非负整数 num1 和num2 ，计算它们的和。
 * 
 * 注意：
 * 
 * 
 * num1 和num2 的长度都小于 5100.
 * num1 和num2 都只包含数字 0-9.
 * num1 和num2 都不包含任何前导零。
 * 你不能使用任何內建 BigInteger 库， 也不能直接将输入的字符串转换为整数形式。
 * 
 * 
 */
#include "useforme.h"
// @lc code=start
class Solution {
public:
    string addStrings(string num1, string num2) {
        int i = num1.size()-1;
        int j = num2.size()-1;
        char c = '0';
        string ans ="";
        while(i>=0&&j>=0){
            int sum = (num1[i]-'0') + (num2[j]-'0') + (c-'0');
            if(sum>=10){
                c = '1';
                sum = sum - 10;
            }else{
                c = '0';
            }
            char s = sum + '0';
            ans = s + ans;
            // cout<<ans<<" ";
            i--;
            j--;
        }
        while(i>=0){
            int sum = (num1[i]-'0') + (c-'0');
            if(sum>=10){
                c = '1';
                sum = sum - 10;
            }else{
                c = '0';
            }
            char s = sum + '0';
            ans = s + ans  ;
            // cout<<ans<<" ";
            i--;
        }
        while(j>=0){
            int sum = (num2[j]-'0') + (c-'0');
            // cout<<sum;
            if(sum>=10){
                c = '1';
                sum = sum - 10;
            }else{
                c = '0';
            }
            char s = sum + '0';
            
            ans = s + ans;
            // cout<<ans<<" ";
            j--;
        }
        if(c == '1'){
            // cout<<"   dsds ";
            ans = c + ans;
        }
        return ans;
    }
};
// @lc code=end

