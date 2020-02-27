/*
 * @Description: 
 * @Version: 2.0
 * @Author: yunruowu
 * @Date: 2020-02-27 10:55:25
 * @LastEditors: yunruowu
 * @LastEditTime: 2020-02-27 11:14:06
 */
/*
 * @lc app=leetcode.cn id=606 lang=cpp
 *
 * [606] 根据二叉树创建字符串
 *
 * https://leetcode-cn.com/problems/construct-string-from-binary-tree/description/
 *
 * algorithms
 * Easy (52.23%)
 * Likes:    97
 * Dislikes: 0
 * Total Accepted:    9K
 * Total Submissions: 17K
 * Testcase Example:  '[1,2,3,4]'
 *
 * 你需要采用前序遍历的方式，将一个二叉树转换成一个由括号和整数组成的字符串。
 * 
 * 空节点则用一对空括号 "()" 表示。而且你需要省略所有不影响字符串与原始二叉树之间的一对一映射关系的空括号对。
 * 
 * 示例 1:
 * 
 * 
 * 输入: 二叉树: [1,2,3,4]
 * ⁠      1
 * ⁠    /   \
 * ⁠   2     3
 * ⁠  /    
 * ⁠ 4     
 * 
 * 输出: "1(2(4))(3)"
 * 
 * 解释: 原本将是“1(2(4)())(3())”，
 * 在你省略所有不必要的空括号对之后，
 * 它将是“1(2(4))(3)”。
 * 
 * 
 * 示例 2:
 * 
 * 
 * 输入: 二叉树: [1,2,3,null,4]
 * ⁠      1
 * ⁠    /   \
 * ⁠   2     3
 * ⁠    \  
 * ⁠     4 
 * 
 * 输出: "1(2()(4))(3)"
 * 
 * 解释: 和第一个示例相似，
 * 除了我们不能省略第一个对括号来中断输入和输出之间的一对一映射关系。
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
    string ans;
    void pre(TreeNode* t) {
        if(t == NULL){
            return ;
        }
        ans += to_string(t->val);
        if(t->left){
            ans+='(';
            pre(t->left);
            ans+=')';
            if(t->right){
                
                ans+='(';
                pre(t->right);
                ans+=')';
            }
        }
        else{
            if(t->right){
                ans+='(';

    
                ans+=')';
                ans+='(';
                pre(t->right);
                ans+=')';
            }
        }
        
        
        return ;
    }
    string tree2str(TreeNode* t) {
        pre(t);
        return ans;
    }
    
};
// @lc code=end

