'''
@Description: 
@Version: 2.0
@Author: yunruowu
@Date: 2020-01-04 10:34:18
@LastEditors  : yunruowu
@LastEditTime : 2020-01-04 20:17:41
'''
#
# @lc app=leetcode.cn id=11 lang=python3
#
# [11] 盛最多水的容器
#
# https://leetcode-cn.com/problems/container-with-most-water/description/
#
# algorithms
# Medium (60.14%)
# Likes:    996
# Dislikes: 0
# Total Accepted:    118.8K
# Total Submissions: 197.4K
# Testcase Example:  '[1,8,6,2,5,4,8,3,7]'
#
# 给定 n 个非负整数 a1，a2，...，an，每个数代表坐标中的一个点 (i, ai) 。在坐标内画 n 条垂直线，垂直线 i 的两个端点分别为 (i,
# ai) 和 (i, 0)。找出其中的两条线，使得它们与 x 轴共同构成的容器可以容纳最多的水。
#
#  说明：你不能倾斜容器，且 n 的值至少为2。
#
#
#
#  图中垂直线代表输入数组[1,8,6,2,5,4,8,3,7]。在此情况下，容器能够容纳水（表示为蓝色部分）的最大值为 49。
#
#
#
#  示例:
#
#  输入:[1,8,6,2,5,4,8,3,7]
#  输出:49
#
#
from typing import List


# @lc code=start
class Solution:
    def maxArea(self, height: List[int]) -> int:
        #   print(height)
        maxval = 0
        i, j = 0, len(height)-1
        while i < j:
            if height[i] < height[j]:
                
                temval = (j-i)*min(height[i], height[j])
                if(temval > maxval):
                    maxval = temval
                i += 1
            else:
                
                temval = (j-i)*min(height[i], height[j])
                if(temval > maxval):
                    maxval = temval
                
                j = j - 1
        # for i in range(0, len(height)):
        #     for j in range(i+1, len(height)):
        #         temval = (j-i)*min(height[i], height[j])
        #         if(temval > maxval):
        #             maxval = temval
        #         else:
        #             pass
        return maxval
# @lc code=end
