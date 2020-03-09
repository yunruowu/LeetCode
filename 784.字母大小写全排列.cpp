/*
 * @Description: 
 * @Version: 2.0
 * @Author: yunruowu
 * @Date: 2020-03-08 23:32:43
 * @LastEditors: yunruowu
 * @LastEditTime: 2020-03-09 00:19:40
 */
/*
 * @lc app=leetcode.cn id=784 lang=cpp
 *
 * [784] 字母大小写全排列
 *
 * https://leetcode-cn.com/problems/letter-case-permutation/description/
 *
 * algorithms
 * Easy (62.09%)
 * Likes:    146
 * Dislikes: 0
 * Total Accepted:    14.7K
 * Total Submissions: 23.3K
 * Testcase Example:  '"a1b2"'
 *
 * 给定一个字符串S，通过将字符串S中的每个字母转变大小写，我们可以获得一个新的字符串。返回所有可能得到的字符串集合。
 * 
 * 
 * 示例:
 * 输入: S = "a1b2"
 * 输出: ["a1b2", "a1B2", "A1b2", "A1B2"]
 * 
 * 输入: S = "3z4"
 * 输出: ["3z4", "3Z4"]
 * 
 * 输入: S = "12345"
 * 输出: ["12345"]
 * 
 * 
 * 注意：
 * 
 * 
 * S 的长度不超过12。
 * S 仅由数字和字母组成。
 * 
 * 
 */
#include "useforme.h"
// @lc code=start
class Solution {
public:
    vector<string> letterCasePermutation(string S) {
        vector<string> ans;
        // ans.push_back(S);
        if(S.empty()){
            return ans;
        }
        ans.push_back("");
        // if(isalpha(S[0])){
        //     cout<<1;
        //     if(isupper(S[0])){
        //         ans.push_back(S[0]+"");
        //         ans.push_back((char)tolower(S[0])+"");
        //     }else{
        //         cout<<2;
        //         ans.push_back(S[0]+"");
        //         // string temp = ""+char(toupper(S[0]));
        //         toupper(S[0]);
        //         ans.push_back((S[0])+"");
        //     }
        // }else{
        //     cout<<1;
        //     ans.push_back(S[0]+"");
        // }
        cout<<1;
        for(int i = 0; i<S.size(); i++){
            if(isalpha(S[i])){
                int size = ans.size();
                for(int j=0;j<size;j++){
                    string temp = ans[j];
                    if(isupper(S[i])){
                        ans[j]=temp+S[i];
                        // cout<<1;
                        ans.push_back(temp + (char)tolower(S[i]));
                        // ans.push_back(tolower(S[0])+"");
                    }else{
                        ans[j]=temp + S[i];
                        ans.push_back(temp + (char)toupper(S[i]));
                    }
                }
            }else{
                for(int j=0;j<ans.size();j++){
                    ans[j]=ans[j]+S[i];
                }
            }
        }
        return ans;
    }
};
// @lc code=end

