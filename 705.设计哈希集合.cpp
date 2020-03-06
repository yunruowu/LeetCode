/*
 * @Description: 
 * @Version: 2.0
 * @Author: yunruowu
 * @Date: 2020-03-05 16:42:47
 * @LastEditors: yunruowu
 * @LastEditTime: 2020-03-05 17:27:29
 */
/*
 * @lc app=leetcode.cn id=705 lang=cpp
 *
 * [705] 设计哈希集合
 *
 * https://leetcode-cn.com/problems/design-hashset/description/
 *
 * algorithms
 * Easy (55.34%)
 * Likes:    35
 * Dislikes: 0
 * Total Accepted:    10.6K
 * Total Submissions: 19.1K
 * Testcase Example:  '["MyHashSet","add","add","contains","contains","add","contains","remove","contains"]\n[[],[1],[2],[1],[3],[2],[2],[2],[2]]'
 *
 * 不使用任何内建的哈希表库设计一个哈希集合
 * 
 * 具体地说，你的设计应该包含以下的功能
 * 
 * 
 * add(value)：向哈希集合中插入一个值。
 * contains(value) ：返回哈希集合中是否存在这个值。
 * remove(value)：将给定值从哈希集合中删除。如果哈希集合中没有这个值，什么也不做。
 * 
 * 
 * 
 * 示例:
 * 
 * MyHashSet hashSet = new MyHashSet();
 * hashSet.add(1);         
 * hashSet.add(2);         
 * hashSet.contains(1);    // 返回 true
 * hashSet.contains(3);    // 返回 false (未找到)
 * hashSet.add(2);          
 * hashSet.contains(2);    // 返回 true
 * hashSet.remove(2);          
 * hashSet.contains(2);    // 返回  false (已经被删除)
 * 
 * 
 * 
 * 注意：
 * 
 * 
 * 所有的值都在 [0, 1000000]的范围内。
 * 操作的总数目在[1, 10000]范围内。
 * 不要使用内建的哈希集合库。
 * 
 */
#include "iostream"
#include "vector"
using namespace std;
#include "useforme.h"
// @lc code=start
// struct ListNode {
//     int val;
//     ListNode * next;
//     ListNode(int x) : val(x), next(NULL) {}
// };
class MyHashSet {
public:
    /** Initialize your data structure here. */
    vector<ListNode*> hash;
    int prime = 6151;
    MyHashSet() {
        for(int i = 0; i<prime;i++){
            hash.push_back(NULL);
        }
    }
    
    void add(int key) {
        if(contains(key)){
            return;
        }
        int pos = key%prime;
        
        
        if(hash[pos]==NULL){
            ListNode* addOne=new ListNode(key);
            hash[pos]=addOne;
            return;
        }
        ListNode* temp = hash[pos];
        while(temp->next!=NULL){
            temp = temp->next;
        }
        ListNode* addOne=new ListNode(key);
        temp->next = addOne;
    }
    
    void remove(int key) {
        if(!contains(key)){
            return;
        }
        int pos = key%prime;
        ListNode* temp = hash[pos];
        if(temp->val==key){
            hash[pos]= temp->next;
            delete temp;
            return;
        }
        while(temp->next!=NULL){
            if(temp->next->val == key){
                ListNode* del = temp->next;
                temp->next = del->next;
                delete del;
                return ;
            }
            temp = temp->next;
        }

    }
    
    /** Returns true if this set contains the specified element */
    bool contains(int key) {
        int pos = key%prime;
        ListNode* temp = hash[pos];
        while(temp!=NULL){
            if(temp->val == key){
                return true;
            }
            temp = temp->next;
        }
        return false;
    }
};

/**
 * Your MyHashSet object will be instantiated and called as such:
 * MyHashSet* obj = new MyHashSet();
 * obj->add(key);
 * obj->remove(key);
 * bool param_3 = obj->contains(key);
 */
// @lc code=end

