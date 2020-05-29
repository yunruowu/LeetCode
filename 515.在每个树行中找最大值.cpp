/*
 * @lc app=leetcode.cn id=515 lang=cpp
 *
 * [515] 在每个树行中找最大值
 *
 * https://leetcode-cn.com/problems/find-largest-value-in-each-tree-row/description/
 *
 * algorithms
 * Medium (58.68%)
 * Likes:    60
 * Dislikes: 0
 * Total Accepted:    9.9K
 * Total Submissions: 16.6K
 * Testcase Example:  '[1,3,2,5,3,null,9]'
 *
 * 您需要在二叉树的每一行中找到最大的值。
 * 
 * 示例：
 * 
 * 
 * 输入: 
 * 
 * ⁠         1
 * ⁠        / \
 * ⁠       3   2
 * ⁠      / \   \  
 * ⁠     5   3   9 
 * 
 * 输出: [1, 3, 9]
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
    vector<int> largestValues(TreeNode* root) {
        TreeNode* cur;
        vector<int> ans;
        if(root==NULL)
            return ans;
        queue<TreeNode*> que;
        que.push(root);
        int s = 1;
        int val = INT_MIN;
        while(!que.empty()){
            int nows = s;
            s = 0;
            val = INT_MIN;
            // ans = que.front();
            while(nows>0){
                cur = que.front();
                val = max(val, cur->val);
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
            ans.push_back(val);
        }
        return ans;
    }
};
// @lc code=end

