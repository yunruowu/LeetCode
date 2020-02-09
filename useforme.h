 /*
 * @Description: 文件用来包含所有解题头文件，结构
 * @Version: 2.0
 * @Author: yunruowu
 * @Date: 2020-02-02 10:30:03
 * @LastEditors  : yunruowu
 * @LastEditTime : 2020-02-07 21:19:36
 */

#include<iostream>
#include<vector>
#include<stack>
#include<queue>
#include<algorithm>
#include<ctype.h>
#include <math.h>
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

struct ListNode {
    int val;
    ListNode * next;
    ListNode(int x) : val(x), next(NULL) {}
};
using namespace std;
void Prinetvec(vector<int> nums){
    for(int i = 0 ;i< nums.size();i++){
        cout<<nums[i]<<" ";
    }
    cout<<endl;
};
