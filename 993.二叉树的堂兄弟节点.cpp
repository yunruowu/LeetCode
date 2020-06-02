/*
 * @lc app=leetcode.cn id=993 lang=cpp
 *
 * [993] 二叉树的堂兄弟节点
 *
 * https://leetcode-cn.com/problems/cousins-in-binary-tree/description/
 *
 * algorithms
 * Easy (51.07%)
 * Likes:    67
 * Dislikes: 0
 * Total Accepted:    8.8K
 * Total Submissions: 17.1K
 * Testcase Example:  '[1,2,3,4]\n4\n3'
 *
 * 在二叉树中，根节点位于深度 0 处，每个深度为 k 的节点的子节点位于深度 k+1 处。
 *
 * 如果二叉树的两个节点深度相同，但父节点不同，则它们是一对堂兄弟节点。
 *
 * 我们给出了具有唯一值的二叉树的根节点 root，以及树中两个不同节点的值 x 和 y。
 *
 * 只有与值 x 和 y 对应的节点是堂兄弟节点时，才返回 true。否则，返回 false。
 *
 *
 *
 * 示例 1：
 *
 *
 * 输入：root = [1,2,3,4], x = 4, y = 3
 * 输出：false
 *
 *
 * 示例 2：
 *
 *
 * 输入：root = [1,2,3,null,4,null,5], x = 5, y = 4
 * 输出：true
 *
 *
 * 示例 3：
 *
 *
 *
 * 输入：root = [1,2,3,null,4], x = 2, y = 3
 * 输出：false
 *
 *
 *
 * 提示：
 *
 *
 * 二叉树的节点数介于 2 到 100 之间。
 * 每个节点的值都是唯一的、范围为 1 到 100 的整数。
 *
 *
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
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    struct mes
    {
        int nowPos;
        TreeNode *parent;
    };

    mes getPos(TreeNode*root, int x){
        mes ans;
        TreeNode* cur = root;
        queue<TreeNode*> que;
        int num = 1;
        que.push(cur);
        int pos = 0;
        while(que.empty()!=true){
            int len = 0;
            while(num!=0){
                cur = que.front();
                que.pop();
                if(cur->left)
                {
                    if(cur->left->val==x)
                    {
                        ans.nowPos = pos;
                        ans.parent = cur;
                        return ans;
                    }
                    que.push(cur->left);
                    len ++;
                }
                if(cur->right)
                {
                    if(cur->right->val==x)
                    {
                        ans.nowPos = pos;
                        ans.parent = cur;
                        return ans;
                    }
                    que.push(cur->right);
                    len ++;
                }
                num--;
            }
            pos++;
            num=len;
        }
        return ans;
    }
    bool isCousins(TreeNode* root, int x, int y) {
        mes m1, m2;
        if(root->val==x||root->val==y)
            return false;
        m1 = getPos(root, x);
        m2 = getPos(root, y);
        return (m1.parent != m2.parent && m1.nowPos == m2.nowPos);
    }
};
// @lc code=end

