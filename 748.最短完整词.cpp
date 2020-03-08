/*
 * @Description: 
 * @Version: 2.0
 * @Author: yunruowu
 * @Date: 2020-03-07 16:01:47
 * @LastEditors: yunruowu
 * @LastEditTime: 2020-03-07 16:23:41
 */
/*
 * @lc app=leetcode.cn id=748 lang=cpp
 *
 * [748] 最短完整词
 *
 * https://leetcode-cn.com/problems/shortest-completing-word/description/
 *
 * algorithms
 * Easy (56.73%)
 * Likes:    22
 * Dislikes: 0
 * Total Accepted:    4.4K
 * Total Submissions: 7.7K
 * Testcase Example:  '"1s3 PSt"\n["step","steps","stripe","stepple"]'
 *
 * 
 * 如果单词列表（words）中的一个单词包含牌照（licensePlate）中所有的字母，那么我们称之为完整词。在所有完整词中，最短的单词我们称之为最短完整词。
 * 
 * 单词在匹配牌照中的字母时不区分大小写，比如牌照中的 "P" 依然可以匹配单词中的 "p" 字母。
 * 
 * 我们保证一定存在一个最短完整词。当有多个单词都符合最短完整词的匹配条件时取单词列表中最靠前的一个。
 * 
 * 牌照中可能包含多个相同的字符，比如说：对于牌照 "PP"，单词 "pair" 无法匹配，但是 "supper" 可以匹配。
 * 
 * 
 * 
 * 示例 1：
 * 
 * 输入：licensePlate = "1s3 PSt", words = ["step", "steps", "stripe", "stepple"]
 * 输出："steps"
 * 说明：最短完整词应该包括 "s"、"p"、"s" 以及 "t"。对于 "step" 它只包含一个 "s"
 * 所以它不符合条件。同时在匹配过程中我们忽略牌照中的大小写。
 * 
 * 
 * 
 * 示例 2：
 * 
 * 输入：licensePlate = "1s3 456", words = ["looks", "pest", "stew", "show"]
 * 输出："pest"
 * 说明：存在 3 个包含字母 "s" 且有着最短长度的完整词，但我们返回最先出现的完整词。
 * 
 * 
 * 
 * 
 * 注意:
 * 
 * 
 * 牌照（licensePlate）的长度在区域[1, 7]中。
 * 牌照（licensePlate）将会包含数字、空格、或者字母（大写和小写）。
 * 单词列表（words）长度在区间 [10, 1000] 中。
 * 每一个单词 words[i] 都是小写，并且长度在区间 [1, 15] 中。
 * 
 * 
 * 
 * 
 */
#include "useforme.h"
// @lc code=start
class Solution {
public:
    string shortestCompletingWord(string licensePlate, vector<string>& words) {
        int minlen = 9999;
        string ans;
        string L;
        for(int j = 0; j<licensePlate.size(); j++){
            if(isalpha(licensePlate[j])){
                if(isupper(licensePlate[j])){
                    L += tolower(licensePlate[j]);
                }else{
                    L += licensePlate[j];
                }
            }
        }
        licensePlate = L;
        cout<<licensePlate;
        for(int i = 0; i<words.size(); i++){
            string temp = words[i];
            if(temp.size()>=licensePlate.size()&&temp.size()<minlen){
                int tag = 0;
                for(int j = 0; j<licensePlate.size()&&tag==0; j++){
                    
                    if(find(temp.begin(),temp.end(),licensePlate[j])!=temp.end()){
                        temp[find(temp.begin(),temp.end(),licensePlate[j])-temp.begin()]=' ';
                    }else{
                        tag = 1;
                    }
                }
                if(tag == 0){
                    ans = words[i];
                    cout<<ans;
                    minlen = ans.size();
                }
            }
        }
        return ans;
    }
};
// @lc code=end

