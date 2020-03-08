/*
 * @Description: 
 * @Version: 2.0
 * @Author: yunruowu
 * @Date: 2020-02-29 14:49:52
 * @LastEditors: yunruowu
 * @LastEditTime: 2020-03-08 23:12:14
 */
/*
 * @lc app=leetcode.cn id=671 lang=cpp
 *
 * [671] 二叉树中第二小的节点
 *
 * https://leetcode-cn.com/problems/second-minimum-node-in-a-binary-tree/description/
 *
 * algorithms
 * Easy (44.93%)
 * Likes:    60
 * Dislikes: 0
 * Total Accepted:    8.1K
 * Total Submissions: 17.8K
 * Testcase Example:  '[2,2,5,null,null,5,7]'
 *
 * 给定一个非空特殊的二叉树，每个节点都是正数，并且每个节点的子节点数量只能为 2 或
 * 0。如果一个节点有两个子节点的话，那么这个节点的值不大于它的子节点的值。 
 * 
 * 给出这样的一个二叉树，你需要输出所有节点中的第二小的值。如果第二小的值不存在的话，输出 -1 。
 * 
 * 示例 1:
 * 
 * 
 * 输入: 
 * ⁠   2
 * ⁠  / \
 * ⁠ 2   5
 * ⁠    / \
 * ⁠   5   7
 * 
 * 输出: 5
 * 说明: 最小的值是 2 ，第二小的值是 5 。
 * 
 * 
 * 示例 2:
 * 
 * 
 * 输入: 
 * ⁠   2
 * ⁠  / \
 * ⁠ 2   2
 * 
 * 输出: -1
 * 说明: 最小的值是 2, 但是不存在第二小的值。
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
    int findSecondMinimumValue(TreeNode* root) {
        int min_val = root->val;
        int min_temp = min_val+1;
        int tag = 0;
        queue<TreeNode*> que;
        que.push(root);
        TreeNode* cur;
        while (!que.empty())
        {
            cur=que.front();
            que.pop();
            if(cur->left){
                if(tag==0){
                    if(cur->left->val>min_val){
                        min_temp=cur->left->val;
                        if(cur->right->val<min_temp){
                            que.push(cur->right);
                        }
                        tag =1;
                    }else
                    {
                        if(cur->right->val>min_val){
                            min_temp=cur->right->val;
                            if(cur->left->val<min_temp){
                                que.push(cur->left);
                            }
                            tag = 1;
                        }
                    }
                    
                }
                else{
                    
                    if(cur->left->val<=min_temp){
                        if(cur->left->val==min_val){
                            que.push(cur->left);
                        }
                        else{ 
                            min_temp=min(min_temp,cur->left->val);
                            if(cur->right->val<min_temp){
                                que.push(cur->right);
                            }
                        }
                    }
                    if(cur->right->val<=min_temp){
                        if(cur->right->val==min_val){
                            que.push(cur->right);
                        }
                        else{
                            min_temp=min(cur->right->val,min_temp);
                            if(cur->left->val<min_temp){
                                que.push(cur->left);
                            }
                            
                        }
                        }
                }
            }
        }
        if(tag == 0)
            return -1;
        return min_temp;
    }
};
// @lc code=end

