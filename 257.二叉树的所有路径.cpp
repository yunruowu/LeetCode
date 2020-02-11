/*
 * @Description: 
 * @Version: 2.0
 * @Author: yunruowu
 * @Date: 2020-02-10 14:02:46
 * @LastEditors  : yunruowu
 * @LastEditTime : 2020-02-10 14:36:26
 */
/*
 * @lc app=leetcode.cn id=257 lang=cpp
 *
 * [257] 二叉树的所有路径
 *
 * https://leetcode-cn.com/problems/binary-tree-paths/description/
 *
 * algorithms
 * Easy (61.64%)
 * Likes:    200
 * Dislikes: 0
 * Total Accepted:    23.7K
 * Total Submissions: 38.4K
 * Testcase Example:  '[1,2,3,null,5]'
 *
 * 给定一个二叉树，返回所有从根节点到叶子节点的路径。
 * 
 * 说明: 叶子节点是指没有子节点的节点。
 * 
 * 示例:
 * 
 * 输入:
 * 
 * ⁠  1
 * ⁠/   \
 * 2     3
 * ⁠\
 * ⁠ 5
 * 
 * 输出: ["1->2->5", "1->3"]
 * 
 * 解释: 所有根节点到叶子节点的路径为: 1->2->5, 1->3
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
    vector<string> ans;
    string str;
public:
    void through(TreeNode* root){
        
        str = str + to_string(root->val);
        ans.push_back(str);
        if(root->left){
            
            through(root->left);
        }
        if(root->right){
            through(root->right);
        }
        if(root->left == NULL && root->right == NULL){
            return;
        }
    }
    vector<string> binaryTreePaths(TreeNode* root) {
        
        through(root);
        return ans;
    }
};
// @lc code=end

