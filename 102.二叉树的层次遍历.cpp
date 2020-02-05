/*
 * @Description: 
 * @Version: 2.0
 * @Author: yunruowu
 * @Date: 2020-02-02 10:27:54
 * @LastEditors  : yunruowu
 * @LastEditTime : 2020-02-02 11:11:36
 */
/*
 * @lc app=leetcode.cn id=102 lang=cpp
 *
 * [102] 二叉树的层次遍历
 *
 * https://leetcode-cn.com/problems/binary-tree-level-order-traversal/description/
 *
 * algorithms
 * Medium (60.07%)
 * Likes:    357
 * Dislikes: 0
 * Total Accepted:    73.1K
 * Total Submissions: 120.8K
 * Testcase Example:  '[3,9,20,null,null,15,7]'
 *
 * 给定一个二叉树，返回其按层次遍历的节点值。
 * （即逐层地，从左到右访问所有节点）。
 *
 * 例如:
 * 给定二叉树: [3,9,20,null,null,15,7],
 *
 * ⁠   3
 * ⁠  / \
 * ⁠ 9  20
 * ⁠   /  \
 * ⁠  15   7
 *
 *
 * 返回其层次遍历结果：
 *
 * [
 * ⁠ [3],
 * ⁠ [9,20],
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
    vector<vector<int>> levelOrder(TreeNode *root) {
        queue<TreeNode*> sQue;
        vector<vector<int>> ans;
        if(root == NULL){
            return ans;
        }
        sQue.push(root);
        int sum = 1;
        while(sQue.empty()!=true){
            int i = 0;
            vector<int> temp;
            while(sum>0){
                TreeNode * t = sQue.front();
                if(t->left!=NULL){
                    sQue.push(t->left);
                    i++;
                }
                if(t->right!=NULL){
                    sQue.push(t->right);
                    i++;
                }
                cout<<t->val<<" ";
                temp.push_back(t->val);
                sQue.pop();
                sum--;
                cout<<i<<sum<<endl;
            }
            ans.push_back(temp);
            sum = i;
            cout<<sum;
        }
        return ans;
    }
};
// @lc code=end
