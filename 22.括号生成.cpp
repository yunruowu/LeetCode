/*
 * @lc app=leetcode.cn id=22 lang=cpp
 *
 * [22] 括号生成
 *
 * https://leetcode-cn.com/problems/generate-parentheses/description/
 *
 * algorithms
 * Medium (73.75%)
 * Likes:    839
 * Dislikes: 0
 * Total Accepted:    94.3K
 * Total Submissions: 127.8K
 * Testcase Example:  '3'
 *
 * 给出 n 代表生成括号的对数，请你写出一个函数，使其能够生成所有可能的并且有效的括号组合。
 * 
 * 例如，给出 n = 3，生成结果为：
 * 
 * [
 * ⁠ "((()))",
 * ⁠ "(()())",
 * ⁠ "(())()",
 * ⁠ "()(())",
 * ⁠ "()()()"
 * ]
 * 
 * 
 */
#include "useforme.h"
// @lc code=start
class Solution {
public:
    vector <string >res;
    void DFS(string path, int lc, int lr,int n){
        if(lc<lr || lc>n||lr>n) 
            return;
        if(lr == lc && lc == n){
            res.push_back(path);
            return;
        }
        DFS(path+'(', lc+1, lr, n);
        DFS(path+')', lc, lr+1, n);
        
    }
    vector<string> generateParenthesis(int n) {
        int lc = 0, lr = 0;
        DFS("", lc, lr, n);
        return res;
    }
};
// @lc code=end

