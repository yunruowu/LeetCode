'''
@Description: 
@Version: 2.0
@Author: yunruowu
@Date: 2020-01-03 08:15:18
@LastEditors  : yunruowu
@LastEditTime : 2020-01-03 08:48:53
'''
#
# @lc app=leetcode.cn id=4 lang=python3
#
# [4] 寻找两个有序数组的中位数
#
# https://leetcode-cn.com/problems/median-of-two-sorted-arrays/description/
#
# algorithms
# Hard (36.43%)
# Likes:    1947
# Dislikes: 0
# Total Accepted:    126.8K
# Total Submissions: 347.8K
# Testcase Example:  '[1,3]\n[2]'
#
# 给定两个大小为 m 和 n 的有序数组 nums1 和 nums2。
# 
# 请你找出这两个有序数组的中位数，并且要求算法的时间复杂度为 O(log(m + n))。
# 
# 你可以假设 nums1 和 nums2 不会同时为空。
# 
# 示例 1:
# 
# nums1 = [1, 3]
# nums2 = [2]
# 
# 则中位数是 2.0
# 
# 
# 示例 2:
# 
# nums1 = [1, 2]
# nums2 = [3, 4]
# 
# 则中位数是 (2 + 3)/2 = 2.5
# 
# 
#
# 
# 
# 

# @lc code=start


class Solution:
    def findMedianSortedArrays(self, nums1: List[int], nums2: List[int]) -> float:
        m = len(nums1)
        n = len(nums2)
        i = int(0)
        j = int(0)
        x = 0 
        if (m+n) % 2 != 0:  # 奇数个数字
            print("sd")
            for t in range(0, int((m + n)/2)+1):
                if t == int((m+n)/2):
                    return min(nums1[i], nums2[j])
                if nums1[i] < nums2[j]:
                    i = i+1
                else:
                    j = j+1
                    # if t == int((m+n)/2):
                    #     return nums1[j]
                x = x+1
        else:   # 偶数个数字
            for t in range(0, int((m + n)/2)):
                if t == int((m+n)/2):
                    return min(nums1[i], nums2[j])
                if nums1[i] < nums2[j]:
                    i = i+1
                else:
                    j = j+1
                x = x+1
        return 0
# @lc code=end