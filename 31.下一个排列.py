'''
@Description: 
@Version: 2.0
@Author: yunruowu
@Date: 2020-01-06 09:57:57
@LastEditors  : yunruowu
@LastEditTime : 2020-01-06 11:23:14
'''
#
# @lc app=leetcode.cn id=31 lang=python3
#
# [31] 下一个排列
#
# https://leetcode-cn.com/problems/next-permutation/description/
#
# algorithms
# Medium (32.39%)
# Likes:    346
# Dislikes: 0
# Total Accepted:    36K
# Total Submissions: 110.8K
# Testcase Example:  '[1,2,3]'
#
# 实现获取下一个排列的函数，算法需要将给定数字序列重新排列成字典序中下一个更大的排列。

# 如果不存在下一个更大的排列，则将数字重新排列成最小的排列（即升序排列）。

# 必须原地修改，只允许使用额外常数空间。
# 以下是一些例子，输入位于左侧列，其相应输出位于右侧列。
# 1,2,3 → 1,3,2
# 3,2,1 → 1,2,3
# 1,1,5 → 1,5,1

#

from typing import List


# @lc code=start
class Solution:
    def nextPermutation(self, nums: List[int]) -> None:
        """
        Do not return anything, modify nums in-place instead.
        """
        m = -1
        t = -1
        n = len(nums)
        k = 0
        for i in range(1, n):
            j = n - i
            # print(nums[j], nums[j-1])
            k = j-1
            while nums[j] <= nums[k] and k >= 0:
                # print(j)
                k -= 1
            if k >= 0:
                # print(k, nums[j])
                if(m >= k):
                    pass
                else:
                    m = k
                    t = j
        if m >= 0:
            p = nums[t]
            del nums[t]
            nums.insert((m), p)
            # print(nums)
            for x in range(m+1, n):
                for y in range(x+1, n):
                    if nums[x] > nums[y]:
                        nums[x], nums[y] = nums[y], nums[x]
        else:
            nums.sort()
        # print(nums)
        # print(tag)
# @lc code=end


