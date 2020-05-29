/*
 * @lc app=leetcode.cn id=199 lang=cpp
 *
 * [199] 二叉树的右视图
 *
 * https://leetcode-cn.com/problems/binary-tree-right-side-view/description/
 *
 * algorithms
 * Medium (63.94%)
 * Likes:    168
 * Dislikes: 0
 * Total Accepted:    24.7K
 * Total Submissions: 38.6K
 * Testcase Example:  '[1,2,3,null,5,null,4]'
 *
 * 给定一棵二叉树，想象自己站在它的右侧，按照从顶部到底部的顺序，返回从右侧所能看到的节点值。
 * 
 * 示例:
 * 
 * 输入: [1,2,3,null,5,null,4]
 * 输出: [1, 3, 4]
 * 解释:
 * 
 * ⁠  1            <---
 * ⁠/   \
 * 2     3         <---
 * ⁠\     \
 * ⁠ 5     4       <---
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
    vector<int> rightSideView(TreeNode* root) {
        
        vector<int> ans;
        if(!root)
            return ans;
        TreeNode* cur = root;
        queue<TreeNode*> que;
        // queue<TreeNode*> que1;
        que.push(cur);
        int num = 1;
        int temp_size = 0;
        while(!que.empty()){
            cur = que.front();
            que.pop();
            num--;
            if(cur->left){
                que.push(cur->left);
                temp_size++;
            }
            if(cur->right){
                que.push(cur->right);
                temp_size++;
            }
            if(num == 0){
                num = temp_size;
                ans.push_back(cur->val);
                temp_size = 0;
            }
        }
        return ans;
    }
};
// @lc code=end

