/*
 * @Description: 
 * @Version: 2.0
 * @Author: yunruowu
 * @Date: 2020-02-01 14:33:10
 * @LastEditors  : yunruowu
 * @LastEditTime : 2020-02-01 14:35:46
 */
/*
 * @lc app=leetcode.cn id=389 lang=cpp
 *
 * [389] 找不同
 *
 * https://leetcode-cn.com/problems/find-the-difference/description/
 *
 * algorithms
 * Easy (60.23%)
 * Likes:    105
 * Dislikes: 0
 * Total Accepted:    20.2K
 * Total Submissions: 33.4K
 * Testcase Example:  '"abcd"\n"abcde"'
 *
 * 给定两个字符串 s 和 t，它们只包含小写字母。
 * 
 * 字符串 t 由字符串 s 随机重排，然后在随机位置添加一个字母。
 * 
 * 请找出在 t 中被添加的字母。
 * 
 * 
 * 
 * 示例:
 * 
 * 输入：
 * s = "abcd"
 * t = "abcde"
 * 
 * 输出：
 * e
 * 
 * 解释：
 * 'e' 是那个被添加的字母。
 * 
 * 
 */
#include <string>
using namespace std;
// @lc code=start
class Solution {
public:
    char findTheDifference(string s, string t) {
        for(int i = 0; i<s.size(); i++){
            int index = t.find(s[i]);
            t.erase(t.begin()+index);
        }
        return t[0];
    }
};
// @lc code=end

