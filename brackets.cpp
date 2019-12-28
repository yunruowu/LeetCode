// #include<string.h>
#include<iostream>
#include<vector>
// #include <iostream>
#include <stack>
using namespace std;
class Solution {
public:
    bool isValid(string s) {
        stack <char> strstack;
        int i = 0;
        for(i= 0;i<s.length();i++){
            if(s[i]=='('||s[i]=='{'||s[i]=='['){
                strstack.push(s[i]);
            }
            else if (strstack.size>0)
            {          
                if(s[i]==')')
                {
                    if(strstack.top()=='('){
                        strstack.pop();
                    }else 
                    {
                        return false;
                    }
                    
                }else if(s[i]==']')
                {
                    if(strstack.top()=='['){
                        strstack.pop();
                    }else 
                    {
                        return false;
                    }
                }else
                {
                if(strstack.top()=='{'){
                        strstack.pop();
                    }else 
                    {
                        return false;
                    }
                }
            }
            else
            {
                return false;
            }
            
            
        }
        if(strstack.size()==0)
            return true;
        else
        {
            return false;
        }
        
    }
};