/*
 * @lc app=leetcode.cn id=404 lang=cpp
 *
 * [404] 左叶子之和
 *
 * https://leetcode-cn.com/problems/sum-of-left-leaves/description/
 *
 * algorithms
 * Easy (52.75%)
 * Likes:    117
 * Dislikes: 0
 * Total Accepted:    15.4K
 * Total Submissions: 29K
 * Testcase Example:  '[3,9,20,null,null,15,7]'
 *
 * 计算给定二叉树的所有左叶子之和。
 * 
 * 示例：
 * 
 * 
 * ⁠   3
 * ⁠  / \
 * ⁠ 9  20
 * ⁠   /  \
 * ⁠  15   7
 * 
 * 在这个二叉树中，有两个左叶子，分别是 9 和 15，所以返回 24
 * 
 * 
 * 
 */
#include "useforme.h"

// @lc code=start
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    int sumOfLeftLeaves(TreeNode* root) {
        if(root==NULL){
            return 0;
        }
        stack<TreeNode*> sta;
        sta.push(root);
        int ans = 0;
        
        while (!sta.empty())
        {
            TreeNode* t = sta.top();
            sta.pop();
            TreeNode* left = t->left;
            if(left!=NULL)
            {
                if(left->left==NULL&&left->right==NULL){
                    // cout<<left->val<<" ";
                    ans += left->val;
                }else
                {
                // cout<<left->val<<" ";

                    sta.push(left);
                }
            }
            if(t->right!=NULL){
                // cout<<t->right->val<<" ";
                
                sta.push(t->right);
            }
            // TreeNode* right = t->right;

        }
        return ans;
    }
};
// @lc code=end

