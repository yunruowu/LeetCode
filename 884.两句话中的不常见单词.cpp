/*
 * @Description: 
 * @Version: 2.0
 * @Author: yunruowu
 * @Date: 2020-03-14 10:40:10
 * @LastEditors: yunruowu
 * @LastEditTime: 2020-03-14 11:25:41
 */
/*
 * @lc app=leetcode.cn id=884 lang=cpp
 *
 * [884] 两句话中的不常见单词
 *
 * https://leetcode-cn.com/problems/uncommon-words-from-two-sentences/description/
 *
 * algorithms
 * Easy (60.20%)
 * Likes:    45
 * Dislikes: 0
 * Total Accepted:    8.5K
 * Total Submissions: 14K
 * Testcase Example:  '"this apple is sweet"\n"this apple is sour"'
 *
 * 给定两个句子 A 和 B 。 （句子是一串由空格分隔的单词。每个单词仅由小写字母组成。）
 * 
 * 如果一个单词在其中一个句子中只出现一次，在另一个句子中却没有出现，那么这个单词就是不常见的。
 * 
 * 返回所有不常用单词的列表。
 * 
 * 您可以按任何顺序返回列表。
 * 
 * 
 * 
 * 
 * 
 * 
 * 示例 1：
 * 
 * 输入：A = "this apple is sweet", B = "this apple is sour"
 * 输出：["sweet","sour"]
 * 
 * 
 * 示例 2：
 * 
 * 输入：A = "apple apple", B = "banana"
 * 输出：["banana"]
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 0 <= A.length <= 200
 * 0 <= B.length <= 200
 * A 和 B 都只包含空格和小写字母。
 * 
 * 
 */
#include "useforme.h"
// @lc code=start
class Solution {
public:
    vector<string> to_word(string S){
        int i =0;
        vector<string> word;
        string ins;
        while(i<S.size()){
            ins.clear();
            while(S[i]!=' '&&i<S.size()){
                ins +=S[i];
                i++;
            }
            word.push_back(ins);
            i++;
        }
        return word;
    }
    vector<string> uncommonFromSentences(string A, string B) {
        vector<string> wordA = to_word(A);
        vector<string> wordB = to_word(B);
        vector<string> ans;
        for(int i = 0; i<wordA.size(); i++){
            // cout<<wordA.rend()-find(wordA.rbegin(),wordA.rend(),wordA[i])<<" "<<i+1;
            if(find(wordB.begin(),wordB.end(),wordA[i])==wordB.end()){
                if((wordA.rend()-find(wordA.rbegin(),wordA.rend(),wordA[i]))==find(wordA.begin(),wordA.end(),wordA[i])-wordA.begin()+1)
                    ans.push_back(wordA[i]);
            }
        }
        // vector<string> ans;
        for(int i = 0; i<wordB.size(); i++){
            if(find(wordA.begin(),wordA.end(),wordB[i])==wordA.end()){
                if((wordB.rend()-find(wordB.rbegin(),wordB.rend(),wordB[i]))==find(wordB.begin(),wordB.end(),wordB[i])-wordB.begin()+1)
                    ans.push_back(wordB[i]);
            }
        }
        return ans;
    }
};
// @lc code=end

