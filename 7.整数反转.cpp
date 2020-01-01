/*
 * @Description: 
 * @Version: 2.0
 * @Author: yunruowu
 * @Date: 2019-12-31 08:27:01
 * @LastEditors  : yunruowu
 * @LastEditTime : 2019-12-31 08:32:50
 */
/*
 * @lc app=leetcode.cn id=7 lang=cpp
 *
 * [7] 整数反转
 *
 * https://leetcode-cn.com/problems/reverse-integer/description/
 *
 * algorithms
 * Easy (33.36%)
 * Likes:    1562
 * Dislikes: 0
 * Total Accepted:    245.6K
 * Total Submissions: 736.2K
 * Testcase Example:  '123'
 *
 * 给出一个 32 位的有符号整数，你需要将这个整数中每位上的数字进行反转。
 * 
 * 示例 1:
 * 
 * 输入: 123
 * 输出: 321
 * 
 * 
 * 示例 2:
 * 
 * 输入: -123
 * 输出: -321
 * 
 * 
 * 示例 3:
 * 
 * 输入: 120
 * 输出: 21
 * 
 * 
 * 注意:
 * 
 * 假设我们的环境只能存储得下 32 位的有符号整数，则其数值范围为 [−2^31,  2^31 − 1]。请根据这个假设，如果反转后整数溢出那么就返回
 * 0。
 * 
 */
#include<limits.h>
// @lc code=start
class Solution {
public:
    int reverse(int x) {
        long n = 0;
        while(x!=0){
            int i = x%10;
            x= (x-i)/10;
            n = n*10+i;
        }
        if(n>INT_MAX||n<INT_MIN){
            return 0;
        }
        return n;
    }
};
// @lc code=end

