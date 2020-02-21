/*
 * @Description: 
 * @Version: 2.0
 * @Author: yunruowu
 * @Date: 2020-02-21 09:18:36
 * @LastEditors: yunruowu
 * @LastEditTime: 2020-02-21 09:31:57
 */
/*
 * @lc app=leetcode.cn id=557 lang=cpp
 *
 * [557] 反转字符串中的单词 III
 *
 * https://leetcode-cn.com/problems/reverse-words-in-a-string-iii/description/
 *
 * algorithms
 * Easy (69.14%)
 * Likes:    156
 * Dislikes: 0
 * Total Accepted:    42.4K
 * Total Submissions: 61.1K
 * Testcase Example:  '"Let\'s take LeetCode contest"'
 *
 * 给定一个字符串，你需要反转字符串中每个单词的字符顺序，同时仍保留空格和单词的初始顺序。
 * 
 * 示例 1:
 * 
 * 
 * 输入: "Let's take LeetCode contest"
 * 输出: "s'teL ekat edoCteeL tsetnoc" 
 * 
 * 
 * 注意：在字符串中，每个单词由单个空格分隔，并且字符串中不会有任何额外的空格。
 * 
 */
#include "useforme.h"
// @lc code=start
class Solution {
public:
    string reverseWords(string s) {
        int i = 0;
        int len = s.size();
        while(i<len){
            int left = i;
            int right = i;
            while((right+1)!=len&&s[right+1]!=' '){
                right++;
            }
            i = right+2;
            while(left<=right){
                swap(s[left],s[right]);
                left++;
                right--;
            }
            
        }
        return s;
    }
};
// @lc code=end

