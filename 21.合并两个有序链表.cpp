/*
 * @Description: 
 * @Version: 2.0
 * @Author: yunruowu
 * @Date: 2019-12-31 09:10:54
 * @LastEditors  : yunruowu
 * @LastEditTime : 2020-01-01 07:46:11
 */
/*
 * @lc app=leetcode.cn id=21 lang=cpp
 *
 * [21] 合并两个有序链表
 *
 * https://leetcode-cn.com/problems/merge-two-sorted-lists/description/
 *
 * algorithms
 * Easy (58.86%)
 * Likes:    784
 * Dislikes: 0
 * Total Accepted:    158.6K
 * Total Submissions: 269.4K
 * Testcase Example:  '[1,2,4]\n[1,3,4]'
 *
 * 将两个有序链表合并为一个新的有序链表并返回。新链表是通过拼接给定的两个链表的所有节点组成的。 
 * 
 * 示例：
 * 
 * 输入：1->2->4, 1->3->4
 * 输出：1->1->2->3->4->4
 * 
 * 
 */

// @lc code=start
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
#include<iostream>
using namespace std;
 // namespace std;


struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        if(l1==NULL&&l2==NULL){
            return  NULL;
        }
        
        ListNode *a = l1;
        ListNode *b = l2;
        if(a==NULL){
            return b;
        }
        if(b==NULL){
            return a;    
        }
       
        ListNode *r=new ListNode(-1);
        ListNode *p=r;
        while(a!=NULL&&b!=NULL){
            if(a->val<=b->val){
                ListNode *q =new ListNode(a->val);
                if(r->val == -1)
                {
                    r ->val=q->val;
                    a=a->next;
                }else
                {
                    p->next = q;
                    p=q;
                    a=a->next; /* code */
                }
            }else
            {
               ListNode *q =new ListNode(b->val);
                if(r->val == -1)
                {
                    r ->val=q->val;
                    b=b->next;
                }else
                {
                    p->next = q;
                    p=q;
                    b=b->next; /* code */
                }
                
            }
        }
        if(a==NULL){
            p->next = b;
        }
        if(b==NULL){
            p->next = a;
        }
        return r;
    }
};
// @lc code=end

