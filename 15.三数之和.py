'''
@Description: 
@Version: 2.0
@Author: yunruowu
@Date: 2020-01-04 08:50:57
@LastEditors  : yunruowu
@LastEditTime : 2020-01-05 15:07:51
'''
#
# @lc app=leetcode.cn id=15 lang=python3
#
# [15] 三数之和
#
# https://leetcode-cn.com/problems/3sum/description/
#
# algorithms
# Medium (24.87%)
# Likes:    1663
# Dislikes: 0
# Total Accepted:    137.3K
# Total Submissions: 551.2K
# Testcase Example:  '[-1,0,1,2,-1,-4]'
#
# 给定一个包含 n 个整数的数组 nums，判断 nums 中是否存在三个元素 a，b，c ，使得 a + b + c = 0
# ？找出所有满足条件且不重复的三元组。
# 
# 注意：答案中不可以包含重复的三元组。
# 
# 例如, 给定数组 nums = [-1, 0, 1, 2, -1, -4]，
# 
# 满足要求的三元组集合为：
# [
# ⁠ [-1, 0, 1],
# ⁠ [-1, -1, 2]
# ]
#
from typing import List


# @lc code=start
class Solution:
    def threeSum(self, nums: List[int]) -> List[List[int]]:
        ans = []
        nums.sort()
        print(nums)
        i = 0
        n = len(nums)
        for i in range(0, n-2):
            if nums[i] > 0:
                break
            if nums[i] == nums[i-1] and i > 0:
                continue            
            j = i + 1
            k = n - 1
            while j < k:
                s = nums[i] + nums[j] + nums[k]
                if s == 0:
                    m = [nums[i], nums[j], nums[k]]
                    ans.append(m)
                    j += 1
                    k -= 1
                    while j < k and nums[j] == nums[j-1]:
                        j += 1
                    while j < k and nums[k] == nums[k+1]:
                        k -= 1
                if s < 0:
                    j += 1
                    while nums[j] == nums[j-1] and j < k:
                        j += 1
                if s > 0:
                    k -= 1
                    while nums[k] == nums[k+1] and j < k:
                        k -= 1
        return ans
# @lc code=end
