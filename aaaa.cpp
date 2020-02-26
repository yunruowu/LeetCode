/*
 * @Description: 
 * @Version: 2.0
 * @Author: yunruowu
 * @Date: 2020-02-18 11:21:20
 * @LastEditors: yunruowu
 * @LastEditTime: 2020-02-26 22:46:24
 */


#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    
    bool isLeapYear(int year) {
        return (year % 4 == 0 && year % 100 != 0) || year % 400 == 0;
    }
    
    int days[12] = {0, 31, 59, 90, 120, 151, 181, 212, 243, 273, 304, 334};
    int dayOffset(int year, int month, int day) {
        int res = (year - 1) * 365 + (year - 1) / 4 - (year - 1) / 100 + (year - 1) / 400 + days[month - 1] + day;
        return isLeapYear(year) && month > 2 ? res + 1 : res;
    }
    int daysBetweenDates(string date1, string date2) {
        string y = date1.substr(0,4);
        int yy = atoi(y.c_str());
        string m = date1.substr(5,2);
        int mm = atoi(m.c_str());
        string d = date1.substr(8,2);
        int dd = atoi(d.c_str());

        string y1 = date2.substr(0,4);
        int yy1 = atoi(y1.c_str());
        string m1 = date2.substr(5,2);
        int mm1 = atoi(m1.c_str());
        string d1 = date2.substr(8,2);
        int dd1 = atoi(d1.c_str());

        return abs(-dayOffset(yy,mm,dd)+dayOffset(yy1,mm1,dd1));
    }
};

void splr(string s){
    string y = s.substr(0,4);
    
    string m = s.substr(5,2);

    string d = s.substr(8,2);
    
    int  t = atoi(d.c_str());
    cout<<t;
    cout<<y<<"  "<<m<<"  "<<d;
}


void t(){
    for(int i = 0;i<4;i++){
        cout<<"i = "<<i<<" ";
        for(int j = 0;j<4;j++){
            if(j==2){
                break;
            }
            cout<<j<<" ";
        }
        
    }
}

int main(int argc, char const *argv[])
{
    t();
    
    return 0;
}
