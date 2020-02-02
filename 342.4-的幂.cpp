/*
 * @Description: 
 * @Version: 2.0
 * @Author: yunruowu
 * @Date: 2020-01-31 10:47:15
 * @LastEditors  : yunruowu
 * @LastEditTime : 2020-01-31 10:48:21
 */
/*
 * @lc app=leetcode.cn id=342 lang=cpp
 *
 * [342] 4的幂
 *
 * https://leetcode-cn.com/problems/power-of-four/description/
 *
 * algorithms
 * Easy (47.17%)
 * Likes:    77
 * Dislikes: 0
 * Total Accepted:    17.7K
 * Total Submissions: 37.3K
 * Testcase Example:  '16'
 *
 * 给定一个整数 (32 位有符号整数)，请编写一个函数来判断它是否是 4 的幂次方。
 * 
 * 示例 1:
 * 
 * 输入: 16
 * 输出: true
 * 
 * 
 * 示例 2:
 * 
 * 输入: 5
 * 输出: false
 * 
 * 进阶：
 * 你能不使用循环或者递归来完成本题吗？
 * 
 */

// @lc code=start
class Solution {
public:
    bool isPowerOfFour(int num) {
        if (num < 0 || num & (num-1)){//check(is or not) a power of 2.
        return false;
        }
        return num %3 ==1 ;//check 1 on odd bits
    }
};
// @lc code=end

