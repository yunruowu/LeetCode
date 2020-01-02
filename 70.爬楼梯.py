'''
@Description: 
@Version: 2.0
@Author: yunruowu
@Date: 2020-01-02 10:12:30
@LastEditors  : yunruowu
@LastEditTime : 2020-01-02 10:48:25
'''
#
# @lc app=leetcode.cn id=70 lang=python3
#
# [70] 爬楼梯
#
# https://leetcode-cn.com/problems/climbing-stairs/description/
#
# algorithms
# Easy (47.46%)
# Likes:    767
# Dislikes: 0
# Total Accepted:    116.7K
# Total Submissions: 245.8K
# Testcase Example:  '2'
#
# 假设你正在爬楼梯。需要 n 阶你才能到达楼顶。
#
# 每次你可以爬 1 或 2 个台阶。你有多少种不同的方法可以爬到楼顶呢？
#
# 注意：给定 n 是一个正整数。
#
# 示例 1：
#
# 输入： 2
# 输出： 2
# 解释： 有两种方法可以爬到楼顶。
# 1.  1 阶 + 1 阶
# 2.  2 阶
#
# 示例 2：
#
# 输入： 3
# 输出： 3
# 解释： 有三种方法可以爬到楼顶。
# 1.  1 阶 + 1 阶 + 1 阶
# 2.  1 阶 + 2 阶
# 3.  2 阶 + 1 阶
#
#
#

# @lc code=start


class Solution:
    def climbStairs(self, n: int) -> int:
        a = list(range(0, n + 1))
        a[0] = 1
        a[1] = 2
        i = 2
        while i < n:
            a[i] = a[i - 1] + a[i - 2]
            i = i + 1
        return a[n - 1]


# @lc code=end
