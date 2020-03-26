/*
 * @Description:
 * @Version: 2.0
 * @Author: yunruowu
 * @Date: 2020-03-25 19:29:24
 * @LastEditors: yunruowu
 * @LastEditTime: 2020-03-25 21:47:22
 */
/*
 * @lc app=leetcode.cn id=897 lang=cpp
 *
 * [897] 递增顺序查找树
 *
 * https://leetcode-cn.com/problems/increasing-order-search-tree/description/
 *
 * algorithms
 * Easy (65.17%)
 * Likes:    62
 * Dislikes: 0
 * Total Accepted:    8.4K
 * Total Submissions: 12.7K
 * Testcase Example:  '[5,3,6,2,4,null,8,1,null,null,null,7,9]\r'
 *
 * 给你一个树，请你 按中序遍历 重新排列树，使树中最左边的结点现在是树的根，并且每个结点没有左子结点，只有一个右子结点。
 *
 *
 *
 * 示例 ：
 *
 * 输入：[5,3,6,2,4,null,8,1,null,null,null,7,9]
 *
 * ⁠      5
 * ⁠     / \
 * ⁠   3    6
 * ⁠  / \    \
 * ⁠ 2   4    8
 * /        / \
 * 1        7   9
 *
 * 输出：[1,null,2,null,3,null,4,null,5,null,6,null,7,null,8,null,9]
 *
 * ⁠1
 * \
 * 2
 * \
 * 3
 * \
 * 4
 * \
 * 5
 * \
 * 6
 * \
 * 7
 * \
 * 8
 * \
 * ⁠                9
 *
 *
 *
 * 提示：
 *
 *
 * 给定树中的结点数介于 1 和 100 之间。
 * 每个结点都有一个从 0 到 1000 范围内的唯一整数值。
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
    TreeNode* increasingBST(TreeNode* root) {
        stack<TreeNode*> sta;
        // sta.push(root);
        // TreeNode* newR = new TreeNode(0);
        // TreeNode* pos = newR;
        vector<TreeNode*> ans;
        TreeNode* cur = root;
        while(!sta.empty()||cur!=NULL){
            // cout<<cur->val;
            if(cur!=NULL){
                sta.push(cur);
                cur = cur->left;
            }
            else{
                cur = sta.top();
                if(cur!=NULL)
                    ans.push_back(cur);
                sta.pop();
                cur = cur->right;
            }
        }
        // cout<<1;
        ans[0]->left = NULL;
        root = ans[0];
        cur = root;
        // root->left = NULL;
        int i = 1;
        while(i<ans.size())
        {
            // cout<<ans[i]->val;
            ans[i]->left = NULL;
            cur->right = ans[i];
            // cur->left = NULL;
            cur = cur->right;
            // if(cur->left)
            //     cout<<0;
            i++;
        }
        // cur=NULL;
        return root;
    }
};
// @lc code=end
