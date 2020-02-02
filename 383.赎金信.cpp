/*
 * @Description: 
 * @Version: 2.0
 * @Author: yunruowu
 * @Date: 2020-02-01 13:38:32
 * @LastEditors  : yunruowu
 * @LastEditTime : 2020-02-01 14:14:16
 */
/*
 * @lc app=leetcode.cn id=383 lang=cpp
 *
 * [383] 赎金信
 *
 * https://leetcode-cn.com/problems/ransom-note/description/
 *
 * algorithms
 * Easy (51.33%)
 * Likes:    68
 * Dislikes: 0
 * Total Accepted:    15.6K
 * Total Submissions: 30.2K
 * Testcase Example:  '"a"\n"b"'
 *
 * 给定一个赎金信 (ransom)
 * 字符串和一个杂志(magazine)字符串，判断第一个字符串ransom能不能由第二个字符串magazines里面的字符构成。如果可以构成，返回
 * true ；否则返回 false。
 * 
 * (题目说明：为了不暴露赎金信字迹，要从杂志上搜索各个需要的字母，组成单词来表达意思。)
 * 
 * 注意：
 * 
 * 你可以假设两个字符串均只含有小写字母。
 * 
 * 
 * canConstruct("a", "b") -> false
 * canConstruct("aa", "ab") -> false
 * canConstruct("aa", "aab") -> true
 * 
 * 
 */
#include <string>
using namespace std;
// @lc code=start
class Solution {
public:
    bool canConstructone(string ransomNote, string magazine) {
        for(int i = 0;i<ransomNote.size();i++){
            int index = magazine.find(ransomNote[i]);
            if(index == -1){
                return 0;
            }
            magazine.erase(magazine.begin()+index);
        }
        return 1;
    }
    bool canConstruct(string ransomNote, string magazine){
        int ransom[26]={0};
        for(int i = 0;i<ransomNote.size();i++){
            ransom[ransomNote[i]-'a']++;
        }
        int maganum[26]={0};
        for(int i = 0; i < magazine.size();i++){
            maganum[magazine[i]-'a']++;
        }
        for(int i = 0 ; i<26 ; i++){
            if(ransom[i]>maganum[i]){
                return false;
            }
        }
        return true;
        
    }
};
// @lc code=end

