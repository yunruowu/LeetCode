#include<iostream>
#include<vector>
// #include <iostream>
#include <stack>
using namespace std; 
class MinStack {
public:
    /** initialize your data structure here. */
    // vector<int> stack;
    // vector<int> min;
    stack <int> Sta;
    stack <int> minSta;
    MinStack() {
        
    }
    
    void push(int x) {
        if(Sta.size()==0){
            Sta.push(x);
            minSta.push(x);
        }else{
            if(x<=minSta.top()){
                minSta.push(x);
            }
            Sta.push(x);
        }
    }
    
    void pop() {
        if(Sta.top()!=minSta.top()){
            Sta.pop();
        }else
        {
            Sta.pop();
            minSta.pop();
        }
        
    }
    
    int top() {
        return Sta.top();
    }
    
    int getMin() {
        return minSta.top();
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(x);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */
int main(){
    stack<int> s1;
    cout<<"asdd";
    cout<<s1.top()<<"sdss";
    return 0;
}