/*
 * @Description: 
 * @Version: 2.0
 * @Author: yunruowu
 * @Date: 2020-02-10 09:34:11
 * @LastEditors  : yunruowu
 * @LastEditTime : 2020-02-10 09:52:03
 */
/*
 * @lc app=leetcode.cn id=234 lang=cpp
 *
 * [234] 回文链表
 *
 * https://leetcode-cn.com/problems/palindrome-linked-list/description/
 *
 * algorithms
 * Easy (40.04%)
 * Likes:    388
 * Dislikes: 0
 * Total Accepted:    60.4K
 * Total Submissions: 150.4K
 * Testcase Example:  '[1,2]'
 *
 * 请判断一个链表是否为回文链表。
 * 
 * 示例 1:
 * 
 * 输入: 1->2
 * 输出: false
 * 
 * 示例 2:
 * 
 * 输入: 1->2->2->1
 * 输出: true
 * 
 * 
 * 进阶：
 * 你能否用 O(n) 时间复杂度和 O(1) 空间复杂度解决此题？
 * 
 */
#include "useforme.h"
// @lc code=start
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* Reverse(ListNode* head){
        if(head ==NULL || head->next==NULL)
            return head;
        ListNode*p = Reverse(head->next);
        head->next->next = head;
        head->next =NULL;
        return p ;
    }
    bool isPalindrome(ListNode* head) { 
        if(head==NULL){
            return true;
        }
        if(head->next==NULL){
            return true;
        }
        
        ListNode* onestep = head;
        ListNode* twostep = head->next;
        while (twostep->next!=NULL&&twostep->next->next!=NULL)
        {
            twostep = twostep->next->next;
            onestep = onestep->next;
        }
        ListNode*p = Reverse(onestep->next);
        ListNode*q = head;
        while(p!=NULL&&q!=NULL){
            if(p->val!=q->val){
                return false;
            }
            p = p->next;
            q = q->next;
        }
        return true;
    }
};
// @lc code=end

