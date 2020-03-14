/*
 * @Description: 
 * @Version: 2.0
 * @Author: yunruowu
 * @Date: 2020-03-13 10:14:01
 * @LastEditors: yunruowu
 * @LastEditTime: 2020-03-13 10:24:34
 */
/*
 * @lc app=leetcode.cn id=872 lang=cpp
 *
 * [872] 叶子相似的树
 *
 * https://leetcode-cn.com/problems/leaf-similar-trees/description/
 *
 * algorithms
 * Easy (61.84%)
 * Likes:    49
 * Dislikes: 0
 * Total Accepted:    9.8K
 * Total Submissions: 15.6K
 * Testcase Example:  '[3,5,1,6,2,9,8,null,null,7,4]\n[3,5,1,6,7,4,2,null,null,null,null,null,null,9,8]'
 *
 * 请考虑一颗二叉树上所有的叶子，这些叶子的值按从左到右的顺序排列形成一个 叶值序列 。
 * 
 * 
 * 
 * 举个例子，如上图所示，给定一颗叶值序列为 (6, 7, 4, 9, 8) 的树。
 * 
 * 如果有两颗二叉树的叶值序列是相同，那么我们就认为它们是 叶相似 的。
 * 
 * 如果给定的两个头结点分别为 root1 和 root2 的树是叶相似的，则返回 true；否则返回 false 。
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 给定的两颗树可能会有 1 到 100 个结点。
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
    vector<int> DFS(TreeNode* root){
        stack<TreeNode*> sta;
        vector<int> leaf;
        sta.push(root);
        if(root==NULL)
            return leaf;
        TreeNode* cur;
        while(!sta.empty()){
            cur = sta.top();
            sta.pop();
            if(cur->right){
                sta.push(cur->right);
            }
            if(cur->left){
                sta.push(cur->left);
            }
            if(!cur->left&&!cur->right){
                leaf.push_back(cur->val);
            }
        }
        return leaf;
    }
    bool leafSimilar(TreeNode* root1, TreeNode* root2) {
        vector<int> leaf1 = DFS(root1);
        vector<int> leaf2 = DFS(root2);
        return leaf1==leaf2;
    }
};
// @lc code=end

