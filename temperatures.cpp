#include<iostream>
#include<vector>
// #include <iostream>
#include <stack>
using namespace std;
class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& T) {
        vector<int> ans;
        stack<int> sta;
        ans.insert(ans.begin(),0);
        // std::vector<int>::iterator it=myvec.end()-1;it>=myvec.begin();it--
        // vector<int>::iterator it = T.end()-1;
        // sta.push(*it);
        // for(it = T.end()-2;it>=T.begin();it--){

        // }
        int len = T.size();
        sta.push(len-1);
        long i;
        for(i = len-2;i>=0;i--){
            while (T[i]>=T[sta.top()])
            {
                    sta.pop();
                    if(sta.empty()==true){
                        break;
                    }
            }
            if(sta.empty()==true){
                    ans.insert(ans.begin(),0);
            }
            ans.insert(ans.begin(),sta.top()-i);
            sta.push(i);    
        }
        return ans;
    }



    
};

int main(){
    // Solution s;
    vector<int>a;
    
    string s = "123456";
    string a = s.substr(0,2);
    cout<<a;
    
    return 0;
}



