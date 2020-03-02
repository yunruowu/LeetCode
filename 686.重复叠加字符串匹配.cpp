/*
 * @Description: 
 * @Version: 2.0
 * @Author: yunruowu
 * @Date: 2020-03-02 22:56:41
 * @LastEditors: yunruowu
 * @LastEditTime: 2020-03-02 23:25:14
 */
/*
 * @lc app=leetcode.cn id=686 lang=cpp
 *
 * [686] 重复叠加字符串匹配
 *
 * https://leetcode-cn.com/problems/repeated-string-match/description/
 *
 * algorithms
 * Easy (33.12%)
 * Likes:    73
 * Dislikes: 0
 * Total Accepted:    7.6K
 * Total Submissions: 22.5K
 * Testcase Example:  '"abcd"\n"cdabcdab"'
 *
 * 给定两个字符串 A 和 B, 寻找重复叠加字符串A的最小次数，使得字符串B成为叠加后的字符串A的子串，如果不存在则返回 -1。
 * 
 * 举个例子，A = "abcd"，B = "cdabcdab"。
 * 
 * 答案为 3， 因为 A 重复叠加三遍后为 “abcdabcdabcd”，此时 B 是其子串；A 重复叠加两遍后为"abcdabcd"，B
 * 并不是其子串。
 * 
 * 注意:
 * 
 * A 与 B 字符串的长度在1和10000区间范围内。
 * 
 */
#include "useforme.h"
// @lc code=start
class Solution {
public:
    
    int repeatedStringMatch(string A, string B) {
        string a = A;
        int i = 1;
        
        while(A.size()<B.size()){
            A = A + a;
            i++;
        }
        if((A.find(B)<A.size()&&A.find(B)>=0))
        {
            return i;
        }
        else{
            A = A+a;
            i++;
            if((A.find(B)<A.size()&&A.find(B)>=0))
            {
                return i;
            }
        }
        return -1;
    }
};
// @lc code=end

