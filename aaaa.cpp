/*
 * @Description: 
 * @Version: 2.0
 * @Author: yunruowu
 * @Date: 2020-02-18 11:21:20
 * @LastEditors: yunruowu
 * @LastEditTime: 2020-02-20 21:50:23
 */
#include "useforme.h"


bool isA(char s){
        return s-'A'>=0 && s-'A'<26;
    }

void s(){
    vector<string> s;
    s.push_back("swws");
    s.push_back("ssss");
    s.push_back("ss");
    s.push_back("ss");
    cout<<find(s.begin(),s.end(),"ss")-s.begin();
    
}


void t(){
    string s = "Bob hit a ball, the hit BALL flew far after it was hit.";
    transform(s.begin(),s.end(),s.begin(), ::tolower);
    string t;
    int i =0;
    int len = s.size();
    while(i<len){
        t = "";
        while(isalpha(s[i])&&i<len){
            t = t + s[i];
            i++;
        }
        while(!isalpha(s[i])&&i<len){
            i++;
        }
        cout<<t<<endl;
    }
}


int main(int argc, char const *argv[])
{
    // s();
    // t();?
    // cout<<"           "<<1212;
    string s = "1dasdssss";
    cout<<s.find("d")<<s.find('d');
    // cout<<'l'-'a'<<'e'-'a';
    return  0;
}
