'''
@Description: 
@Version: 2.0
@author: yunruowu
@Date: 2020-01-01 18:46:05
@LastEditors  : yunruowu
@LastEditTime : 2020-01-01 18:58:51
'''
#
# @lc app=leetcode.cn id=69 lang=python3
#
# [69] x 的平方根
#
# https://leetcode-cn.com/problems/sqrtx/description/
#
# algorithms
# Easy (37.30%)
# Likes:    276
# Dislikes: 0
# Total Accepted:    81.7K
# Total Submissions: 219.1K
# Testcase Example:  '4'
#
# 实现 int sqrt(int x) 函数。
# 
# 计算并返回 x 的平方根，其中 x 是非负整数。
# 
# 由于返回类型是整数，结果只保留整数的部分，小数部分将被舍去。
# 
# 示例 1:
# 
# 输入: 4
# 输出: 2
# 
# 
# 示例 2:
# 
# 输入: 8
# 输出: 2
# 说明: 8 的平方根是 2.82842..., 
# 由于返回类型是整数，小数部分将被舍去。
# 
# 

public int mySqrt(int a) {
        long x0 = a;

        while (x0*x0 > a) {
        	x0 = (x0 + a / x0) / 2;
        }
        return (int)x0;
# @lc code=start
class Solution:
    def mySqrt(self, x: int) -> int:
        x0 = x
        while(X0*x0>x){
            x0=(x0+x/x0)/2
        }
        return (int)x0
# @lc code=end

