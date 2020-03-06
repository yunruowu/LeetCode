/*
 * @Description: 
 * @Version: 2.0
 * @Author: yunruowu
 * @Date: 2020-03-05 19:00:44
 * @LastEditors: yunruowu
 * @LastEditTime: 2020-03-05 19:07:22
 */
/*
 * @lc app=leetcode.cn id=709 lang=cpp
 *
 * [709] 转换成小写字母
 *
 * https://leetcode-cn.com/problems/to-lower-case/description/
 *
 * algorithms
 * Easy (75.15%)
 * Likes:    110
 * Dislikes: 0
 * Total Accepted:    38.2K
 * Total Submissions: 50.7K
 * Testcase Example:  '"Hello"'
 *
 * 实现函数 ToLowerCase()，该函数接收一个字符串参数 str，并将该字符串中的大写字母转换成小写字母，之后返回新的字符串。
 * 
 * 
 * 
 * 示例 1：
 * 
 * 
 * 输入: "Hello"
 * 输出: "hello"
 * 
 * 示例 2：
 * 
 * 
 * 输入: "here"
 * 输出: "here"
 * 
 * 示例 3：
 * 
 * 
 * 输入: "LOVELY"
 * 输出: "lovely"
 * 
 * 
 */
#include "useforme.h"
// @lc code=start
class Solution {
public:
    string toLowerCase(string str) {
        int i = 0;
        while(i<str.size()){
            if(str[i]>='A'&&str[i]<='Z'){
                str[i] = str[i]+32;
            }
            i++;
        }
        return str;
    }
};
// @lc code=end

