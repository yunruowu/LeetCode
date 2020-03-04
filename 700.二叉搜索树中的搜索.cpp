/*
 * @Description: 
 * @Version: 2.0
 * @Author: yunruowu
 * @Date: 2020-03-04 08:59:47
 * @LastEditors: yunruowu
 * @LastEditTime: 2020-03-04 09:08:26
 */
/*
 * @lc app=leetcode.cn id=700 lang=cpp
 *
 * [700] 二叉搜索树中的搜索
 *
 * https://leetcode-cn.com/problems/search-in-a-binary-search-tree/description/
 *
 * algorithms
 * Easy (71.79%)
 * Likes:    50
 * Dislikes: 0
 * Total Accepted:    18.4K
 * Total Submissions: 25.5K
 * Testcase Example:  '[4,2,7,1,3]\n2'
 *
 * 给定二叉搜索树（BST）的根节点和一个值。 你需要在BST中找到节点值等于给定值的节点。 返回以该节点为根的子树。 如果节点不存在，则返回 NULL。
 * 
 * 例如，
 * 
 * 
 * 给定二叉搜索树:
 * 
 * ⁠       4
 * ⁠      / \
 * ⁠     2   7
 * ⁠    / \
 * ⁠   1   3
 * 
 * 和值: 2
 * 
 * 
 * 你应该返回如下子树:
 * 
 * 
 * ⁠     2     
 * ⁠    / \   
 * ⁠   1   3
 * 
 * 
 * 在上述示例中，如果要找的值是 5，但因为没有节点值为 5，我们应该返回 NULL。
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
    // TreeNode* pre(TreeNode* root,int val){
    //     if(root==NULL){
    //         return NULL;
    //     }
    //     if(root->val == val){
    //         return root;
    //     }
    //     return 
    // }

    TreeNode* searchBST(TreeNode* root, int val) {
        queue<TreeNode*>que;
        if(root->val==val){
            return root;
        }
        que.push(root);
        TreeNode* cur;
        while(!que.empty()){
            cur = que.front();
            que.pop();
            if(cur->val == val){
                return cur;
            }
            if(cur->left)
                que.push(cur->left);
            if(cur->right)
                que.push(cur->right);
        }
        return NULL;
    }
};
// @lc code=end

