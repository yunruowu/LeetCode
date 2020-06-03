#include <stdio.h>
// #include "useforme.h"
#include <iostream>
using namespace std;
int main(){
    int x=0,y=0;
    int s = 999999999;
    int x_min,y_min;
    while(x<=8){
        y=0;
        while(y<=10){
            // cout<<x<<y;
            if(200*x+120*y>=1800){
                int temp_s = 32*x+24*y+(4*x+6*y)*2;
                // cout<<temp_s<<endl;
                if(temp_s<s){
                    cout<<x_min<<" "<<y_min<<" "<<s<<endl;
                    s = temp_s;
                    x_min = x;
                    y_min = y;
                }
            }
            y++;
        }
        x++;
    }
    cout<<x_min<<" "<<y_min<<" "<<s;
    return 0;
}
