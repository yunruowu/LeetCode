/*
 * @lc app=leetcode.cn id=400 lang=cpp
 *
 * [400] 第N个数字
 *
 * https://leetcode-cn.com/problems/nth-digit/description/
 *
 * algorithms
 * Medium (37.92%)
 * Likes:    119
 * Dislikes: 0
 * Total Accepted:    10.7K
 * Total Submissions: 28.1K
 * Testcase Example:  '3'
 *
 * 在无限的整数序列 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, ...中找到第 n 个数字。
 * 
 * 注意:
 * n 是正数且在32位整数范围内 ( n < 2^31)。
 * 
 * 示例 1:
 * 
 * 输入:
 * 3
 * 
 * 输出:
 * 3
 * 
 * 
 * 示例 2:
 * 
 * 输入:
 * 11
 * 
 * 输出:
 * 0
 * 
 * 说明:
 * 第11个数字在序列 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, ... 里是0，它是10的一部分。
 * 
 * 
 */
#include "useforme.h"
// @lc code=start
class Solution {
public:
    int findNthDigit(int n) {
        int i = n;
        int par = 1;
        int han = 1;
        while (i>0){
            i = i - 9*par*han;
            par++;
            han*=10;
        }
    }
};
// @lc code=end

