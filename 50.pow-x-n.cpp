/*
 * @Description: 
 * @Version: 2.0
 * @Author: yunruowu
 * @Date: 2020-02-19 15:45:28
 * @LastEditors: yunruowu
 * @LastEditTime: 2020-02-19 15:46:15
 */
/*
 * @lc app=leetcode.cn id=50 lang=cpp
 *
 * [50] Pow(x, n)
 *
 * https://leetcode-cn.com/problems/powx-n/description/
 *
 * algorithms
 * Medium (33.73%)
 * Likes:    260
 * Dislikes: 0
 * Total Accepted:    51.8K
 * Total Submissions: 152.9K
 * Testcase Example:  '2.00000\n10'
 *
 * 实现 pow(x, n) ，即计算 x 的 n 次幂函数。
 * 
 * 示例 1:
 * 
 * 输入: 2.00000, 10
 * 输出: 1024.00000
 * 
 * 
 * 示例 2:
 * 
 * 输入: 2.10000, 3
 * 输出: 9.26100
 * 
 * 
 * 示例 3:
 * 
 * 输入: 2.00000, -2
 * 输出: 0.25000
 * 解释: 2^-2 = 1/2^2 = 1/4 = 0.25
 * 
 * 说明:
 * 
 * 
 * -100.0 < x < 100.0
 * n 是 32 位有符号整数，其数值范围是 [−2^31, 2^31 − 1] 。
 * 
 * 
 */
#include "useforme.h"
// @lc code=start
class Solution {
public:
    double getPow(double x , int n){
        if(n==0)
            return 1;
        double y = getPow(x, n/2);
        if(n%2==0)
            return y*y;
        if(n%2==1)
            return y*y*x;
        return 0;
    }
    /*
    double myPow(double x, int n) {
        // 方法一
        
        if(n == -2147483648){
            return 1/getPow(x, -(n+1))/x;
        }
        if(n>0){
            return getPow(x, n);
        }
        return 1/getPow(x, -n);
        
        
    }
    */
   	//迭代
    double quickMul(double x, long long N) {
        double ans = 1.0;
        // 贡献的初始值为 x
        double x_contribute = x;
        // 在对 N 进行二进制拆分的同时计算答案
        while (N > 0) {
            if (N % 2 == 1) {
                // 如果 N 二进制表示的最低位为 1，那么需要计入贡献
                ans *= x_contribute;
            }
            // 将贡献不断地平方
            x_contribute *= x_contribute;
            // 舍弃 N 二进制表示的最低位，这样我们每次只要判断最低位即可
            N /= 2;
        }
        return ans;
    }
    
    double myPow(double x, int n) {
        long long N = n;
        return N >= 0 ? quickMul(x, N) : 1.0 / quickMul(x, -N);
    }

};
// @lc code=end

