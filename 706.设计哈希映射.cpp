/*
 * @Description: 
 * @Version: 2.0
 * @Author: yunruowu
 * @Date: 2020-03-05 17:28:32
 * @LastEditors: yunruowu
 * @LastEditTime: 2020-03-05 19:00:20
 */
/*
 * @lc app=leetcode.cn id=706 lang=cpp
 *
 * [706] 设计哈希映射
 *
 * https://leetcode-cn.com/problems/design-hashmap/description/
 *
 * algorithms
 * Easy (55.83%)
 * Likes:    32
 * Dislikes: 0
 * Total Accepted:    9.4K
 * Total Submissions: 16.8K
 * Testcase Example:  '["MyHashMap","put","put","get","get","put","get", "remove", "get"]\n[[],[1,1],[2,2],[1],[3],[2,1],[2],[2],[2]]'
 *
 * 不使用任何内建的哈希表库设计一个哈希映射
 * 
 * 具体地说，你的设计应该包含以下的功能
 * 
 * 
 * put(key, value)：向哈希映射中插入(键,值)的数值对。如果键对应的值已经存在，更新这个值。
 * get(key)：返回给定的键所对应的值，如果映射中不包含这个键，返回-1。
 * remove(key)：如果映射中存在这个键，删除这个数值对。
 * 
 * 
 * 
 * 示例：
 * 
 * 
 * MyHashMap hashMap = new MyHashMap();
 * hashMap.put(1, 1);          
 * hashMap.put(2, 2);         
 * hashMap.get(1);            // 返回 1
 * hashMap.get(3);            // 返回 -1 (未找到)
 * hashMap.put(2, 1);         // 更新已有的值
 * hashMap.get(2);            // 返回 1 
 * hashMap.remove(2);         // 删除键为2的数据
 * hashMap.get(2);            // 返回 -1 (未找到) 
 * 
 * 
 * 
 * 注意：
 * 
 * 
 * 所有的值都在 [1, 1000000]的范围内。
 * 操作的总数目在[1, 10000]范围内。
 * 不要使用内建的哈希库。
 * 
 * 
 */
#include "useforme.h"
// @lc code=start
class MyHashMap {
public:
    /** Initialize your data structure here. */
    vector<int> hash;
    int prime = 100000;
    MyHashMap() {
        for(int i = 0; i<prime;i++){
            hash.push_back(-1);
        }
    }
    
    /** value will always be non-negative. */
    void put(int key, int value) {
        if(get(key)==-1){//插入
            hash[key]=value;
        }else{//更新
            hash[key]=value;
        }
        cout<<hash[key];
    }
    
    /** Returns the value to which the specified key is mapped, or -1 if this map contains no mapping for the key */
    int get(int key) {
        return hash[key];
    }
    
    /** Removes the mapping of the specified value key if this map contains a mapping for the key */
    void remove(int key) {
        hash[key]=-1;
    }
};

/**
 * Your MyHashMap object will be instantiated and called as such:
 * MyHashMap* obj = new MyHashMap();
 * obj->put(key,value);
 * int param_2 = obj->get(key);
 * obj->remove(key);
 */
// @lc code=end

