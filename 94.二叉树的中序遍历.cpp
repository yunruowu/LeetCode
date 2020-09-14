/*
 * @lc app=leetcode.cn id=94 lang=cpp
 *
 * [94] 二叉树的中序遍历
 *
 * https://leetcode-cn.com/problems/binary-tree-inorder-traversal/description/
 *
 * algorithms
 * Medium (72.49%)
 * Likes:    703
 * Dislikes: 0
 * Total Accepted:    259.5K
 * Total Submissions: 353.2K
 * Testcase Example:  '[1,null,2,3]'
 *
 * 给定一个二叉树，返回它的中序 遍历。
 * 
 * 示例:
 * 
 * 输入: [1,null,2,3]
 * ⁠  1
 * ⁠   \
 * ⁠    2
 * ⁠   /
 * ⁠  3
 * 
 * 输出: [1,3,2]
 * 
 * 进阶: 递归算法很简单，你可以通过迭代算法完成吗？
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
    vector<int> ans;
    void mid (TreeNode* root){
        if(root==NULL){
            return ;
        }
        // if(root->left!=NULL){
            mid(root->left);
        // }
        // if(root!=NULL){
            ans.push_back(root->val);
        // }
        
        // if(root->right!=NULL){
            mid(root->right);
        // }
        return;
    }
    vector<int> inorderTraversal(TreeNode* root) {
        
        mid(root);
        return ans;
    }
};
// @lc code=end

