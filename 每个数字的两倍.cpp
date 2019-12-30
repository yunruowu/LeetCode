#include <iostream>
#include <stack>
#include <stdlib.h>
#include <string>
#include <vector>

using namespace std;
class Solution {
public:
  int dominantIndex(vector<int> &nums) {
    int n = nums.size();
    int i;
    int sum = 1;
    int csum = 0;
    if (nums.size() == 1) {
      return 0;
    }
    if (nums.size() == 0) {
      return -1;
    }
    if (nums[sum] < nums[csum]) {
      swap(sum, csum);
    }
    for (int i = 0; i < n; i++) {
      if (nums[i] > nums[csum] && nums[i] > nums[sum]) {
        csum = sum;
        sum = i;
      }
      if (nums[i] > nums[csum] && nums[i] < nums[sum]) {
        csum = i;
      }
    }
    //  for(int i = 0;i<n&&i!=sum;i++){
    //     if(nums[i]*2>nums[sum]){
    //         return -1;
    //     }
    // }
    if (nums[sum] > nums[csum]) {
      return sum;
    } else {
      return -1;
    }
  }
};