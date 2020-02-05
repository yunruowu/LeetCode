/*
 * @Description: 
 * @Version: 2.0
 * @Author: yunruowu
 * @Date: 2020-02-02 20:42:46
 * @LastEditors  : yunruowu
 * @LastEditTime : 2020-02-03 13:45:09
 */
/*
 * @lc app=leetcode.cn id=295 lang=cpp
 *
 * [295] 数据流的中位数
 *
 * https://leetcode-cn.com/problems/find-median-from-data-stream/description/
 *
 * algorithms
 * Hard (40.90%)
 * Likes:    110
 * Dislikes: 0
 * Total Accepted:    9.4K
 * Total Submissions: 22.5K
 * Testcase Example:  '["MedianFinder","addNum","addNum","findMedian","addNum","findMedian"]\n[[],[1],[2],[],[3],[]]'
 *
 * 中位数是有序列表中间的数。如果列表长度是偶数，中位数则是中间两个数的平均值。
 * 
 * 例如，
 * 
 * [2,3,4] 的中位数是 3
 * 
 * [2,3] 的中位数是 (2 + 3) / 2 = 2.5
 * 
 * 设计一个支持以下两种操作的数据结构：
 * 
 * 
 * void addNum(int num) - 从数据流中添加一个整数到数据结构中。
 * double findMedian() - 返回目前所有元素的中位数。
 * 
 * 
 * 示例：
 * 
 * addNum(1)
 * addNum(2)
 * findMedian() -> 1.5
 * addNum(3) 
 * findMedian() -> 2
 * 
 * 进阶:
 * 
 * 
 * 如果数据流中所有整数都在 0 到 100 范围内，你将如何优化你的算法？
 * 如果数据流中 99% 的整数都在 0 到 100 范围内，你将如何优化你的算法？
 * 
 * 
 */
#include "useforme.h"
// @lc code=start
class MedianFinder {
public:
    /** initialize your data structure here. */
    void printHeap(vector<int> &v){
    for(vector<int>::iterator it= v.begin();it!=v.end();++it){
        cout<< *it <<" ";
    }
    cout<<"\n"<<endl;
    }
    MedianFinder() {
        make_heap(min_heap.begin(),min_heap.end(),greater<int>());
        make_heap(max_heap.begin(),max_heap.end(),less<int>());
        minsize = 0;
        maxsize = 0;
        median = 0;
    }
    void addNum(int num) {
        if(minsize == 0 && maxsize == 0){
            max_heap.push_back(num);
            push_heap(max_heap.begin(),max_heap.end(),less<int>());
            maxsize++;
        }else
        {
            double temp = findMedian();
            if(num>temp){
                min_heap.push_back(num);
                push_heap(min_heap.begin(),min_heap.end(),greater<int>());
                minsize++;
            }else
            {
                max_heap.push_back(num);
                push_heap(max_heap.begin(),max_heap.end(),less<int>());
                maxsize++;
            }
            if(minsize>maxsize){
                max_heap.push_back(min_heap[0]);
                push_heap(max_heap.begin(),max_heap.end(),less<int>());
                pop_heap(min_heap.begin(),min_heap.end(),greater<int>());
                min_heap.pop_back();
                minsize--;
                maxsize++;
            }
            if(maxsize-minsize>=2){
                min_heap.push_back(max_heap[0]);
                push_heap(min_heap.begin(),min_heap.end(),greater<int>());
                pop_heap(max_heap.begin(),max_heap.end(),less<int>());
                max_heap.pop_back();
                minsize++;
                maxsize--;
            }
        }
    }
    
    double findMedian() {
        // cout<<"min";
        // printHeap(min_heap);
        // cout<<"max";
        // printHeap(max_heap);
        if(maxsize>minsize){
            return (double)max_heap[0];
        }else
        {
            return (double) (max_heap[0]+min_heap[0])/2;
        }
        
    }
private:
    vector<int> max_heap;
    vector<int> min_heap;
    int maxsize;
    int minsize;
    double median = 0.0;
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */
// @lc code=end

