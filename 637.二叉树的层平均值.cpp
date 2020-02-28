/*
 * @Description: 
 * @Version: 2.0
 * @Author: yunruowu
 * @Date: 2020-02-28 10:01:15
 * @LastEditors: yunruowu
 * @LastEditTime: 2020-02-28 10:27:06
 */
/*
 * @lc app=leetcode.cn id=637 lang=cpp
 *
 * [637] 二叉树的层平均值
 *
 * https://leetcode-cn.com/problems/average-of-levels-in-binary-tree/description/
 *
 * algorithms
 * Easy (62.70%)
 * Likes:    98
 * Dislikes: 0
 * Total Accepted:    13.8K
 * Total Submissions: 21.8K
 * Testcase Example:  '[3,9,20,15,7]'
 *
 * 给定一个非空二叉树, 返回一个由每层节点平均值组成的数组.
 * 
 * 示例 1:
 * 
 * 输入:
 * ⁠   3
 * ⁠  / \
 * ⁠ 9  20
 * ⁠   /  \
 * ⁠  15   7
 * 输出: [3, 14.5, 11]
 * 解释:
 * 第0层的平均值是 3,  第1层是 14.5, 第2层是 11. 因此返回 [3, 14.5, 11].
 * 
 * 
 * 注意：
 * 
 * 
 * 节点值的范围在32位有符号整数范围内。
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
    vector<double> averageOfLevels(TreeNode* root) {
        vector<double> ans;
        if(root==NULL){
            return ans;
        }
        queue<TreeNode*> que;
        TreeNode* cur = root;
        int len = 1;
        que.push(root);
        while (!que.empty())
        {
            double sum = 0.0;
            int new_len = 0;
            int l = len;
            while(len>0){
                cur = que.front();
                sum+=cur->val;
                que.pop();
                if(cur->left){
                    que.push(cur->left);
                    new_len++;
                }
                if(cur->right){
                    que.push(cur->right);
                    new_len++;
                }
                len--;
            }
            ans.push_back((sum/l));
            len=new_len;
        }
        return ans;
        

    }
};
// @lc code=end

