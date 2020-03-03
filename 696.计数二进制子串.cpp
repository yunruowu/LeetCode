/*
 * @Description: 
 * @Version: 2.0
 * @Author: yunruowu
 * @Date: 2020-03-03 10:58:14
 * @LastEditors: yunruowu
 * @LastEditTime: 2020-03-03 11:25:00
 */
/*
 * @lc app=leetcode.cn id=696 lang=cpp
 *
 * [696] 计数二进制子串
 *
 * https://leetcode-cn.com/problems/count-binary-substrings/description/
 *
 * algorithms
 * Easy (49.73%)
 * Likes:    123
 * Dislikes: 0
 * Total Accepted:    7.8K
 * Total Submissions: 15.5K
 * Testcase Example:  '"00110"'
 *
 * 给定一个字符串 s，计算具有相同数量0和1的非空(连续)子字符串的数量，并且这些子字符串中的所有0和所有1都是组合在一起的。
 * 
 * 重复出现的子串要计算它们出现的次数。
 * 
 * 示例 1 :
 * 
 * 
 * 输入: "00110011"
 * 输出: 6
 * 解释: 有6个子串具有相同数量的连续1和0：“0011”，“01”，“1100”，“10”，“0011” 和 “01”。
 * 
 * 请注意，一些重复出现的子串要计算它们出现的次数。
 * 
 * 另外，“00110011”不是有效的子串，因为所有的0（和1）没有组合在一起。
 * 
 * 
 * 示例 2 :
 * 
 * 
 * 输入: "10101"
 * 输出: 4
 * 解释: 有4个子串：“10”，“01”，“10”，“01”，它们具有相同数量的连续1和0。
 * 
 * 
 * 注意：
 * 
 * 
 * s.length 在1到50,000之间。
 * s 只包含“0”或“1”字符。
 * 
 * 
 */
#include "useforme.h"
// @lc code=start
class Solution {
public:
    int countBinarySubstrings(string s) {
        int i = 0;
        if(s.size() == 1){
            return 0;
        }
        vector<int> num;
        while(i<s.size()){
            int pos = i;
            int len = 0;
            while(s[i]==s[pos]&&i<s.size()){
                len ++;
                i++;
            }
            num.push_back(len);
        }
        int ans = 0;
        // cout<<num[0];
        for(int i = 1;i<num.size();i++){
            // cout<<num[i];
            ans+=min(num[i-1],num[i]);
        }
        return ans;
    }
};
// @lc code=end

