/*
 * @lc app=leetcode.cn id=513 lang=cpp
 *
 * [513] 找树左下角的值
 *
 * https://leetcode-cn.com/problems/find-bottom-left-tree-value/description/
 *
 * algorithms
 * Medium (68.92%)
 * Likes:    76
 * Dislikes: 0
 * Total Accepted:    12.6K
 * Total Submissions: 18.3K
 * Testcase Example:  '[2,1,3]'
 *
 * 给定一个二叉树，在树的最后一行找到最左边的值。
 * 
 * 示例 1:
 * 
 * 
 * 输入:
 * 
 * ⁠   2
 * ⁠  / \
 * ⁠ 1   3
 * 
 * 输出:
 * 1
 * 
 * 
 * 
 * 
 * 示例 2: 
 * 
 * 
 * 输入:
 * 
 * ⁠       1
 * ⁠      / \
 * ⁠     2   3
 * ⁠    /   / \
 * ⁠   4   5   6
 * ⁠      /
 * ⁠     7
 * 
 * 输出:
 * 7
 * 
 * 
 * 
 * 
 * 注意: 您可以假设树（即给定的根节点）不为 NULL。
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
    int findBottomLeftValue(TreeNode* root) {
        TreeNode* cur;
        TreeNode* ans;
        queue<TreeNode*> que;
        que.push(root);
        int s = 1;
        while(!que.empty()){
            int nows = s;
            s = 0;
            ans = que.front();
            while(nows>0){
                cur = que.front();
                que.pop();
                if(cur->left)
                {
                    que.push(cur->left);
                    s++;
                }
                if(cur->right)
                {
                    que.push(cur->right);
                    s++;
                }
                nows--;
            }
        }
        return ans->val;
    }
};
// @lc code=end

