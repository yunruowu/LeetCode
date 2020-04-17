/*
 * @lc app=leetcode.cn id=98 lang=cpp
 *
 * [98] 验证二叉搜索树
 *
 * https://leetcode-cn.com/problems/validate-binary-search-tree/description/
 *
 * algorithms
 * Medium (29.59%)
 * Likes:    508
 * Dislikes: 0
 * Total Accepted:    91.5K
 * Total Submissions: 307.4K
 * Testcase Example:  '[2,1,3]'
 *
 * 给定一个二叉树，判断其是否是一个有效的二叉搜索树。
 * 
 * 假设一个二叉搜索树具有如下特征：
 * 
 * 
 * 节点的左子树只包含小于当前节点的数。
 * 节点的右子树只包含大于当前节点的数。
 * 所有左子树和右子树自身必须也是二叉搜索树。
 * 
 * 
 * 示例 1:
 * 
 * 输入:
 * ⁠   2
 * ⁠  / \
 * ⁠ 1   3
 * 输出: true
 * 
 * 
 * 示例 2:
 * 
 * 输入:
 * ⁠   5
 * ⁠  / \
 * ⁠ 1   4
 * / \
 * 3   6
 * 输出: false
 * 解释: 输入为: [5,1,4,null,null,3,6]。
 * 根节点的值为 5 ，但是其右子节点值为 4 。
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
    int getMin(TreeNode* root){
        if(root==NULL){
            return 99999;
        }
        int m = root->val;
        if(root->left){
            m = min(m, getMin(root->left));
        }
        if(root->right){
            m = min(m, getMin(root->right));
        }
        return m;
    }
    int getMax(TreeNode* root){
        if(root==NULL){
            return -1;
        }
        int m = root->val;
        if(root->left){
            m = max(m, getMax(root->left));
        }
        if(root->right){
            m = max(m, getMax(root->right));
        }
        return m;
    }
    bool isValidBST(TreeNode* root) {
        if(root==NULL)
            return true;
        bool tag_L = true;
        bool tag_R = true;
        if(root->left){
            tag_L = (root->val>getMax(root->left))&&isValidBST(root->left);
        }
        if(root->right){
            tag_R = (root->val<getMin(root->right))&&isValidBST(root->right);
        }
        return tag_L&&tag_R;
    }
};
// @lc code=end

