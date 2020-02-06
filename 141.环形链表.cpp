/*
 * @Description: 
 * @Version: 2.0
 * @Author: yunruowu
 * @Date: 2020-02-05 21:56:17
 * @LastEditors  : yunruowu
 * @LastEditTime : 2020-02-05 22:07:12
 */
/*
 * @lc app=leetcode.cn id=141 lang=cpp
 *
 * [141] 环形链表
 *
 * https://leetcode-cn.com/problems/linked-list-cycle/description/
 *
 * algorithms
 * Easy (45.92%)
 * Likes:    480
 * Dislikes: 0
 * Total Accepted:    103.5K
 * Total Submissions: 225.2K
 * Testcase Example:  '[3,2,0,-4]\n1'
 *
 * 给定一个链表，判断链表中是否有环。
 * 
 * 为了表示给定链表中的环，我们使用整数 pos 来表示链表尾连接到链表中的位置（索引从 0 开始）。 如果 pos 是 -1，则在该链表中没有环。
 * 
 * 
 * 
 * 示例 1：
 * 
 * 输入：head = [3,2,0,-4], pos = 1
 * 输出：true
 * 解释：链表中有一个环，其尾部连接到第二个节点。
 * 
 * 
 * 
 * 
 * 示例 2：
 * 
 * 输入：head = [1,2], pos = 0
 * 输出：true
 * 解释：链表中有一个环，其尾部连接到第一个节点。
 * 
 * 
 * 
 * 
 * 示例 3：
 * 
 * 输入：head = [1], pos = -1
 * 输出：false
 * 解释：链表中没有环。
 * 
 * 
 * 
 * 
 * 
 * 
 * 进阶：
 * 
 * 你能用 O(1)（即，常量）内存解决此问题吗？
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
    bool hasCycle(ListNode *head) {
        vector<ListNode*> Node;
        ListNode * p = head;
        while(p!=NULL){
            if(find(Node.begin(),Node.end(),p)==Node.end()){
                Node.push_back(p);
                p = p->next;
            }else//找到
            {
                return true;
            }
            
        }
        return false;
    }
};
// @lc code=end

