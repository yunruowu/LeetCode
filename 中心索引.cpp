#include <iostream>
#include <stack>
#include <stdlib.h>
#include <string>
#include <vector>

using namespace std;
class Solution {
public:
  int pivotIndex(vector<int> &nums) {
    int i = 0;
    for (i = 0; i < nums.size(); i++) {
        int j,sum1,sum2;
        sum1 = 0;
        sum2=0;
        for(j=0;j<i;j++){
            sum1=sum1+nums[j];
        }
        for(j=i+1;j<nums.size();j++){
            sum2=sum2+nums[j];
        }
        if(sum1==sum2){
            return i;
        }
    }
    return -1;
  }
};