/*
 * @Description: 
 * @Version: 2.0
 * @Author: yunruowu
 * @Date: 2020-02-22 21:57:19
 * @LastEditors: yunruowu
 * @LastEditTime: 2020-02-22 22:30:31
 */
/*
 * @lc app=leetcode.cn id=563 lang=cpp
 *
 * [563] 二叉树的坡度
 *
 * https://leetcode-cn.com/problems/binary-tree-tilt/description/
 *
 * algorithms
 * Easy (52.49%)
 * Likes:    48
 * Dislikes: 0
 * Total Accepted:    8.2K
 * Total Submissions: 15.6K
 * Testcase Example:  '[1,2,3]'
 *
 * 给定一个二叉树，计算整个树的坡度。
 * 
 * 一个树的节点的坡度定义即为，该节点左子树的结点之和和右子树结点之和的差的绝对值。空结点的的坡度是0。
 * 
 * 整个树的坡度就是其所有节点的坡度之和。
 * 
 * 示例:
 * 
 * 
 * 输入: 
 * ⁠        1
 * ⁠      /   \
 * ⁠     2     3
 * 输出: 1
 * 解释: 
 * 结点的坡度 2 : 0
 * 结点的坡度 3 : 0
 * 结点的坡度 1 : |2-3| = 1
 * 树的坡度 : 0 + 0 + 1 = 1
 * 
 * 
 * 注意:
 * 
 * 
 * 任何子树的结点的和不会超过32位整数的范围。
 * 坡度的值不会超过32位整数的范围。
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
    int tilt = 0;
    int sumOfNode(TreeNode* root){//节点的只和
        if(root == NULL){
            return 0;
        }
        if(!root->left&&!root->right){
            return root->val;
        }
        int l = sumOfNode(root->left) ;
        int r = sumOfNode(root->right);
        tilt += abs(l-r);
        return l + r + root->val;
    }
    int tiltOfNode(TreeNode* root){
        if(root == NULL){
            return 0;
        }
        return abs(sumOfNode(root->left)-sumOfNode(root->right));
    }
    
    int findTilt(TreeNode* root) {
        
        sumOfNode(root);
        
        return tilt;
    }
};
// @lc code=end

