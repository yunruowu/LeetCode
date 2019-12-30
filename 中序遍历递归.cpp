/**
 * Definition for a binary tree node.
  struct TreeNode {
      int val;
      TreeNode *left;
     TreeNode *right;
      TreeNode(int x) : val(x), left(NULL), right(NULL) {}
  };
 */
#include <iostream>
#include <vector>
#include <stack>
#include <string>
#include <stdlib.h>
using namespace std;
struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
class Solution
{
public:
    vector<int> inorderTraversal(TreeNode *root)
    {
        vector<int> ans;
        stack<TreeNode*> st;
        if(root==NULL){
            return ans;
        }
        st.push(root);
        int tag = 0;
        while(!st.empty()){
            
            while(st.top()->left!=NULL&&tag==0){
                st.push(st.top()->left);
            }
            if(st.top()->right!=NULL){
                TreeNode* croot = st.top();
                st.pop();
                ans.push_back(croot->val);
                st.push (croot->right);
                tag=0;
            }else{
                TreeNode* croot = st.top();
                st.pop();
                ans.push_back(croot->val);
                tag =1;
            }
        }
        return ans;
    }
};