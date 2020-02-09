/*
 * @Description: 
 * @Version: 2.0
 * @Author: yunruowu
 * @Date: 2020-02-08 10:04:03
 * @LastEditors  : yunruowu
 * @LastEditTime : 2020-02-08 10:29:54
 */
/*
 * @lc app=leetcode.cn id=205 lang=cpp
 *
 * [205] 同构字符串
 *
 * https://leetcode-cn.com/problems/isomorphic-strings/description/
 *
 * algorithms
 * Easy (46.97%)
 * Likes:    153
 * Dislikes: 0
 * Total Accepted:    26.6K
 * Total Submissions: 56.6K
 * Testcase Example:  '"egg"\n"add"'
 *
 * 给定两个字符串 s 和 t，判断它们是否是同构的。
 * 
 * 如果 s 中的字符可以被替换得到 t ，那么这两个字符串是同构的。
 * 
 * 所有出现的字符都必须用另一个字符替换，同时保留字符的顺序。两个字符不能映射到同一个字符上，但字符可以映射自己本身。
 * 
 * 示例 1:
 * 
 * 输入: s = "egg", t = "add"
 * 输出: true
 * 
 * 
 * 示例 2:
 * 
 * 输入: s = "foo", t = "bar"
 * 输出: false
 * 
 * 示例 3:
 * 
 * 输入: s = "paper", t = "title"
 * 输出: true
 * 
 * 说明:
 * 你可以假设 s 和 t 具有相同的长度。
 * 
 */
#include <useforme.h>   
// @lc code=start
class Solution {
public:
//对比两个字符串对应位置的字符在字符串内第一次出现的位置
    bool isIsomorphic(string s, string t) {
        int len = s.size();
        for(int i  = 0; i<len;i++){
            if(s.find(s[i])!=t.find(t[i])) 
                return false;
        }
        return true;
    }
};
// @lc code=end

