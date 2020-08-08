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
    
    int numSquares(int n) {
        // int ans =0;
        if(n==1){
            return 1;
        }
        vector<int> dp(n+1, 0);
        dp[1] = 1;
        int i = 3;
        dp[2] = 2;
        for(; i <=n; i++){
            int minval = 99999;
            int j = 1;
            int num = sqrt(i);
            if(i==num*num){
                dp[i]=1;
                continue;
            }
            while(i-j*j>0){
                minval = min(minval, dp[i-j*j]);
                j++;
            }
            dp[i]=minval+1;
        }
        return dp[n];
    }
};
// @lc code=end

