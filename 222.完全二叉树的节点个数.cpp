/*
 * @lc app=leetcode.cn id=222 lang=cpp
 *
 * [222] 完全二叉树的节点个数
 *
 * https://leetcode-cn.com/problems/count-complete-tree-nodes/description/
 *
 * algorithms
 * Medium (67.92%)
 * Likes:    165
 * Dislikes: 0
 * Total Accepted:    22.3K
 * Total Submissions: 32K
 * Testcase Example:  '[1,2,3,4,5,6]'
 *
 * 给出一个完全二叉树，求出该树的节点个数。
 * 
 * 说明：
 * 
 * 
 * 完全二叉树的定义如下：在完全二叉树中，除了最底层节点可能没填满外，其余每层节点数都达到最大值，并且最下面一层的节点都集中在该层最左边的若干位置。若最底层为第
 * h 层，则该层包含 1~ 2^h 个节点。
 * 
 * 示例:
 * 
 * 输入: 
 * ⁠   1
 * ⁠  / \
 * ⁠ 2   3
 * ⁠/ \  /
 * 4  5 6
 * 
 * 输出: 6
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
    int countNodes(TreeNode* root) {
        stack<TreeNode*> sta;
        if(!root)
            return 0;
        sta.push(root);
        TreeNode* cur;
        int ans = 1;
        while (!sta.empty())
        {
            cur = sta.top();
            sta.pop();
            if(cur->left)
            {
                ans++;
                sta.push(cur->left);
            }
            if(cur->right)
            {
                ans++;
                sta.push(cur->right);
            }
        }   
        return ans;
    }
};
// @lc code=end

int main(int argc, char const *argv[])
{
    cout<<1;
    ;
    return 0;
    // ;
}
