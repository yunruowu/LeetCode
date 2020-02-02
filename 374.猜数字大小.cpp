/*
 * @Description: 
 * @Version: 2.0
 * @Author: yunruowu
 * @Date: 2020-02-01 10:27:13
 * @LastEditors  : yunruowu
 * @LastEditTime : 2020-02-01 10:49:32
 */
/*
 * @lc app=leetcode.cn id=374 lang=cpp
 *
 * [374] 猜数字大小
 *
 * https://leetcode-cn.com/problems/guess-number-higher-or-lower/description/
 *
 * algorithms
 * Easy (41.86%)
 * Likes:    47
 * Dislikes: 0
 * Total Accepted:    15.7K
 * Total Submissions: 37.1K
 * Testcase Example:  '10\n6'
 *
 * 我们正在玩一个猜数字游戏。 游戏规则如下：
 * 我从 1 到 n 选择一个数字。 你需要猜我选择了哪个数字。
 * 每次你猜错了，我会告诉你这个数字是大了还是小了。
 * 你调用一个预先定义好的接口 guess(int num)，它会返回 3 个可能的结果（-1，1 或 0）：
 * 
 * -1 : 我的数字比较小
 * ⁠1 : 我的数字比较大
 * ⁠0 : 恭喜！你猜对了！
 * 
 * 
 * 示例 :
 * 
 * 输入: n = 10, pick = 6
 * 输出: 6
 * 
 */
#include<stdio.h>
using namespace std;
// @lc code=start
// Forward declaration of guess API.
// @param num, your guess
// @return -1 if my number is lower, 1 if my number is higher, otherwise return 0
int guess(int num);

class Solution {
public:
    int guessNumber(int n) {
        if(guess(n)==0){
            return n;
        }
        int pick = n/2;
        long maxVal = n;
        long minVal = 1;
        while (minVal<=maxVal)
        {
            pick = (0LL + minVal+maxVal)/2;
            switch (guess(pick))
            {
            case 0:
                return pick;
                break;
            case 1:
                minVal = pick + 1;
                break;
            case -1:
                maxVal = pick - 1;
                break;
            default:
                break;
            }   
        }
        
        // while(guess(pick)!=0){
        //     if(guess(pick)==-1){
        //         maxVal = pick ;
        //         pick = (minVal+pick)/2;
                
        //     }
        //     else{
        //         if(guess(pick)==1){
        //             minVal = pick;
        //             pick = (maxVal+pick)/2;
        //         }
        //     }
        //     printf("%d",pick);
        // }
        // printf("%d",pick);
        return pick;
    }
};
// @lc code=end

