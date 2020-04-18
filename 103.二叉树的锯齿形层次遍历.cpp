/*
 * @lc app=leetcode.cn id=103 lang=cpp
 *
 * [103] 二叉树的锯齿形层次遍历
 *
 * https://leetcode-cn.com/problems/binary-tree-zigzag-level-order-traversal/description/
 *
 * algorithms
 * Medium (54.03%)
 * Likes:    178
 * Dislikes: 0
 * Total Accepted:    43.1K
 * Total Submissions: 79.6K
 * Testcase Example:  '[3,9,20,null,null,15,7]'
 *
 * 给定一个二叉树，返回其节点值的锯齿形层次遍历。（即先从左往右，再从右往左进行下一层遍历，以此类推，层与层之间交替进行）。
 * 
 * 例如：
 * 给定二叉树 [3,9,20,null,null,15,7],
 * 
 * ⁠   3
 * ⁠  / \
 * ⁠ 9  20
 * ⁠   /  \
 * ⁠  15   7
 * 
 * 
 * 返回锯齿形层次遍历如下： 
 * 
 * [
 * ⁠ [3],
 * ⁠ [20,9],
 * ⁠ [15,7]
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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        stack<TreeNode*> que;
        stack<TreeNode*> sta;
        vector<vector<int>> ans;
        TreeNode * cur = root;
        if(!cur)
            return ans;
        sta.push(cur);
        while(! que.empty()||!sta.empty()){
            
            vector<int> RtoL;
            while(!sta.empty()){
                cur = sta.top();
                RtoL.push_back(cur->val);
                sta.pop();
                if(cur->left){
                    que.push(cur->left);
                }
                if(cur->right){
                    que.push(cur->right);
                }
                
            }
            if(!RtoL.empty())
                ans.push_back(RtoL);
            vector<int> LtoR;
            while(! que.empty()){
                cur = que.top();
                LtoR.push_back(cur->val);
                que.pop();
                if(cur->right){
                    sta.push(cur->right);
                }
                if(cur->left){
                    sta.push(cur->left);
                }
                
            }
            // ans.push_back(LtoR);
            if(!LtoR.empty())
                ans.push_back(LtoR);
        }
        return ans;
    }
};
// @lc code=end

