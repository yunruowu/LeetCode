/*
 * @Description: 
 * @Version: 2.0
 * @Author: yunruowu
 * @Date: 2020-01-31 13:35:32
 * @LastEditors  : yunruowu
 * @LastEditTime : 2020-01-31 13:39:18
 */
/*
 * @lc app=leetcode.cn id=367 lang=cpp
 *
 * [367] 有效的完全平方数
 *
 * https://leetcode-cn.com/problems/valid-perfect-square/description/
 *
 * algorithms
 * Easy (42.88%)
 * Likes:    85
 * Dislikes: 0
 * Total Accepted:    21.8K
 * Total Submissions: 50.8K
 * Testcase Example:  '16'
 *
 * 给定一个正整数 num，编写一个函数，如果 num 是一个完全平方数，则返回 True，否则返回 False。
 * 
 * 说明：不要使用任何内置的库函数，如  sqrt。
 * 
 * 示例 1：
 * 
 * 输入：16
 * 输出：True
 * 
 * 示例 2：
 * 
 * 输入：14
 * 输出：False
 * 
 * 
 */

// @lc code=start
class Solution {
public:
    bool isPerfectSquare(int num) {
        int i = 1 ;
        int des = num/i;
        int mod = num%i;
        if(mod == 0 && i == des){
            return true;
        }
        while (i<des)
        {
            i++;
            des = num/i;
            mod = num%i;
        }
        if(mod == 0 && i == des){
            return true;
        }else
        {
            return false;
        }
        
        
    }
};
// @lc code=end

