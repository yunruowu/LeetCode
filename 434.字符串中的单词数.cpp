/*
 * @Description: 
 * @Version: 2.0
 * @Author: yunruowu
 * @Date: 2020-02-14 17:03:39
 * @LastEditors  : yunruowu
 * @LastEditTime : 2020-02-14 17:13:39
 */
/*
 * @lc app=leetcode.cn id=434 lang=cpp
 *
 * [434] 字符串中的单词数
 *
 * https://leetcode-cn.com/problems/number-of-segments-in-a-string/description/
 *
 * algorithms
 * Easy (33.66%)
 * Likes:    47
 * Dislikes: 0
 * Total Accepted:    12.2K
 * Total Submissions: 36.2K
 * Testcase Example:  '"Hello, my name is John"'
 *
 * 统计字符串中的单词个数，这里的单词指的是连续的不是空格的字符。
 * 
 * 请注意，你可以假定字符串里不包括任何不可打印的字符。
 * 
 * 示例:
 * 
 * 输入: "Hello, my name is John"
 * 输出: 5
 * 
 * 
 */
#include "useforme.h"
// @lc code=start
class Solution {
public:
    int countSegments(string s) {
        if(s==""){
            return 0;
        }
        int len = s.size();
        int i = 0;
        int num = 0;
        while(i<len){
            int j = i;
            while(s[j]!=' ' && j<len){
                j++;
            }
            if(j>i){
                num++;
            }
            i = j+1;
        }
        return num;
    }
};
// @lc code=end

