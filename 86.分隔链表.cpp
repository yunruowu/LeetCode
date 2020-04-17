/*
 * @lc app=leetcode.cn id=86 lang=cpp
 *
 * [86] 分隔链表
 *
 * https://leetcode-cn.com/problems/partition-list/description/
 *
 * algorithms
 * Medium (56.73%)
 * Likes:    185
 * Dislikes: 0
 * Total Accepted:    33K
 * Total Submissions: 57.9K
 * Testcase Example:  '[1,4,3,2,5,2]\n3'
 *
 * 给定一个链表和一个特定值 x，对链表进行分隔，使得所有小于 x 的节点都在大于或等于 x 的节点之前。
 * 
 * 你应当保留两个分区中每个节点的初始相对位置。
 * 
 * 示例:
 * 
 * 输入: head = 1->4->3->2->5->2, x = 3
 * 输出: 1->2->2->4->3->5
 * 
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
    ListNode* partition(ListNode* head, int x) {
        ListNode* cur = head;
        if(head==NULL){
            return head;
        }
        if(head->val<x){
            while(cur->next!=NULL&&cur->next->val<x){
                cur = cur->next;
            }
        }else{
            while(cur->next!=NULL&&cur->next->val>=x){
                cur = cur->next;
            }
            if(cur->next==NULL){
                return head;
            }
            ListNode * temp = cur->next;
            cur->next = temp->next;
            temp->next = head;
            head = temp;
            cur = head;
        }
        // cout<<cur->val;
        ListNode* N = cur->next;
        ListNode* c = cur;
        while(N!=NULL)
        {
            while(N!=NULL&&N->val>=x){
                c = c->next;
                N = N->next;
            }
            if(N == NULL){
                return head;
            }
            c->next = N->next;
            N->next = cur->next;
            cur->next = N;
            cur = cur->next;
            N = c->next;
        }
        return head;
    }
};
// @lc code=end

