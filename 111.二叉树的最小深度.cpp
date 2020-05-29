/*
 * @lc app=leetcode.cn id=111 lang=cpp
 *
 * [111] 二叉树的最小深度
 *
 * https://leetcode-cn.com/problems/minimum-depth-of-binary-tree/description/
 *
 * algorithms
 * Easy (41.88%)
 * Likes:    243
 * Dislikes: 0
 * Total Accepted:    67.2K
 * Total Submissions: 159.8K
 * Testcase Example:  '[3,9,20,null,null,15,7]'
 *
 * 给定一个二叉树，找出其最小深度。
 * 
 * 最小深度是从根节点到最近叶子节点的最短路径上的节点数量。
 * 
 * 说明: 叶子节点是指没有子节点的节点。
 * 
 * 示例:
 * 
 * 给定二叉树 [3,9,20,null,null,15,7],
 * 
 * ⁠   3
 * ⁠  / \
 * ⁠ 9  20
 * ⁠   /  \
 * ⁠  15   7
 * 
 * 返回它的最小深度  2.
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
    int minD = 9999;
    void getMinDepth(TreeNode* root, int nowdepth){
        cout<<minD<<nowdepth<<endl;
        if(!root->left&&!root->right)
        {   
            minD = min(minD, nowdepth);
            return ;
        }
        if(nowdepth>minD){
            return ;
        }
        if(root->left)
            getMinDepth(root->left, nowdepth+1);
        
        if(root->right){
            getMinDepth(root->right, nowdepth+1);
        }
        return ;
        
    }
    int minDepth(TreeNode* root) {
        int minL;
        if(!root)
            return 0;
        if(!root->left&&!root->right)
            return 1;
        if(root->left){
            getMinDepth(root->left, 1);
            // minL = minD +1 ;
        }
        if(root->right){
            getMinDepth(root->right, 1);
        }

        return minD+1;

    }
};
// @lc code=end

