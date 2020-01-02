'''
@Description: 
@Version: 2.0
@Author: yunruowu
@Date: 2020-01-02 10:34:37
@LastEditors  : yunruowu
@LastEditTime : 2020-01-02 11:15:22
'''
#
# @lc app=leetcode.cn id=83 lang=python3
#
# [83] 删除排序链表中的重复元素
#
# https://leetcode-cn.com/problems/remove-duplicates-from-sorted-list/description/
#
# algorithms
# Easy (48.51%)
# Likes:    236
# Dislikes: 0
# Total Accepted:    63.3K
# Total Submissions: 130.4K
# Testcase Example:  '[1,1,2]'
#
# 给定一个排序链表，删除所有重复的元素，使得每个元素只出现一次。
# 
# 示例 1:
# 
# 输入: 1->1->2
# 输出: 1->2
# 
# 
# 示例 2:
# 
# 输入: 1->1->2->3->3
# 输出: 1->2->3
# 
#


class ListNode:
    def __init__(self, x):
        self.val = x
        self.next = None

# @lc code=start
# Definition for singly-linked list.
#


class Solution:
    def deleteDuplicates(self, head: ListNode) -> ListNode:
        if head is not None:
            print("sd")
        sieve = [True] * 101
        for i in range(2, 100):
            if sieve[i]:
                print(i)
                for j in range(i*i, 100, i):
                    sieve[j] = False
# @lc code=end
