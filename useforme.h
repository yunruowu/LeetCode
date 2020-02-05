/*
 * @Description: 文件用来包含所有解题头文件，结构
 * @Version: 2.0
 * @Author: yunruowu
 * @Date: 2020-02-02 10:30:03
 * @LastEditors  : yunruowu
 * @LastEditTime : 2020-02-03 11:46:51
 */

#include<iostream>
#include<vector>
#include<stack>
#include<queue>
#include<algorithm>
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
using namespace std;