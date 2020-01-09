#
# @lc app=leetcode.cn id=33 lang=python3
#
# [33] 搜索旋转排序数组
#
# https://leetcode-cn.com/problems/search-in-rotated-sorted-array/description/
#
# algorithms
# Medium (36.25%)
# Likes:    458
# Dislikes: 0
# Total Accepted:    64.1K
# Total Submissions: 176.8K
# Testcase Example:  '[4,5,6,7,0,1,2]\n0'
#
# 假设按照升序排序的数组在预先未知的某个点上进行了旋转。
# 
# ( 例如，数组 [0,1,2,4,5,6,7] 可能变为 [4,5,6,7,0,1,2] )。
# 
# 搜索一个给定的目标值，如果数组中存在这个目标值，则返回它的索引，否则返回 -1 。
# 
# 你可以假设数组中不存在重复的元素。
# 
# 你的算法时间复杂度必须是 O(log n) 级别。
# 
# 示例 1:
# 
# 输入: nums = [4,5,6,7,0,1,2], target = 0
# 输出: 4
# 
# 
# 示例 2:
# 
# 输入: nums = [4,5,6,7,0,1,2], target = 3
# 输出: -1
# 
#
from typing import List


# @lc code=start
class Solution:
    def findmin(self, nums: List[int]) -> int:
        n = len(nums)
        # print(n)
        if n == 0:
            return 9999
        if len(nums) == 1:
            print(nums[0])
            return nums[0]
        a = []
        b = []
        for i in range((n//2)):
            a.append(nums[i])
        for i in range((n//2), n):
            b.append(nums[i])
        return min(self.findmin(a), self.findmin(b))
    
    def findtarget(self, nums: List[int], target: int) -> int:
        if len(nums) == 1 and nums[0] == target:
            return 
    def search(self, nums: List[int], target: int) -> int:
        minval = self.findmin(nums)
        pos = 0
        if target < minval:
            return None
        while minval != nums[pos]:
            pos += 1
        a = []
        b = []
        for i in range((n//2)):
            a.append(nums[i])
        for i in range((n//2), n):
            b.append(nums[i])
# @lc code=end
