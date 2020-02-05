#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void printHeap(vector<int> &v){
    for(vector<int>::iterator it= v.begin();it!=v.end();++it){
        cout<< *it <<" ";
    }
    cout<<"\n"<<endl;
}

int main()
{
    vector<int> minheap;
    minheap.push_back(58);
    minheap.push_back(3);
    minheap.push_back(5);
    minheap.push_back(6);

    //建立小顶堆
    make_heap(minheap.begin(), minheap.end(), greater<int>());
    printHeap(minheap);//6 10 9 30 15 22
cout<<minheap[0];
    //插入元素
    minheap.push_back(20);
    push_heap(minheap.begin(),minheap.end(), greater<int>());//该算法前提：必须在堆的条件下
    printHeap(minheap); //6 10 9 30 15 22 20   仍为小顶堆

    //删除堆顶元素
    pop_heap(minheap.begin(),minheap.end(), greater<int>());
    printHeap(minheap);//9 10 20 30 15 22 6  不为小顶堆 这个pop_heap操作后，实际上是把堆顶元素放到了末尾
    minheap.pop_back();//这才彻底在底层vector数据容器中删除
    printHeap(minheap);//9 10 20 30 15 22  仍为小顶堆

    //堆排序  保持greater，小顶堆，得到的是降序
    // sort_heap(minheap.begin(),minheap.end(), greater<int>());//试了用less，结果杂乱无章
    printHeap(minheap);//30 22 20 15 10 9 注意结果是降序的哦!!!其实是调用了很多次pop_heap(...,greater..)，每一次都把小顶堆堆顶的元素往末尾放，没放一次end迭代器减1
    
    return 0;
}
