/*
 * @Description: ;
 * @Version: 2.0
 * @Author: yunruowu
 * @Date: 2020-03-08 23:17:18
 * @LastEditors: yunruowu
 * @LastEditTime: 2020-03-08 23:32:09
 */
/*
 * @lc app=leetcode.cn id=783 lang=cpp
 *
 * [783] 二叉搜索树结点最小距离
 *
 * https://leetcode-cn.com/problems/minimum-distance-between-bst-nodes/description/
 *
 * algorithms
 * Easy (51.61%)
 * Likes:    47
 * Dislikes: 0
 * Total Accepted:    9.4K
 * Total Submissions: 18K
 * Testcase Example:  '[4,2,6,1,3,null,null]'
 *
 * 给定一个二叉搜索树的根结点 root，返回树中任意两节点的差的最小值。
 * 
 * 
 * 
 * 示例：
 * 
 * 输入: root = [4,2,6,1,3,null,null]
 * 输出: 1
 * 解释:
 * 注意，root是树结点对象(TreeNode object)，而不是数组。
 * 
 * 给定的树 [4,2,6,1,3,null,null] 可表示为下图:
 * 
 * ⁠         4
 * ⁠       /   \
 * ⁠     2      6
 * ⁠    / \    
 * ⁠   1   3  
 * 
 * 最小的差值是 1, 它是节点1和节点2的差值, 也是节点3和节点2的差值。
 * 
 * 
 * 
 * 注意：
 * 
 * 
 * 二叉树的大小范围在 2 到 100。
 * 二叉树总是有效的，每个节点的值都是整数，且不重复。
 * 本题与 530：https://leetcode-cn.com/problems/minimum-absolute-difference-in-bst/
 * 相同
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
    int minval = 9999;
    int getLeftMaxVal(TreeNode* root){
        while(root->right!=NULL){
            root=root->right;
        }
        return root->val;
    }
    int getRightMinVal(TreeNode* root){
        while(root->left!=NULL){
            root = root -> left;
        }
        return root->val;
    }
    void minDiffInBST1(TreeNode* root) {
        if(root->left!=NULL){
            int l_max = getLeftMaxVal(root->left);
            cout<<l_max;
            minval = min(abs(root->val-l_max),minval);
            cout<<minval;
            minDiffInBST1(root->left);
        }
        if(root->right!=NULL){
            int r_min = getRightMinVal(root->right);
            minval = min(minval, abs(root->val-r_min));
            cout<<minval;
            minDiffInBST1(root->right);
        }
    }
    int minDiffInBST(TreeNode* root) {
        minDiffInBST1(root);
        return minval;
    }
};
// @lc code=end

