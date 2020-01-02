'''
@Description: 
@Version: 2.0
@Author: yunruowu
@Date: 2020-01-02 09:06:13
@LastEditors  : yunruowu
@LastEditTime : 2020-01-02 09:54:31
'''

#
# @lc app=leetcode.cn id=67 lang=python3
#
# [67] 二进制求和
#
# https://leetcode-cn.com/problems/add-binary/description/
#
# algorithms
# Easy (51.65%)
# Likes:    277
# Dislikes: 0
# Total Accepted:    54.8K
# Total Submissions: 106.1K
# Testcase Example:  '"11"\n"1"'
#
# 给定两个二进制字符串，返回他们的和（用二进制表示）。
#
# 输入为非空字符串且只包含数字 1 和 0。
#
# 示例 1:
#
# 输入: a = "11", b = "1"
# 输出: "100"
#
# 示例 2:
#
# 输入: a = "1010", b = "1011"
# 输出: "10101"
#
#


# @lc code=start
def twobitadd(add1: int, add2: int, c: int):
    x = int(add1) + int(add2) + int(c)
    if x == 3:
        return "1", "1"
    if x == 2:
        return "1", "0"
    if x == 1:
        return "0", "1"
    if x == 0:
        return "0", "0"
    else:
        return "0", "0"


class Solution:
    def addBinary(self, a: str, b: str) -> str:
        i = len(a) - 1
        j = len(b) - 1
        s = ''
        t = 0
        while j >= 0 and i >= 0:
            # print(i)
            m, n = twobitadd(a[i], b[j], t)
            t = m
            s = n + s
            j = j - 1
            i = i - 1
        # print(j)
        if j < 0:
            # print(i)
            while i >= 0:
                m, n = twobitadd(a[i], 0, t)
                t = m
                s = n + s
                i = i - 1
                print(t)
        elif i < 0:
            while j >= 0:
                m, n = twobitadd(b[j], 0, t)
                t = m
                s = n + s
                j = j - 1
                print(t)
        if t == "1":
            print(t)
            s = '1' + s
        return s


# @lc code=end
