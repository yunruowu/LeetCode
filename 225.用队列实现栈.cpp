/*
 * @Description: 
 * @Version: 2.0
 * @Author: yunruowu
 * @Date: 2020-02-10 10:02:08
 * @LastEditors  : yunruowu
 * @LastEditTime : 2020-02-10 11:01:14
 */
/*
 * @lc app=leetcode.cn id=225 lang=cpp
 *
 * [225] 用队列实现栈
 *
 * https://leetcode-cn.com/problems/implement-stack-using-queues/description/
 *
 * algorithms
 * Easy (61.99%)
 * Likes:    113
 * Dislikes: 0
 * Total Accepted:    28.5K
 * Total Submissions: 45.8K
 * Testcase Example:  '["MyStack","push","push","top","pop","empty"]\n[[],[1],[2],[],[],[]]'
 *
 * 使用队列实现栈的下列操作：
 * 
 * 
 * push(x) -- 元素 x 入栈
 * pop() -- 移除栈顶元素
 * top() -- 获取栈顶元素
 * empty() -- 返回栈是否为空
 * 
 * 
 * 注意:
 * 
 * 
 * 你只能使用队列的基本操作-- 也就是 push to back, peek/pop from front, size, 和 is empty
 * 这些操作是合法的。
 * 你所使用的语言也许不支持队列。 你可以使用 list 或者 deque（双端队列）来模拟一个队列 , 只要是标准的队列操作即可。
 * 你可以假设所有操作都是有效的（例如, 对一个空的栈不会调用 pop 或者 top 操作）。
 * 
 * 
 */
#include "useforme.h"
// @lc code=start
class MyStack {
private:
    queue<int> queone;
    queue<int> quetwo;
    bool selque;
    int num = 0;
public:
    /** Initialize your data structure here. */
    MyStack() {
        selque = 0;
        num = 0;
    }
    
    /** Push element x onto stack. */
    void push(int x) {
        if(selque==0){
            queone.push(x);
            num++;
        }else
        {
            quetwo.push(x);
            num++;
        }
        
    }
    
    /** Removes the element on top of the stack and returns that element. */
    int pop() {
        int len = num;
        int ans;
        cout<<num<<len<<endl;
        if(selque==0){
            
            while(num>1){
                quetwo.push(queone.front());
                queone.pop();
                num--;
            }
            ans = queone.front();
            queone.pop();
        }else
        {
            while(num>1){
                queone.push(quetwo.front());
                quetwo.pop();
                num--;
            }
            ans = quetwo.front();
            quetwo.pop();
        }
        selque=!selque;
        num = len-1;
        cout<<num<<len<<endl<<selque<<endl;
        return ans;
    }
    
    /** Get the top element. */
    int top() {
        int len = num;
        int ans;
        if(selque==0){
            
            while(num>1){
                quetwo.push(queone.front());
                queone.pop();
                num--;
            }
            ans = queone.front();
            quetwo.push(queone.front());
            queone.pop();
        }else
        {
            while(num>1){
                queone.push(quetwo.front());
                quetwo.pop();
                num--;
            }
            ans = quetwo.front();
            queone.push(quetwo.front());
            quetwo.pop();
        }
        selque=!selque;
        // num = len--;
        num = len;
        return ans;
    }
    
    /** Returns whether the stack is empty. */
    bool empty() {
        return num==0;
    }
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */
// @lc code=end

