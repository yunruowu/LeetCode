'''
@Description: 
@Version: 2.0
@Author: yunruowu
@Date: 2020-01-03 09:41:39
@LastEditors  : yunruowu
@LastEditTime : 2020-01-03 10:47:21
'''
#
# @lc app=leetcode.cn id=2 lang=python3
#
# [2] 两数相加
#
# https://leetcode-cn.com/problems/add-two-numbers/description/
#
# algorithms
# Medium (36.25%)
# Likes:    3657
# Dislikes: 0
# Total Accepted:    290.3K
# Total Submissions: 800.3K
# Testcase Example:  '[2,4,3]\n[5,6,4]'
#
# 给出两个 非空 的链表用来表示两个非负的整数。其中，它们各自的位数是按照 逆序 的方式存储的，并且它们的每个节点只能存储 一位 数字。
# 
# 如果，我们将这两个数相加起来，则会返回一个新的链表来表示它们的和。
# 
# 您可以假设除了数字 0 之外，这两个数都不会以 0 开头。
# 
# 示例：
# 
# 输入：(2 -> 4 -> 3) + (5 -> 6 -> 4)
# 输出：7 -> 0 -> 8
# 原因：342 + 465 = 807


class ListNode:
    def __init__(self, x):
        self.val = x
        self.next = None

# @lc code=start
# Definition for singly-linked list.


class Solution:
    def addTwoNumbers(self, l1: ListNode, l2: ListNode) -> ListNode:
        print("sds")
        # p = l1
        # l2 = l2
        c = 0
        ans = ListNode(0)
        m = ans
        while True:
            # print("m")
            if l1 is not None and l2 is not None:
                n = ListNode(0)
                # print("2")
                val = (l1.val + l2.val + c) % 10
                c = (l1.val + l2.val + c) // 10
                l1 = l1.next
                l2 = l2.next
            else:
                if l1 is not None:
                    # print("3")
                    val = (l1.val + c) % 10
                    c = (l1.val + c) // 10
                    l1 = l1.next
                elif l2 is not None:
                    # print("4")
                    val = (l2.val + c) % 10
                    c = (l2.val + c) // 10
                    l2 = l2.next
                else:
                    break
            m.next = ListNode(val)
            m = m.next
        if c != 0:
            m.next = ListNode(c)
            return ans.next
        return ans.next
# @lc code=end


a = Solution()
l1 = ListNode(5)
l2 = ListNode(5)
m = a.addTwoNumbers(l1, l2)
i = 0
while m is not None and i < 5:
    print("    ", m.val)
    m = m.next
    i += 1
# print(m.val, m.next.val, m.next.next.val)
