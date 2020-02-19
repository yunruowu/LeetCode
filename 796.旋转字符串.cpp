/*
 * @Description: 
 * @Version: 2.0
 * @Author: yunruowu
 * @Date: 2020-02-19 16:53:05
 * @LastEditors: yunruowu
 * @LastEditTime: 2020-02-19 18:59:39
 */
/*
 * @lc app=leetcode.cn id=796 lang=cpp
 *
 * [796] 旋转字符串
 *
 * https://leetcode-cn.com/problems/rotate-string/description/
 *
 * algorithms
 * Easy (49.05%)
 * Likes:    61
 * Dislikes: 0
 * Total Accepted:    7.8K
 * Total Submissions: 15.7K
 * Testcase Example:  '"abcde"\n"cdeab"'
 *
 * 给定两个字符串, A 和 B。
 * 
 * A 的旋转操作就是将 A 最左边的字符移动到最右边。 例如, 若 A = 'abcde'，在移动一次之后结果就是'bcdea'
 * 。如果在若干次旋转操作之后，A 能变成B，那么返回True。
 * 
 * 
 * 示例 1:
 * 输入: A = 'abcde', B = 'cdeab'
 * 输出: true
 * 
 * 示例 2:
 * 输入: A = 'abcde', B = 'abced'
 * 输出: false
 * 
 * 注意：
 * 
 * 
 * A 和 B 长度不超过 100。
 * 
 * 
 */
#include "useforme.h"
// @lc code=start
class Solution {
public:
    string rotate(string A){
        char a = A[0];
        A.erase(0,1);
        A = A + a;
        return A;
    }
    bool rotateString(string A, string B) {
        
        int len = A.size();
        int i = 0 ;
        while(i<=len){
            i++;
            if(A == B){
                return true;
            }
            A = rotate(A);
        }
        return false;
    }
};
// @lc code=end

