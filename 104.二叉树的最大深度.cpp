/*
 * @Description: 
 * @Version: 2.0
 * @Author: yunruowu
 * @Date: 2020-02-02 11:13:43
 * @LastEditors  : yunruowu
 * @LastEditTime : 2020-02-02 11:31:55
 */
/*
 * @lc app=leetcode.cn id=104 lang=cpp
 *
 * [104] 二叉树的最大深度
 *
 * https://leetcode-cn.com/problems/maximum-depth-of-binary-tree/description/
 *
 * algorithms
 * Easy (71.59%)
 * Likes:    439
 * Dislikes: 0
 * Total Accepted:    117K
 * Total Submissions: 162.5K
 * Testcase Example:  '[3,9,20,null,null,15,7]'
 *
 * 给定一个二叉树，找出其最大深度。
 * 
 * 二叉树的深度为根节点到最远叶子节点的最长路径上的节点数。
 * 
 * 说明: 叶子节点是指没有子节点的节点。
 * 
 * 示例：
 * 给定二叉树 [3,9,20,null,null,15,7]，
 * 
 * ⁠   3
 * ⁠  / \
 * ⁠ 9  20
 * ⁠   /  \
 * ⁠  15   7
 * 
 * 返回它的最大深度 3 。
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
    int maxDepth(TreeNode* root) {
        int maxdepth  = 0;
        if(root==NULL){
            return 0;
        }
        queue<TreeNode *> treeQueue;
        treeQueue.push(root);
        int len = 1;
        while(treeQueue.empty()!=true)
        {
            int i = 0;
            while (len>0)
            {
                TreeNode* temp = treeQueue.front();
                if(temp->left!=NULL){
                    treeQueue.push(temp->left);
                    i++;
                }
                if(temp->right!=NULL){
                    treeQueue.push(temp->right);
                    i++;
                }
                treeQueue.pop();
                len--;
            }
            maxdepth++;
            cout<<maxdepth<<" ";    
            len = i;
        }
        return maxdepth;
    }
};
// @lc code=end

