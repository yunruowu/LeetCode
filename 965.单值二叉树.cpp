/*
 * @lc app=leetcode.cn id=965 lang=cpp
 *
 * [965] 单值二叉树
 *
 * https://leetcode-cn.com/problems/univalued-binary-tree/description/
 *
 * algorithms
 * Easy (67.33%)
 * Likes:    48
 * Dislikes: 0
 * Total Accepted:    14.9K
 * Total Submissions: 22.1K
 * Testcase Example:  '[1,1,1,1,1,null,1]'
 *
 * 如果二叉树每个节点都具有相同的值，那么该二叉树就是单值二叉树。
 * 
 * 只有给定的树是单值二叉树时，才返回 true；否则返回 false。
 * 
 * 
 * 
 * 示例 1：
 * 
 * 
 * 
 * 输入：[1,1,1,1,1,null,1]
 * 输出：true
 * 
 * 
 * 示例 2：
 * 
 * 
 * 
 * 输入：[2,2,2,5,2]
 * 输出：false
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 给定树的节点数范围是 [1, 100]。
 * 每个节点的值都是整数，范围为 [0, 99] 。
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
    bool isUnivalTree(TreeNode* root) {
        if(root==NULL){
            return true;
        }
        int a = root->val;
        queue<TreeNode*> que;
        que.push(root);
        TreeNode* cur = root;
        while(que.empty()!=true){
            cur = que.front();
            cout<<cur->val<<endl;
            if(cur->left){
                if(cur->left->val!=a){
                    return false;
                }
                que.push(cur->left);
            }
            if(cur->right){
                if(cur->right->val!=a){
                    return false;
                }
                que.push(cur->right);
            }
            que.pop();
        }
        return true;
    }
};
// @lc code=end

