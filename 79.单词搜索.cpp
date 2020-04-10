/*
 * @lc app=leetcode.cn id=79 lang=cpp
 *
 * [79] 单词搜索
 *
 * https://leetcode-cn.com/problems/word-search/description/
 *
 * algorithms
 * Medium (41.05%)
 * Likes:    375
 * Dislikes: 0
 * Total Accepted:    50.5K
 * Total Submissions: 122.7K
 * Testcase Example:  '[["A","B","C","E"],["S","F","C","S"],["A","D","E","E"]]\n"ABCCED"'
 *
 * 给定一个二维网格和一个单词，找出该单词是否存在于网格中。
 * 
 * 单词必须按照字母顺序，通过相邻的单元格内的字母构成，其中“相邻”单元格是那些水平相邻或垂直相邻的单元格。同一个单元格内的字母不允许被重复使用。
 * 
 * 
 * 
 * 示例:
 * 
 * board =
 * [
 * ⁠ ['A','B','C','E'],
 * ⁠ ['S','F','C','S'],
 * ⁠ ['A','D','E','E']
 * ]
 * 
 * 给定 word = "ABCCED", 返回 true
 * 给定 word = "SEE", 返回 true
 * 给定 word = "ABCB", 返回 false
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * board 和 word 中只包含大写和小写英文字母。
 * 1 <= board.length <= 200
 * 1 <= board[i].length <= 200
 * 1 <= word.length <= 10^3
 * 
 * 
 */
#include "useforme.h"
// @lc code=start
class Solution {
public:
    bool explore(vector<int> pos, int cur, vector<vector<char>> board, string word, vector<vector<bool>>tags )
    {
        int m = pos[0];
        int n = pos[1];
        if(cur==word.size()-1){
            return true;
        }
        if(m+1<board.size()&&tags[m+1][n]!=true&&word[cur+1]==board[m+1][n]){
            tags[m+1][n] = true;
            // cur+1;
            pos[0]++;
            if(explore(pos, cur+1, board, word, tags))
                return true;
            tags[m+1][n] = false;
            // cur--;
            pos[0]--;
        }
        if(m-1>=0&&tags[m-1][n]!=true&&word[cur+1]==board[m-1][n]){
            tags[m-1][n] = true;
            // cur+1;
            pos[0]--;
            if(explore(pos, cur+1, board, word, tags))
                return true;
            tags[m-1][n] = false;
            // cur--;
            pos[0]++;
        }
        if(n+1<board[0].size()&&tags[m][n+1]!=true&&word[cur+1]==board[m][n+1]){
            tags[m][n+1] = true;
            // cur+1;
            pos[1]++;
            if(explore(pos, cur+1, board, word, tags))
                return true;
            tags[m][n+1] = false;
            // cur--;
            pos[1]--;
        }
        if(n-1>=0&&tags[m][n-1]!=true&&word[cur+1]==board[m][n-1]){
            cout<<"xyy ";
            tags[m][n-1] = true;
            // cur+1;
            pos[1]--;
            if(explore(pos, cur+1, board, word, tags))
                return true;
            tags[m][n-1] = false;
            // cur--;
            pos[1]++;
        }
        return false;
    }
    bool exist(vector<vector<char>>& board, string word) {
        vector<vector<bool>> tags(board.size(), vector<bool>(board[0].size(),false));
        for(int i = 0; i<board.size(); i++){
            for (int j = 0; j < board[0].size(); j++)
            {
                if(board[i][j]==word[0]){
                    vector<int> p;
                    p.push_back(i);
                    p.push_back(j);
                    tags[i][j]=true;
                    if(explore(p, 0, board, word, tags)){
                        return true;
                    }
                    tags[i][j]=false;

                }
            }
            
        }
        return false;
    }
};
// @lc code=end

