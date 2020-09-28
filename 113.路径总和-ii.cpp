/*
 * @lc app=leetcode.cn id=113 lang=cpp
 *
 * [113] 路径总和 II
 *
 * https://leetcode-cn.com/problems/path-sum-ii/description/
 *
 * algorithms
 * Medium (60.78%)
 * Likes:    331
 * Dislikes: 0
 * Total Accepted:    78.7K
 * Total Submissions: 128.7K
 * Testcase Example:  '[5,4,8,11,null,13,4,7,2,null,null,5,1]\n22'
 *
 * 给定一个二叉树和一个目标和，找到所有从根节点到叶子节点路径总和等于给定目标和的路径。
 * 
 * 说明: 叶子节点是指没有子节点的节点。
 * 
 * 示例:
 * 给定如下二叉树，以及目标和 sum = 22，
 * 
 * ⁠             5
 * ⁠            / \
 * ⁠           4   8
 * ⁠          /   / \
 * ⁠         11  13  4
 * ⁠        /  \    / \
 * ⁠       7    2  5   1
 * 
 * 
 * 返回:
 * 
 * [
 * ⁠  [5,4,11,2],
 * ⁠  [5,8,4,5]
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
    int tsum;
    vector<vector<int> > ans;
    void dfs(int sum, TreeNode* cur, vector<int> mem){
        if(cur->left == NULL&& cur->right==NULL){
            if(sum == tsum){
                // cout<<sum<<endl;
                ans.push_back(mem);
            }
            return;
        }
        // int r_bool=false,l_bool=false;
        if(cur->right!=NULL){
            vector<int> t = mem;
            mem.push_back(cur->right->val);
            dfs(sum + cur->right->val, cur->right, mem);
            mem.pop_back();
        }
        
        if(cur->left!=NULL){
            vector<int> t = mem;
            mem.push_back(cur->left->val);
            dfs(sum + cur->left->val, cur->left, mem);
            mem.pop_back();
            
        }
        // return r_bool || l_bool;
    }
    vector<vector<int>> pathSum(TreeNode* root, int sum) {
        vector<int> t;
        tsum = sum;
        // cout<<sum<<" "<<tsum;
        if(root!=NULL){
            t.push_back(root->val);

            dfs(root->val, root, t);
        }
        return ans;
    }
};
// @lc code=end

