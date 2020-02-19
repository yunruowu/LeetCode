/*
 * @Description: 
 * @Version: 2.0
 * @Author: yunruowu
 * @Date: 2020-02-19 21:38:28
 * @LastEditors: yunruowu
 * @LastEditTime: 2020-02-19 22:10:39
 */
/*
 * @lc app=leetcode.cn id=821 lang=cpp
 *
 * [821] 字符的最短距离
 *
 * https://leetcode-cn.com/problems/shortest-distance-to-a-character/description/
 *
 * algorithms
 * Easy (66.08%)
 * Likes:    100
 * Dislikes: 0
 * Total Accepted:    10.1K
 * Total Submissions: 15.3K
 * Testcase Example:  '"loveleetcode"\n"e"'
 *
 * 给定一个字符串 S 和一个字符 C。返回一个代表字符串 S 中每个字符到字符串 S 中的字符 C 的最短距离的数组。
 * 
 * 示例 1:
 * 
 * 
 * 输入: S = "loveleetcode", C = 'e'
 * 输出: [3, 2, 1, 0, 1, 0, 0, 1, 2, 2, 1, 0]
 * 
 * 
 * 说明:
 * 
 * 
 * 字符串 S 的长度范围为 [1, 10000]。
 * C 是一个单字符，且保证是字符串 S 里的字符。
 * S 和 C 中的所有字母均为小写字母。
 * 
 * 
 */
#include "useforme.h"
// @lc code=start
class Solution {
public:
    vector<int> shortestToChar(string S, char C) {
        int i = 0;
        int len = S.size();
        int nextC;
        vector<int> ans ;
        int nowE = -1;
        while(i<len){
            while(S[i]==C&&i<len){
                ans.push_back(0);
                nowE = i;
                i++;
                
            }
            
            int j = i;
            while(j<len&&S[j]!=C){
                j++;
            }
            if(S[j]==C){
                while(i<j){
                    if(nowE==-1){//最开始
                        ans.push_back(j-i);
                        i++;
                    }
                    else
                    {
                        ans.push_back(min(j-i,i-nowE));
                        i++;
                    }
                }
                
            }else
            {
                while(i<len){
                    if(nowE==-1){//最开始
                        ans.push_back(j-i);
                        i++;
                    }
                    else
                    {
                        ans.push_back(i-nowE);
                        i++;
                    }
                }
            }
            
        }
        return ans;
    }
};
// @lc code=end

