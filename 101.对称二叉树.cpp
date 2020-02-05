/*
 * @Description: 
 * @Version: 2.0
 * @Author: yunruowu
 * @Date: 2020-02-04 20:00:27
 * @LastEditors  : yunruowu
 * @LastEditTime : 2020-02-04 20:35:50
 */
/*
 * @lc app=leetcode.cn id=101 lang=cpp
 *
 * [101] 对称二叉树
 *
 * https://leetcode-cn.com/problems/symmetric-tree/description/
 *
 * algorithms
 * Easy (49.70%)
 * Likes:    589
 * Dislikes: 0
 * Total Accepted:    89.1K
 * Total Submissions: 179.2K
 * Testcase Example:  '[1,2,2,3,4,4,3]'
 *
 * 给定一个二叉树，检查它是否是镜像对称的。
 * 
 * 例如，二叉树 [1,2,2,3,4,4,3] 是对称的。
 * 
 * ⁠   1
 * ⁠  / \
 * ⁠ 2   2
 * ⁠/ \ / \
 * 3  4 4  3
 * 
 * 
 * 但是下面这个 [1,2,2,null,3,null,3] 则不是镜像对称的:
 * 
 * ⁠   1
 * ⁠  / \
 * ⁠ 2   2
 * ⁠  \   \
 * ⁠  3    3
 * 
 * 
 * 说明:
 * 
 * 如果你可以运用递归和迭代两种方法解决这个问题，会很加分。
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
    bool isMirror(TreeNode* t1, TreeNode* t2){
        if(t1 == NULL && t2 == NULL){
            return true;
        }
        if(t1==NULL || t2==NULL){
            return false;
        }
        else
        {
            return t1->val==t2->val && isMirror(t1->left,t2->right) && isMirror(t1->right, t2->left);
        }
        

    }
    bool isSymmetric(TreeNode* root) {
        
        return isMirror(root,root);
    }
};
// @lc code=end

