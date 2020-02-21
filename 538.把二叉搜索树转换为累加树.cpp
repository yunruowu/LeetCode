/*
 * @Description: 
 * @Version: 2.0
 * @Author: yunruowu
 * @Date: 2020-02-20 21:58:35
 * @LastEditors: yunruowu
 * @LastEditTime: 2020-02-20 22:39:51
 */
/*
 * @lc app=leetcode.cn id=538 lang=cpp
 *
 * [538] 把二叉搜索树转换为累加树
 *
 * https://leetcode-cn.com/problems/convert-bst-to-greater-tree/description/
 *
 * algorithms
 * Easy (58.09%)
 * Likes:    202
 * Dislikes: 0
 * Total Accepted:    16.1K
 * Total Submissions: 27.6K
 * Testcase Example:  '[5,2,13]'
 *
 * 给定一个二叉搜索树（Binary Search Tree），把它转换成为累加树（Greater
 * Tree)，使得每个节点的值是原来的节点值加上所有大于它的节点值之和。
 * 
 * 例如：
 * 
 * 
 * 输入: 二叉搜索树:
 * ⁠             5
 * ⁠           /   \
 * ⁠          2     13
 * 
 * 输出: 转换为累加树:
 * ⁠            18
 * ⁠           /   \
 * ⁠         20     13
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
    TreeNode* convertBST(TreeNode* root) {
        stack<TreeNode*> sta;
        // sta.push(root);
        int pre = 0;
        TreeNode* cur = root;
        while(!sta.empty()|| cur){
            if(cur!=NULL){
                sta.push(cur);
                cur = cur -> right;
            }
            else{
                cur = sta.top();
                sta.pop();
                cur->val +=pre;
                pre = cur->val;  
                
                cur = cur->left;
            }
            
            
        }
        return root;
    }
};
// @lc code=end

