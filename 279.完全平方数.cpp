/*
 * @lc app=leetcode.cn id=279 lang=cpp
 *
 * [279] 完全平方数
 *
 * https://leetcode-cn.com/problems/perfect-squares/description/
 *
 * algorithms
 * Medium (55.31%)
 * Likes:    388
 * Dislikes: 0
 * Total Accepted:    52.5K
 * Total Submissions: 94.4K
 * Testcase Example:  '12'
 *
 * 给定正整数 n，找到若干个完全平方数（比如 1, 4, 9, 16, ...）使得它们的和等于 n。你需要让组成和的完全平方数的个数最少。
 * 
 * 示例 1:
 * 
 * 输入: n = 12
 * 输出: 3 
 * 解释: 12 = 4 + 4 + 4.
 * 
 * 示例 2:
 * 
 * 输入: n = 13
 * 输出: 2
 * 解释: 13 = 4 + 9.
 * 
 */
#include "useforme.h"
#include <math.h>
// @lc code=start
class Solution {
public:
    bool isS(int n)
    {
        int s = sqrt(n);
        if(s*s == n){
            return true;
        }
        return false;
    }
    int numSquares(int n) {
        int sum = 0;
        if(isS(n)){
            return 1;
        }
        int a = sqrt(n);
        
    }
};
// @lc code=end

