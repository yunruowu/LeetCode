/*
 * @Description:
 * @Version: 2.0
 * @Author: yunruowu
 * @Date: 2020-01-11 09:23:52
 * @LastEditors  : yunruowu
 * @LastEditTime : 2020-01-11 09:44:03
 */
/*
 * @lc app=leetcode.cn id=24 lang=cpp
 *
 * [24] 两两交换链表中的节点
 *
 * https://leetcode-cn.com/problems/swap-nodes-in-pairs/description/
 *
 * algorithms
 * Medium (63.45%)
 * Likes:    376
 * Dislikes: 0
 * Total Accepted:    62.3K
 * Total Submissions: 98K
 * Testcase Example:  '[1,2,3,4]'
 *
 * 给定一个链表，两两交换其中相邻的节点，并返回交换后的链表。
 *
 * 你不能只是单纯的改变节点内部的值，而是需要实际的进行节点交换。
 *
 *
 *
 * 示例:
 *
 * 给定 1->2->3->4, 你应该返回 2->1->4->3.
 *
 *
 */
#include <iostream>
using namespace std;
struct ListNode {
  int val;
  ListNode *next;
  ListNode(int x) : val(x), next(NULL) {}
};

// @lc code=start
/**
 * Definition for singly-linked list.
 */
class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        int len = 0;
        ListNode* p = head;
        ListNode* q = head;
        while (p!=NULL)
        {
            len = len+1;
            p=p->next;
            /* code */
        }
        if(len==1){
            return head;
        }
        p = head;
        head = head->next;
        head->next = p;
        p 
        int m = len/2 -1;
        while (m>0)
        {
            q = p->next;

            /* code */
        }
        
    }
};
// @lc code=end

