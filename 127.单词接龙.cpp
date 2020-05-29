/*
 * @lc app=leetcode.cn id=127 lang=cpp
 *
 * [127] 单词接龙
 *
 * https://leetcode-cn.com/problems/word-ladder/description/
 *
 * algorithms
 * Medium (40.84%)
 * Likes:    276
 * Dislikes: 0
 * Total Accepted:    32.7K
 * Total Submissions: 79.5K
 * Testcase Example:  '"hit"\n"cog"\n["hot","dot","dog","lot","log","cog"]'
 *
 * 给定两个单词（beginWord 和 endWord）和一个字典，找到从 beginWord 到 endWord
 * 的最短转换序列的长度。转换需遵循如下规则：
 * 
 * 
 * 每次转换只能改变一个字母。
 * 转换过程中的中间单词必须是字典中的单词。
 * 
 * 
 * 说明:
 * 
 * 
 * 如果不存在这样的转换序列，返回 0。
 * 所有单词具有相同的长度。
 * 所有单词只由小写字母组成。
 * 字典中不存在重复的单词。
 * 你可以假设 beginWord 和 endWord 是非空的，且二者不相同。
 * 
 * 
 * 示例 1:
 * 
 * 输入:
 * beginWord = "hit",
 * endWord = "cog",
 * wordList = ["hot","dot","dog","lot","log","cog"]
 * 
 * 输出: 5
 * 
 * 解释: 一个最短转换序列是 "hit" -> "hot" -> "dot" -> "dog" -> "cog",
 * ⁠    返回它的长度 5。
 * 
 * 
 * 示例 2:
 * 
 * 输入:
 * beginWord = "hit"
 * endWord = "cog"
 * wordList = ["hot","dot","dog","lot","log"]
 * 
 * 输出: 0
 * 
 * 解释: endWord "cog" 不在字典中，所以无法进行转换。
 * 
 */
#include "useforme.h"
// @lc code=start
class Solution {
public:
    vector<int> used;
    bool diff(string A, string B)
    {
        int sum = 0;  
        // cout<<A<<" "<<B<<endl;
        for(int i=0; i<A.size();i++){
            if(A[i]!=B[i])
            {    
                sum++;
                if(sum>=2){
                    return false;
                }
            }
                
        }
        if(sum == 1)
            return true;
        return false;
    }
    int val = 990;
    void get(string nowWord, string endWord,vector<string> wordList,vector<int> tag ,int length)
    {
        // cout<<nowWord<<endl;
        if(nowWord==endWord){
            val = min(val, length);
            // cout<<"xyy";
            return ;
        }
        if(length>val||length>wordList.size()){
            return ;
        }
        // cout<<wordList.size();
        for(int i =wordList.size()-1 ; i>=0; i--){
            // cout<<wordList[i]<<endl;
            if(tag[i]==0&&diff(nowWord, wordList[i]))
            {
                tag[i] = 1;
                get(wordList[i], endWord, wordList,tag, length+1);
                tag[i] = 0;
            }
        }
        // cout<<1;
        return;
    }
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        for(int i = 0; i<wordList.size(); i++){
            used.push_back(0);
        }
        //  超时
        get(beginWord,endWord,wordList,used, 0);
        if(val == 990)
            return 0;
        return val+1;
        // queue<string> que;
        // que.push(beginWord);
        // while(!que.empty()){

        // }
    }
};
// @lc code=end

