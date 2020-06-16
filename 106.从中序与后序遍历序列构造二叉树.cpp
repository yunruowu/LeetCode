/*
 * @lc app=leetcode.cn id=106 lang=cpp
 *
 * [106] 从中序与后序遍历序列构造二叉树
 *
 * https://leetcode-cn.com/problems/construct-binary-tree-from-inorder-and-postorder-traversal/description/
 *
 * algorithms
 * Medium (67.62%)
 * Likes:    221
 * Dislikes: 0
 * Total Accepted:    38.8K
 * Total Submissions: 56.5K
 * Testcase Example:  '[9,3,15,20,7]\n[9,15,7,20,3]'
 *
 * 根据一棵树的中序遍历与后序遍历构造二叉树。
 * 
 * 注意:
 * 你可以假设树中没有重复的元素。
 * 
 * 例如，给出
 * 
 * 中序遍历 inorder = [9,3,15,20,7]
 * 后序遍历 postorder = [9,15,7,20,3]
 * 
 * 返回如下的二叉树：
 * 
 * ⁠   3
 * ⁠  / \
 * ⁠ 9  20
 * ⁠   /  \
 * ⁠  15   7
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
TreeNode* ans;
    vector<int> postorder,inorder;
    TreeNode* getTree(int s1, int e1, int s2, int e2) {
        if(s1==e1)
            return NULL;
        TreeNode* temp=new TreeNode(postorder[e1-1]);//以头节点创建新的树
        if(e1-s1==1){
            return temp;
        }
        int r_val = postorder[e1-1];
        int root_pos;
        for (int i = s2; i < e2; i++)
        {
            if(r_val == inorder[i])
            {
                root_pos = i;
                break;
            }
        }
        
        temp->left = getTree(s1, s1+(root_pos-s2), s2, root_pos);
        temp->right = getTree(s1+(root_pos-s2), e1-1, root_pos+1, e2);
        return temp;
    }
    
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        this->inorder = inorder;
        this->postorder = postorder;
        if( postorder.size()==0)
        {
            return NULL;
        }
        return getTree(0, postorder.size(),0,inorder.size());
    }
};
// @lc code=end

