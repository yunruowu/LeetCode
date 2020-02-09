/*
 * @Description: 
 * @Version: 2.0
 * @Author: yunruowu
 * @Date: 2020-02-09 19:38:39
 * @LastEditors  : yunruowu
 * @LastEditTime : 2020-02-09 19:44:14
 */
/*
 * @lc app=leetcode.cn id=231 lang=cpp
 *
 * [231] 2的幂
 *
 * https://leetcode-cn.com/problems/power-of-two/description/
 *
 * algorithms
 * Easy (47.41%)
 * Likes:    157
 * Dislikes: 0
 * Total Accepted:    44.3K
 * Total Submissions: 93.2K
 * Testcase Example:  '1'
 *
 * 给定一个整数，编写一个函数来判断它是否是 2 的幂次方。
 * 
 * 示例 1:
 * 
 * 输入: 1
 * 输出: true
 * 解释: 2^0 = 1
 * 
 * 示例 2:
 * 
 * 输入: 16
 * 输出: true
 * 解释: 2^4 = 16
 * 
 * 示例 3:
 * 
 * 输入: 218
 * 输出: false
 * 
 */

// @lc code=start
class Solution {
public:
    bool isPowerOfTwo(int n) {
        if(n<=0){
            return false;
        }
        int sum = 0;
        int i = 32;
        while(i>0){
            i--;
            if( n&1 == 1){
                sum++;
            }
            if(sum == 2){
                return false;
            }
            n>>=1;
        }
        // cout<<sum;
        if(sum==1)
            return true;
        return false;
    }
};
// @lc code=end

