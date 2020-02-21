/*
 * @Description: 
 * @Version: 2.0
 * @Author: yunruowu
 * @Date: 2020-02-21 09:32:50
 * @LastEditors: yunruowu
 * @LastEditTime: 2020-02-21 10:26:42
 */
/*
 * @lc app=leetcode.cn id=559 lang=cpp
 *
 * [559] N叉树的最大深度
 *
 * https://leetcode-cn.com/problems/maximum-depth-of-n-ary-tree/description/
 *
 * algorithms
 * Easy (67.99%)
 * Likes:    73
 * Dislikes: 0
 * Total Accepted:    16.4K
 * Total Submissions: 24K
 * Testcase Example:  '[1,null,3,2,4,null,5,6]\r'
 *
 * 给定一个 N 叉树，找到其最大深度。
 * 
 * 最大深度是指从根节点到最远叶子节点的最长路径上的节点总数。
 * 
 * 例如，给定一个 3叉树 :
 * 
 * 
 * 
 * 
 * 
 * 
 * 
 * 我们应返回其最大深度，3。
 * 
 * 说明:
 * 
 * 
 * 树的深度不会超过 1000。
 * 树的节点总不会超过 5000。
 * 
 */
#include "useforme.h"
// @lc code=start
/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/
class Solution {
public:

    //递归的方法
    int maxdepth =0;
    void getDepth(Node* root,int depth){
        if(root==NULL){
            return ;
        }
        if(depth>maxdepth){
            maxdepth=depth;
        }
        for(int i = 0 ;i<root->children.size();i++){
            getDepth(root->children[i],depth+1);
        }
    }

    //栈方法，没有递归快
    int StackDepth(Node* root){
        queue<Node*> que;
        Node* cur = root;
        que.push(root);
        int depth = 0;
        int len = 1;
        while(!que.empty()){
            int nextlen = 0;
            while(len>0){
                Node *temp = que.front();
                que.pop();
                for(int i = 0; i<temp->children.size();i++){
                    que.push(temp->children[i]);
                    nextlen++;
                }
                len--;
            }
            depth++;
            len = nextlen;
        }
        return depth;
    }
    int maxDepth(Node* root) {
        // getDepth(root,1);
        if(root==NULL){
            return 0;
        }
        return StackDepth(root);
    }
};
// @lc code=end

