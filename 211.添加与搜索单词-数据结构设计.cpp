/*
 * @lc app=leetcode.cn id=211 lang=cpp
 *
 * [211] 添加与搜索单词 - 数据结构设计
 *
 * https://leetcode-cn.com/problems/add-and-search-word-data-structure-design/description/
 *
 * algorithms
 * Medium (43.63%)
 * Likes:    124
 * Dislikes: 0
 * Total Accepted:    11.4K
 * Total Submissions: 25.4K
 * Testcase Example:  '["WordDictionary","addWord","addWord","addWord","search","search","search","search"]\n[[],["bad"],["dad"],["mad"],["pad"],["bad"],[".ad"],["b.."]]'
 *
 * 设计一个支持以下两种操作的数据结构：
 * 
 * void addWord(word)
 * bool search(word)
 * 
 * 
 * search(word) 可以搜索文字或正则表达式字符串，字符串只包含字母 . 或 a-z 。 . 可以表示任何一个字母。
 * 
 * 示例:
 * 
 * addWord("bad")
 * addWord("dad")
 * addWord("mad")
 * search("pad") -> false
 * search("bad") -> true
 * search(".ad") -> true
 * search("b..") -> true
 * 
 * 
 * 说明:
 * 
 * 你可以假设所有单词都是由小写字母 a-z 组成的。
 * 
 */
#include "useforme.h"
// @lc code=start
class WordDictionary {
public:
    /** Initialize your data structure here. */
    vector<string> mem;
    int len;
    WordDictionary() {
        // vector<string> mem;
    }
    
    /** Adds a word into the data structure. */
    void addWord(string word) {
        mem.push_back(word);
    }
    
    /** Returns if the word is in the data structure. A word could contain the dot character '.' to represent any one letter. */
    bool search(string word) {
        int tag = 1;
        for(int i = 0; i<mem.size(); i++){
            tag = 1;
            if(word.size() != mem[i].size())
                tag = 0;
            for(int j = 0; j<mem[i].size(); j++)
            {
                cout<<word[j]<<mem[i][j]<<endl;
                if(word[j]=='.')
                    continue;
                if(word[j]!=mem[i][j])
                    tag = 0;
            }
            if(tag != 0)
                return true;
        }
        return false;
    }
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */
// @lc code=end

