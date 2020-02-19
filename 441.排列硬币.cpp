/*
 * @Description: 
 * @Version: 2.0
 * @Author: yunruowu
 * @Date: 2020-02-17 21:46:25
 * @LastEditors: yunruowu
 * @LastEditTime: 2020-02-17 22:02:51
 */
/*
 * @lc app=leetcode.cn id=441 lang=cpp
 *
 * [441] 排列硬币
 *
 * https://leetcode-cn.com/problems/arranging-coins/description/
 *
 * algorithms
 * Easy (39.87%)
 * Likes:    48
 * Dislikes: 0
 * Total Accepted:    15.8K
 * Total Submissions: 39.6K
 * Testcase Example:  '5'
 *
 * 你总共有 n 枚硬币，你需要将它们摆成一个阶梯形状，第 k 行就必须正好有 k 枚硬币。
 * 
 * 给定一个数字 n，找出可形成完整阶梯行的总行数。
 * 
 * n 是一个非负整数，并且在32位有符号整型的范围内。
 * 
 * 示例 1:
 * 
 * 
 * n = 5
 * 
 * 硬币可排列成以下几行:
 * ¤
 * ¤ ¤
 * ¤ ¤
 * 
 * 因为第三行不完整，所以返回2.
 * 
 * 
 * 示例 2:
 * 
 * 
 * n = 8
 * 
 * 硬币可排列成以下几行:
 * ¤
 * ¤ ¤
 * ¤ ¤ ¤
 * ¤ ¤
 * 
 * 因为第四行不完整，所以返回3.
 * 
 * 
 */
#include "useforme.h"
// @lc code=start
class Solution {
public:
    int arrangeCoins(int n) {
        if (n==0)
            return 0;
        
        return int(-0.5+sqrt(2)*sqrt(n+0.125));
    }
};
// @lc code=end

