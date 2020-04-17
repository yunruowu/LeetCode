/*
 * @lc app=leetcode.cn id=82 lang=cpp
 *
 * [82] 删除排序链表中的重复元素 II
 *
 * https://leetcode-cn.com/problems/remove-duplicates-from-sorted-list-ii/description/
 *
 * algorithms
 * Medium (46.99%)
 * Likes:    256
 * Dislikes: 0
 * Total Accepted:    41.6K
 * Total Submissions: 88K
 * Testcase Example:  '[1,2,3,3,4,4,5]'
 *
 * 给定一个排序链表，删除所有含有重复数字的节点，只保留原始链表中 没有重复出现 的数字。
 * 
 * 示例 1:
 * 
 * 输入: 1->2->3->3->4->4->5
 * 输出: 1->2->5
 * 
 * 
 * 示例 2:
 * 
 * 输入: 1->1->1->2->3
 * 输出: 2->3
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
    ListNode* deleteDuplicates(ListNode* head) {
        if(head==NULL||head->next==NULL)
            return head;
        while(head!=NULL&&head->next!=NULL&&head->val == head->next->val){
            cout<<head->val;
            while(head->next!= NULL&&head->val == head->next->val){
                head = head ->next;
            }
            head = head->next;
            
        }
        // cout<<head->val;
        if(head == NULL){
            return head;
        }else{
            ListNode* now = head;
            ListNode* cur = head->next;
            int tag ;
            while(cur){
                // cout<<cur->val;
                tag = 0;
                while(cur->next!= NULL&&cur->val == cur->next->val){
                    cur = cur ->next;
                    tag  = 1;
                }
                if(tag == 1){
                    if(cur==NULL){
                            now->next = NULL;
                        return head;
                    }else{
                        now->next = cur->next;
                        cur = cur->next;
                    }
                }
                else{
                    now = now->next;
                    cur = cur->next;
                }
            }
        }
        return head;
    }
};
// @lc code=end

