/*
 * @Description: 
 * @Version: 2.0
 * @Author: yunruowu
 * @Date: 2020-01-31 10:48:54
 * @LastEditors  : yunruowu
 * @LastEditTime : 2020-01-31 10:54:19
 */
/*
 * @lc app=leetcode.cn id=344 lang=cpp
 *
 * [344] 反转字符串
 *
 * https://leetcode-cn.com/problems/reverse-string/description/
 *
 * algorithms
 * Easy (68.25%)
 * Likes:    209
 * Dislikes: 0
 * Total Accepted:    103.7K
 * Total Submissions: 151K
 * Testcase Example:  '["h","e","l","l","o"]'
 *
 * 编写一个函数，其作用是将输入的字符串反转过来。输入字符串以字符数组 char[] 的形式给出。
 * 
 * 不要给另外的数组分配额外的空间，你必须原地修改输入数组、使用 O(1) 的额外空间解决这一问题。
 * 
 * 你可以假设数组中的所有字符都是 ASCII 码表中的可打印字符。
 * 
 * 
 * 
 * 示例 1：
 * 
 * 输入：["h","e","l","l","o"]
 * 输出：["o","l","l","e","h"]
 * 
 * 
 * 示例 2：
 * 
 * 输入：["H","a","n","n","a","h"]
 * 输出：["h","a","n","n","a","H"]
 * 
 */
#include <vector>
#include <stdio.h>
using namespace std;
// @lc code=start
class Solution {
public:
    void reverseString(vector<char>& s) {
        int n = s.size();
        int i= 0;
        while (i<n/2)
        {
            swap(s[i],s[n-1-i]);
            i++;
        }
        
    }
};
// @lc code=end

