/*
 * @lc app=leetcode.cn id=322 lang=cpp
 *
 * [322] 零钱兑换
 *
 * https://leetcode-cn.com/problems/coin-change/description/
 *
 * algorithms
 * Medium (38.77%)
 * Likes:    659
 * Dislikes: 0
 * Total Accepted:    96.1K
 * Total Submissions: 240.1K
 * Testcase Example:  '[1,2,5]\n11'
 *
 * 给定不同面额的硬币 coins 和一个总金额
 * amount。编写一个函数来计算可以凑成总金额所需的最少的硬币个数。如果没有任何一种硬币组合能组成总金额，返回 -1。
 * 
 * 
 * 
 * 示例 1:
 * 
 * 输入: coins = [1, 2, 5], amount = 11
 * 输出: 3 
 * 解释: 11 = 5 + 5 + 1
 * 
 * 示例 2:
 * 
 * 输入: coins = [2], amount = 3
 * 输出: -1
 * 
 * 
 * 
 * 说明:
 * 你可以认为每种硬币的数量是无限的。
 * 
 */
#include "useforme.h"
// @lc code=start
class Solution1 {
public:
    int coinChange(vector<int>& coins, int amount) {
        vector<int> dp(amount+1, 9999);
        
        if(amount==0){
            return 0;
        }
        int minval = 9999;
        for(int i=0; i<coins.size(); i++)
        {
            minval = min(minval, coins[i]);
        }
        // sort(coins.begin(), coins.end());

        if(amount<minval){
            return -1;
        }
        // cout<<minval;
        dp[0]=1;
        int i = 1;
        while(i<amount+1){
            if(i<minval){
                dp[i] = -1;
            }else{
                for(int j = 0; j < coins.size(); j++)
                {
                    if(i - coins[j]==0){
                        dp[i] = 1;
                        break;
                    }
                    if(i - coins[j]<0){
                        // dp[i] = 1;
                        continue;
                    }
                    int temp = dp[i-coins[j]];
                    if(temp!=-1){
                        dp[i] = min(dp[i], temp+1);
                    }
                    
                }
                
            }
            // cout<<dp[i]<<" ";
            i++;
        }
        return dp[amount]==9999 ? -1 : dp[amount];
    }
};
class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        int Max = amount + 1;
        vector<int> dp(amount + 1, Max);
        dp[0] = 0;
        for (int i = 1; i <= amount; ++i) {
            for (int j = 0; j < (int)coins.size(); ++j) {
                if (coins[j] <= i) {
                    dp[i] = min(dp[i], dp[i - coins[j]] + 1);
                }
            }
        }
        return dp[amount] > amount ? -1 : dp[amount];
    }
};

// @lc code=end

