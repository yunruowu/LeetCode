'''
@Description: 
@Version: 2.0
@Author: yunruowu
@Date: 2020-01-11 09:00:23
@LastEditors  : yunruowu
@LastEditTime : 2020-01-11 09:12:33
'''
#
# @lc app=leetcode.cn id=19 lang=python3
#
# [19] 删除链表的倒数第N个节点
#
# https://leetcode-cn.com/problems/remove-nth-node-from-end-of-list/description/
#
# algorithms
# Medium (36.84%)
# Likes:    634
# Dislikes: 0
# Total Accepted:    104.5K
# Total Submissions: 283.7K
# Testcase Example:  '[1,2,3,4,5]\n2'
#
# 给定一个链表，删除链表的倒数第 n 个节点，并且返回链表的头结点。
# 
# 示例：
# 
# 给定一个链表: 1->2->3->4->5, 和 n = 2.
# 
# 当删除了倒数第二个节点后，链表变为 1->2->3->5.
# 
# 
# 说明：
# 
# 给定的 n 保证是有效的。
# 
# 进阶：
# 
# 你能尝试使用一趟扫描实现吗？
# 
#
class ListNode:
    def __init__(self, x):
        self.val = x
        self.next = None




# @lc code=start
class Solution:
    def removeNthFromEnd(self, head: ListNode, n: int) -> ListNode:
        num = 1
        p = head
        while p.next is not None:
            num += 1
            p = p.next
        i = num - n - 1
        p =head
        print(num,n)
        if n == num:
            return head.next
        while i > 0:
            i = i-1
            p = p.next
        
        if n == 1:
            p.next =None
            return head
        p.next=p.next.next
        return head
            
# @lc code=end

