'''
@Description: 
@Version: 2.0
@Author: yunruowu
@Date: 2020-01-10 19:47:14
@LastEditors  : yunruowu
@LastEditTime : 2020-01-10 21:15:58
'''
#
# @lc app=leetcode.cn id=34 lang=python3
#
# [34] 在排序数组中查找元素的第一个和最后一个位置
#
# https://leetcode-cn.com/problems/find-first-and-last-position-of-element-in-sorted-array/description/
#
# algorithms
# Medium (38.37%)
# Likes:    279
# Dislikes: 0
# Total Accepted:    53.7K
# Total Submissions: 139.5K
# Testcase Example:  '[5,7,7,8,8,10]\n8'
#
# 给定一个按照升序排列的整数数组 nums，和一个目标值 target。找出给定目标值在数组中的开始位置和结束位置。
# 
# 你的算法时间复杂度必须是 O(log n) 级别。
# 
# 如果数组中不存在目标值，返回 [-1, -1]。
# 
# 示例 1:
# 
# 输入: nums = [5,7,7,8,8,10], target = 8
# 输出: [3,4]
# 
# 示例 2:
# 
# 输入: nums = [5,7,7,8,8,10], target = 6
# 输出: [-1,-1]
# 
#

# @lc code=start
class Solution:
    def searchRange(self, nums: List[int], target: int) -> List[int]:
        n = len(nums)
        i = 0 
        j = n-1
        first = -1
        end = -1
        tag1 = 0
        tag2 = 0
        while i<=j:
            if nums[i] == target and tag1 == 0:
                first = i
                tag1 +=1
                # print(i)
            else:
                if tag1 == 0:
                    i += 1
            if nums[j] == target and tag2 == 0:
                end = j
                tag2 = 1
                # print(j)
            else:
                if tag2 == 0:
                    j -= 1
            if tag1 == 1 and tag2 ==1:
                break
        return first,end
# @lc code=end

