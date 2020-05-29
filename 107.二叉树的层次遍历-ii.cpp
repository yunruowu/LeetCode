/*
 * @lc app=leetcode.cn id=107 lang=cpp
 *
 * [107] 二叉树的层次遍历 II
 *
 * https://leetcode-cn.com/problems/binary-tree-level-order-traversal-ii/description/
 *
 * algorithms
 * Easy (64.70%)
 * Likes:    224
 * Dislikes: 0
 * Total Accepted:    52.4K
 * Total Submissions: 80.8K
 * Testcase Example:  '[3,9,20,null,null,15,7]'
 *
 * 给定一个二叉树，返回其节点值自底向上的层次遍历。 （即按从叶子节点所在层到根节点所在的层，逐层从左向右遍历）
 * 
 * 例如：
 * 给定二叉树 [3,9,20,null,null,15,7],
 * 
 * ⁠   3
 * ⁠  / \
 * ⁠ 9  20
 * ⁠   /  \
 * ⁠  15   7
 * 
 * 
 * 返回其自底向上的层次遍历为：
 * 
 * [
 * ⁠ [15,7],
 * ⁠ [9,20],
 * ⁠ [3]
 * ]
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
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        vector<vector<int>> ans;
        if(!root){
            return ans;
        }
        queue<TreeNode*> que;
        queue<TreeNode*> Q;
        stack<vector<int>> sta;
        TreeNode* cur = root;
        // sta.push(cur);
        que.push(cur);
        while(!que.empty()){
            vector<int> one;
            while(!que.empty()){
                cur = que.front();
                que.pop();
                one.push_back(cur->val);
                if(cur->left){
                    Q.push(cur->left);
                    // sta.push(cur->left);
                }
                if(cur->right){
                    Q.push(cur->right);
                    // sta.push(cur->right);
                }
            }
            if(!one.empty())
                sta.push(one);
            vector<int> two;
            while(!Q.empty()){
                cur = Q.front();
                Q.pop();
                two.push_back(cur->val);
                if(cur->left){
                    que.push(cur->left);
                    // sta.push(cur->left);
                }
                if(cur->right){
                    que.push(cur->right);
                    // sta.push(cur->right);
                }
            }
            if(!two.empty())
                sta.push(two);
        }
        while(!sta.empty()){
            ans.push_back(sta.top());
            sta.pop();
        }
        return ans;
    }
};
// @lc code=end

