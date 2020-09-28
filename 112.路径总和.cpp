/*
 * @lc app=leetcode.cn id=112 lang=cpp
 *
 * [112] 路径总和
 *
 * https://leetcode-cn.com/problems/path-sum/description/
 *
 * algorithms
 * Easy (50.96%)
 * Likes:    434
 * Dislikes: 0
 * Total Accepted:    138.2K
 * Total Submissions: 270.2K
 * Testcase Example:  '[5,4,8,11,null,13,4,7,2,null,null,null,1]\n22'
 *
 * 给定一个二叉树和一个目标和，判断该树中是否存在根节点到叶子节点的路径，这条路径上所有节点值相加等于目标和。
 * 
 * 说明: 叶子节点是指没有子节点的节点。
 * 
 * 示例: 
 * 给定如下二叉树，以及目标和 sum = 22，
 * 
 * ⁠             5
 * ⁠            / \
 * ⁠           4   8
 * ⁠          /   / \
 * ⁠         11  13  4
 * ⁠        /  \      \
 * ⁠       7    2      1
 * 
 * 
 * 返回 true, 因为存在目标和为 22 的根节点到叶子节点的路径 5->4->11->2。
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
    int tsum;
    bool dfs(int sum, TreeNode* cur){
        if(cur->left == NULL&& cur->right==NULL){
            return sum == tsum;
        }
        int r_bool=false,l_bool=false;
        if(cur->right!=NULL){
            int temp = sum + cur->right->val;
            r_bool = dfs(temp, cur->right);
        }
        
        if(cur->left!=NULL){
            int temp = sum + cur->left->val;
            l_bool = dfs(temp, cur->left);
        }
        return r_bool || l_bool;
    }
    bool hasPathSum(TreeNode* root, int sum) {
        tsum = sum;
        stack<TreeNode*> sta;
        int val = 0;
        if(root!=NULL)
            return dfs(root->val, root);
        return false;
        // sta.push(root);
        // while(!sta.empty()){
        //     TreeNode* cur = sta.top();
        //     sta.pop();

        //     if(cur->left){
        //         sta.push(cur->left);
        //     }
        //     if(cur->right){
        //         sta.push(cur->right);
        //     }
        //     if(cur->left==NULL&&cur->right==NULL){

        //     }
        // }
    }
};
// @lc code=end

