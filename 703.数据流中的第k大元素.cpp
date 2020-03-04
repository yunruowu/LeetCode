/*
 * @Description: 
 * @Version: 2.0
 * @Author: yunruowu
 * @Date: 2020-03-04 09:10:13
 * @LastEditors: yunruowu
 * @LastEditTime: 2020-03-04 09:55:59
 */
/*
 * @lc app=leetcode.cn id=703 lang=cpp
 *
 * [703] 数据流中的第K大元素
 *
 * https://leetcode-cn.com/problems/kth-largest-element-in-a-stream/description/
 *
 * algorithms
 * Easy (42.03%)
 * Likes:    107
 * Dislikes: 0
 * Total Accepted:    14.6K
 * Total Submissions: 34.3K
 * Testcase Example:  '["KthLargest","add","add","add","add","add"]\n[[3,[4,5,8,2]],[3],[5],[10],[9],[4]]'
 *
 * 设计一个找到数据流中第K大元素的类（class）。注意是排序后的第K大元素，不是第K个不同的元素。
 * 
 * 你的 KthLargest 类需要一个同时接收整数 k 和整数数组nums 的构造器，它包含数据流中的初始元素。每次调用
 * KthLargest.add，返回当前数据流中第K大的元素。
 * 
 * 示例:
 * 
 * 
 * int k = 3;
 * int[] arr = [4,5,8,2];
 * KthLargest kthLargest = new KthLargest(3, arr);
 * kthLargest.add(3);   // returns 4
 * kthLargest.add(5);   // returns 5
 * kthLargest.add(10);  // returns 5
 * kthLargest.add(9);   // returns 8
 * kthLargest.add(4);   // returns 8
 * 
 * 
 * 说明: 
 * 你可以假设 nums 的长度≥ k-1 且k ≥ 1。
 * 
 */
#include "useforme.h"
// @lc code=start
class KthLargest {
public:
    int k_Max;
    int k_pos;
    vector<int> mem;
    KthLargest(int k, vector<int>& nums) {
        sort(nums.rbegin(),nums.rend());
        cout<<1;
        mem.assign(nums.begin(),nums.end());
        cout<<2;
        k_pos = k;
        
    }
    
    int add(int val) {
        cout<<3;
        if(mem.empty()){
            cout<<4;
            mem.push_back(val);
            return mem[k_pos-1];
        }
        if(val>=mem[0]){
            mem.insert(mem.begin(),val);
        }
        else if(val<mem[mem.size()-1]){
            mem.push_back(val);
        }
        else{
            int i = 1;
            while(val<mem[i]){
                i++;
            }
            mem.insert(mem.begin()+i,val);
        }
        return mem[k_pos-1];
    }
};

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */
// @lc code=end

