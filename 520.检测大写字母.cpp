/*
 * @Description: 
 * @Version: 2.0
 * @Author: yunruowu
 * @Date: 2020-02-19 14:49:22
 * @LastEditors: yunruowu
 * @LastEditTime: 2020-02-19 15:42:51
 */
/*
 * @lc app=leetcode.cn id=520 lang=cpp
 *
 * [520] 检测大写字母
 *
 * https://leetcode-cn.com/problems/detect-capital/description/
 *
 * algorithms
 * Easy (54.34%)
 * Likes:    77
 * Dislikes: 0
 * Total Accepted:    15.1K
 * Total Submissions: 27.7K
 * Testcase Example:  '"USA"'
 *
 * 给定一个单词，你需要判断单词的大写使用是否正确。
 * 
 * 我们定义，在以下情况时，单词的大写用法是正确的：
 * 
 * 
 * 全部字母都是大写，比如"USA"。
 * 单词中所有字母都不是大写，比如"leetcode"。
 * 如果单词不只含有一个字母，只有首字母大写， 比如 "Google"。
 * 
 * 
 * 否则，我们定义这个单词没有正确使用大写字母。
 * 
 * 示例 1:
 * 
 * 
 * 输入: "USA"
 * 输出: True
 * 
 * 
 * 示例 2:
 * 
 * 
 * 输入: "FlaG"
 * 输出: False
 * 
 * 
 * 注意: 输入是由大写和小写拉丁字母组成的非空单词。
 * 
 */
#include "useforme.h"
// @lc code=start
class Solution {
public:
    bool isA(char s){
        return s-'A'>=0 && s-'A'<26;
    }
    bool detectCapitalUse(string word) {
        int len = word.size();
        if(len==1){
            return 1;
        }
        // cout<<word[0]<<isA(word[0])<<endl;
        if(isA(word[0])==true){//第一个大写
            cout<<0;
            if(isA(word[1])==true){//第二个大写
                for(int i = 2; i<len; i++){//其他小写
                    cout<<"1";
                    if(isA(word[i])==false){
                        // cout<<"sds";
                        return false;
                    }
                    
                }
                return true;
            }else{
                cout<<"2";    
                for(int i = 2; i<len; i++){//其他大写
                    if(isA(word[i])){
                        cout<<"weew";
                        return false;
                    }
                
                } 
                return true;
            }
        }else{//第一个小写
        cout<<"3";
            for(int i = 1; i<len; i++){//全部小写
                if(isA(word[i])){
                    return false;
                }
            }
            return true;
        }
        cout<<"sds";
        return false;
    }
};
// @lc code=end

