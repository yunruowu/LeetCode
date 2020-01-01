/*
 * @Description: 
 * @Version: 2.0
 * @Author: yunruowu
 * @Date: 2019-12-31 10:08:13
 * @LastEditors  : yunruowu
 * @LastEditTime : 2019-12-31 10:11:52
 */
/*
 * @lc app=leetcode.cn id=371 lang=cpp
 *
 * [371] 两整数之和
 *
 * https://leetcode-cn.com/problems/sum-of-two-integers/description/
 *
 * algorithms
 * Easy (53.17%)
 * Likes:    177
 * Dislikes: 0
 * Total Accepted:    19.8K
 * Total Submissions: 37.3K
 * Testcase Example:  '1\n2'
 *
 * 不使用运算符 + 和 - ​​​​​​​，计算两整数 ​​​​​​​a 、b ​​​​​​​之和。
 * 
 * 示例 1:
 * 
 * 输入: a = 1, b = 2
 * 输出: 3
 * 
 * 
 * 示例 2:
 * 
 * 输入: a = -2, b = 3
 * 输出: 1
 * 
 */

// @lc code=start
class Solution {
public:
    int getSum(int a, int b) {
        while (b) {
            auto c = ((unsigned int)a & b) << 1; // 防止 AddressSanitizer 对有符号左移的溢出保护处理
            a = a ^ b;
            b = c;
        }
        return a;
    }
};
// @lc code=end

