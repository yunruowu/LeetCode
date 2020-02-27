/*
 * @Description: 
 * @Version: 2.0
 * @Author: yunruowu
 * @Date: 2020-02-27 11:15:56
 * @LastEditors: yunruowu
 * @LastEditTime: 2020-02-27 21:33:31
 */
/*
 * @lc app=leetcode.cn id=617 lang=cpp
 *
 * [617] 合并二叉树
 *
 * https://leetcode-cn.com/problems/merge-two-binary-trees/description/
 *
 * algorithms
 * Easy (74.67%)
 * Likes:    305
 * Dislikes: 0
 * Total Accepted:    35.6K
 * Total Submissions: 47.4K
 * Testcase Example:  '[1,3,2,5]\n[2,1,3,null,4,null,7]'
 *
 * 给定两个二叉树，想象当你将它们中的一个覆盖到另一个上时，两个二叉树的一些节点便会重叠。
 * 
 * 你需要将他们合并为一个新的二叉树。合并的规则是如果两个节点重叠，那么将他们的值相加作为节点合并后的新值，否则不为 NULL
 * 的节点将直接作为新二叉树的节点。
 * 
 * 示例 1:
 * 
 * 
 * 输入: 
 * Tree 1                     Tree 2                  
 * ⁠         1                         2                             
 * ⁠        / \                       / \                            
 * ⁠       3   2                     1   3                        
 * ⁠      /                           \   \                      
 * ⁠     5                             4   7                  
 * 输出: 
 * 合并后的树:
 * 3
 * / \
 * 4   5
 * / \   \ 
 * 5   4   7
 * 
 * 
 * 注意: 合并必须从两个树的根节点开始。
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
    TreeNode *ans = new TreeNode(0);
    int pre_together(TreeNode*t1, TreeNode* t2,TreeNode* cur){
        TreeNode *l = new TreeNode(0);
        TreeNode *r = new TreeNode(0);
        cur->right = r;
        cur->left = l;
        if(t1&&t2){
            cur->val=t1->val+t2->val;
            // cout<<t1->val<<t2->val<<endl;
            
            int l_tag = pre_together(t1->left,t2->left,cur->left);

            int r_tag = pre_together(t1->right,t2->right,cur->right);
            if(l_tag == -1){
                delete cur->left;
                cur->left = NULL;
            }
            if(r_tag == -1){
                delete cur->right;
                
                cur->right = NULL;
            }
            return 0 ;
        }
        if(t1&&!t2){
            cur->val = t1->val;
            // cout<<t1->val<<endl;
            int l_tag = pre_together(t1->left,NULL,cur->left);
            int r_tag = pre_together(t1->right,NULL,cur->right);
            if(l_tag == -1){
                delete cur->left;
                cur->left = NULL;
            }
            if(r_tag == -1){
                delete cur->right;
                
                cur->right = NULL;
            }
            return 0 ;
        }
        if(!t1&&t2){
            cur->val = t2->val;
            // cout<<t2->val<<endl;
            int l_tag = pre_together(NULL,t2->left,cur->left);
            int r_tag = pre_together(NULL,t2->right,cur->right);
            if(l_tag == -1){
                delete cur->left;
                cur->left = NULL;
            }
            if(r_tag == -1){
                delete cur->right;
                
                cur->right = NULL;
            }
            return 0 ;
        }
        if(!t1&&!t2){
            // cout<<"NULL"<<endl;
            cur->left = NULL;
            cur->right = NULL;
            // cur->val = -1;
            memset(&cur, 0, sizeof(TreeNode));
            // delete cur;
            // cur = NULL;
            return -1;
        }
        return 0;
    }
    TreeNode* mergeTrees(TreeNode* t1, TreeNode* t2) {
        if(!t1&&!t2){
            return NULL;
        }
        pre_together(t1,t2,ans);
        return ans;
    }
};
// @lc code=end

