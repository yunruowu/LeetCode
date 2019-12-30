#include <iostream>
#include <stack>
#include <stdlib.h>
#include <string>
#include <vector>

using namespace std;
class Solution {
public:
  vector<int> plusOne(vector<int> &digits) {
    int Cout = 1;
    int sum = digits[digits.size() - 1] + 1;
    for (int i = digits.size() - 1; i >= 0; i--) {
      sum = digits[i] + Cout;
      if (sum == 10) {
        Cout = 1;
        digits[i] = 0;
      } else {
        Cout = 0;
        digits[i] = sum;
        return digits;
      }
    //   sum = Cout + digits[i];
    }
    if (Cout == 1) {
      digits.insert(digits.begin(), 1);
    }
    return digits;
  }
};