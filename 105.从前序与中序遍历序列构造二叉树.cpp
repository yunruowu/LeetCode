/*
 * @lc app=leetcode.cn id=105 lang=cpp
 *
 * [105] 从前序与中序遍历序列构造二叉树
 *
 * https://leetcode-cn.com/problems/construct-binary-tree-from-preorder-and-inorder-traversal/description/
 *
 * algorithms
 * Medium (64.66%)
 * Likes:    534
 * Dislikes: 0
 * Total Accepted:    86.5K
 * Total Submissions: 128.8K
 * Testcase Example:  '[3,9,20,15,7]\n[9,3,15,20,7]'
 *
 * 根据一棵树的前序遍历与中序遍历构造二叉树。
 * 
 * 注意:
 * 你可以假设树中没有重复的元素。
 * 
 * 例如，给出
 * 
 * 前序遍历 preorder = [3,9,20,15,7]
 * 中序遍历 inorder = [9,3,15,20,7]
 * 
 * 返回如下的二叉树：
 * 
 * ⁠   3
 * ⁠  / \
 * ⁠ 9  20
 * ⁠   /  \
 * ⁠  15   7
 * 
 */
# include "useforme.h"
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
    vector<int> preorder,inorder;
    TreeNode* getTree(int s1, int e1, int s2, int e2) {
        if(s1==e1)
            return NULL;
        TreeNode* temp=new TreeNode(preorder[s1]);//以头节点创建新的树
        if(e1-s1==1){
            return temp;
        }
        int r_val = preorder[s1];
        int root_pos;
        for (int i = s2; i < e2; i++)
        {
            if(r_val == inorder[i])
            {
                root_pos = i;
                break;
            }
        }
        
        temp->left = getTree(s1+1, s1+1+(root_pos-s2), s2, root_pos);
        temp->right = getTree(s1+1+(root_pos-s2), e1, root_pos+1, e2);
        return temp;
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        this->inorder = inorder;
        this->preorder = preorder;
        if( preorder.size()==0)
        {
            return NULL;
        }
        return getTree(0, preorder.size(),0,inorder.size());
        // return ans;
    }
};
// @lc code=end

