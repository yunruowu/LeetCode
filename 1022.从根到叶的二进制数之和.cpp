/*
 * @lc app=leetcode.cn id=1022 lang=cpp
 *
 * [1022] 从根到叶的二进制数之和
 *
 * https://leetcode-cn.com/problems/sum-of-root-to-leaf-binary-numbers/description/
 *
 * algorithms
 * Easy (65.12%)
 * Likes:    68
 * Dislikes: 0
 * Total Accepted:    9.7K
 * Total Submissions: 14.8K
 * Testcase Example:  '[1,0,1,0,1,0,1]'
 *
 * 给出一棵二叉树，其上每个结点的值都是 0 或 1 。每一条从根到叶的路径都代表一个从最高有效位开始的二进制数。例如，如果路径为 0 -> 1 -> 1
 * -> 0 -> 1，那么它表示二进制数 01101，也就是 13 。
 * 
 * 对树上的每一片叶子，我们都要找出从根到该叶子的路径所表示的数字。
 * 
 * 以 10^9 + 7 为模，返回这些数字之和。
 * 
 * 
 * 
 * 示例：
 * 
 * 
 * 
 * 输入：[1,0,1,0,1,0,1]
 * 输出：22
 * 解释：(100) + (101) + (110) + (111) = 4 + 5 + 6 + 7 = 22
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 树中的结点数介于 1 和 1000 之间。
 * node.val 为 0 或 1 。
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
    int sumRootToLeaf(TreeNode* root) {
        // int sum = 0;
        stack<TreeNode*> sta;
        sta.push(root);
        TreeNode* cur;
        int ans = 0;
        if(root==NULL){
            return 0;
        }
        while (!sta.empty()) {
            cur = sta.top();
            // sum = sum*2+cur->val;
            sta.pop();
            if(cur->left){
                cur->left->val += cur->val* 2 ;
                sta.push(cur->left);
            }
            if(cur->right){
                cur->right->val += cur->val* 2 ;
                sta.push(cur->right);
            }
            if(cur->left==NULL&& cur->right==NULL){
                ans += cur->val;
                
            }
        }
        
        return ans;
    }
};
// @lc code=end

