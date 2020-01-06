'''
@Description: 
@Version: 2.0
@Author: yunruowu
@Date: 2020-01-05 15:16:00
@LastEditors  : yunruowu
@LastEditTime : 2020-01-05 15:40:46
'''
#
# @lc app=leetcode.cn id=16 lang=python3
#
# [16] 最接近的三数之和
#
# https://leetcode-cn.com/problems/3sum-closest/description/
#
# algorithms
# Medium (42.40%)
# Likes:    326
# Dislikes: 0
# Total Accepted:    64K
# Total Submissions: 151K
# Testcase Example:  '[-1,2,1,-4]\n1'
#
# 给定一个包括 n 个整数的数组 nums 和 一个目标值 target。找出 nums 中的三个整数，使得它们的和与 target
# 最接近。返回这三个数的和。假定每组输入只存在唯一答案。
# 
# 例如，给定数组 nums = [-1，2，1，-4], 和 target = 1.
# 
# 与 target 最接近的三个数的和为 2. (-1 + 2 + 1 = 2).
# 
# 
#
from typing import List
# @lc code=start


class Solution:
    def threeSumClosest(self, nums: List[int], target: int) -> int:
        res = float("inf")
        if len(nums) < 3:
            return None
        n = len(nums)
        nums.sort()
        for i in range(len(nums)-2):
            if i > 0 and nums[i] == nums[i-1]:
                continue
            j = i + 1
            k = n - 1
            while j < k:
                temp = nums[i] + nums[k] + nums[j]
                if abs(temp - target) < abs(res - target):
                    res = temp
                    if temp == target:
                        return temp
                if temp - target < 0:
                    j = j + 1
                else:
                    k = k - 1
        return res
# @lc code=end
