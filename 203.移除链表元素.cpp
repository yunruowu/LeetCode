/*
 * @Description: 
 * @Version: 2.0
 * @Author: yunruowu
 * @Date: 2020-02-07 19:37:23
 * @LastEditors  : yunruowu
 * @LastEditTime : 2020-02-07 19:38:50
 */
/*
 * @lc app=leetcode.cn id=203 lang=cpp
 *
 * [203] 移除链表元素
 *
 * https://leetcode-cn.com/problems/remove-linked-list-elements/description/
 *
 * algorithms
 * Easy (43.72%)
 * Likes:    336
 * Dislikes: 0
 * Total Accepted:    57K
 * Total Submissions: 130K
 * Testcase Example:  '[1,2,6,3,4,5,6]\n6'
 *
 * 删除链表中等于给定值 val 的所有节点。
 * 
 * 示例:
 * 
 * 输入: 1->2->6->3->4->5->6, val = 6
 * 输出: 1->2->3->4->5
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
    ListNode* removeElements(ListNode* head, int val) {
        if (head==NULL){
            return head;
        }
        ListNode* p=head;
        while(p->next!=NULL){
            if (p->next->val == val){
                p->next = p->next->next;
            }
            else{
                p=p->next;
            }
        }
        if (head->val==val)
            head=head->next;
        return head;
    }
};
// @lc code=end

