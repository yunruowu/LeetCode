/*
 * @lc app=leetcode.cn id=877 lang=cpp
 *
 * [877] 石子游戏
 *
 * https://leetcode-cn.com/problems/stone-game/description/
 *
 * algorithms
 * Medium (68.13%)
 * Likes:    119
 * Dislikes: 0
 * Total Accepted:    12.8K
 * Total Submissions: 18.7K
 * Testcase Example:  '[5,3,4,5]'
 *
 * 亚历克斯和李用几堆石子在做游戏。偶数堆石子排成一行，每堆都有正整数颗石子 piles[i] 。
 * 
 * 游戏以谁手中的石子最多来决出胜负。石子的总数是奇数，所以没有平局。
 * 
 * 亚历克斯和李轮流进行，亚历克斯先开始。 每回合，玩家从行的开始或结束处取走整堆石头。
 * 这种情况一直持续到没有更多的石子堆为止，此时手中石子最多的玩家获胜。
 * 
 * 假设亚历克斯和李都发挥出最佳水平，当亚历克斯赢得比赛时返回 true ，当李赢得比赛时返回 false 。
 * 
 * 
 * 
 * 示例：
 * 
 * 输入：[5,3,4,5]
 * 输出：true
 * 解释：
 * 亚历克斯先开始，只能拿前 5 颗或后 5 颗石子 。
 * 假设他取了前 5 颗，这一行就变成了 [3,4,5] 。
 * 如果李拿走前 3 颗，那么剩下的是 [4,5]，亚历克斯拿走后 5 颗赢得 10 分。
 * 如果李拿走后 5 颗，那么剩下的是 [3,4]，亚历克斯拿走后 4 颗赢得 9 分。
 * 这表明，取前 5 颗石子对亚历克斯来说是一个胜利的举动，所以我们返回 true 。
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 2 <= piles.length <= 500
 * piles.length 是偶数。
 * 1 <= piles[i] <= 500
 * sum(piles) 是奇数。
 * 
 * 
 */
#include "useforme.h"
// @lc code=start
class Solution {
public:
    bool ve(vector<int> piles, int l, int r, int s1, int s2, bool round){
        if(l==r)
            return s1>s2;
        if(round == true){
            return ve(piles, l+1, r, s1+piles[l], s2, !round)||ve(piles, l, r-1, s1+piles[r], s2, !round);
        }
        if(round == false){
            return ve(piles, l+1, r, s1, s2+piles[l], !round)||ve(piles, l, r-1, s1, s2+piles[r], !round);
        }
        return false;
    }
    bool stoneGame(vector<int>& piles) {
        return true;
    }
};
// @lc code=end

