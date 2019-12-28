#include<iostream>
#include<vector>
using namespace std; 
class MyCircularQueue {
    public:
        /** Initialize your data structure here. Set the size of the queue to be k. */
        vector<int> data;
        // int data_len ;
        int data_size;
        int p_start;
        int p_end;
        bool tag;
        MyCircularQueue(int k){
            tag = true;//标记判断空还是满；
            data_size = k;
            data.reserve(data_size);
            p_start = 0;
            p_end = 0;
        }
        
        /** Insert an element into the circular queue. Return true if the operation is successful. */
        bool enQueue(int value) {
            // cout<<p_end<<(p_start+1)%data_size<<endl;
            if(!isFull()){
                data[p_end]=value;
                p_end=(p_end+1)%data_size;
                tag = false;
                // cout<<"shuru";
                return true;
            }
            else{
                return false;
            }
        }
        
        /** Delete an element from the circular queue. Return true if the operation is successful. */
        bool deQueue() {
            if(isEmpty()){
                return false;
            }
            p_start = (p_start+1)%data_size;
            tag = true;
            return true;
        }
        
        /** Get the front item from the queue. */
        int Front() {
            if (isEmpty()) {
                return -1;
            }
            return data[p_start];
        }
        
        /** Get the last item from the queue. */
        int Rear() {
             if (isEmpty()) {
                return -1;
            }
            // return data[p_end];
            return data[((p_end+data_size)-1)%data_size];
        }
        // void put(){
        //     int i;
        //     for(i = 0 ;i<data_size;i++){
        //         cout<<data[i];
        //     }
        // }
        /** Checks whether the circular queue is empty or not. */
        bool isEmpty() {
            if(p_end==p_start&&tag==true){
                return true;
            }
            else
            {
                return false;
            }
            
        }
        
        /** Checks whether the circular queue is full or not. */
        bool isFull() {
            if((p_end)%data_size==p_start&&tag==false){
                return true;
            }else
            {
                return false;
            }
            
        }
};
int main(){
    MyCircularQueue qu(3);
    cout<<qu.enQueue(1);
    // cout<<qu.p_end<<" "<<qu.p_start<<endl;
    cout<<qu.enQueue(2);
    // cout<<qu.p_end<<" "<<qu.p_start<<endl;
    cout<<qu.enQueue(3)<<endl;
    cout<<qu.p_end<<" "<<qu.p_start<<endl;
    cout<<qu.Rear()<<"      "<<qu.Front()<<endl;
    // qu.put();
    // cout<<qu.isFull();
    return 0;

}
/**
 * Your MyCircularQueue object will be instantiated and called as such:
 * MyCircularQueue* obj = new MyCircularQueue(k);
 * bool param_1 = obj->enQueue(value);
 * bool param_2 = obj->deQueue();
 * int param_3 = obj->Front();
 * int param_4 = obj->Rear();
 * bool param_5 = obj->isEmpty();
 * bool param_6 = obj->isFull();
 */