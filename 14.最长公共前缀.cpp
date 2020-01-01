/*
 * @Description: 
 * @Version: 2.0
 * @Author: yunruowu
 * @Date: 2019-12-31 08:53:18
 * @LastEditors  : yunruowu
 * @LastEditTime : 2019-12-31 09:10:20
 */
/*
 * @lc app=leetcode.cn id=14 lang=cpp
 *
 * [14] 最长公共前缀
 *
 * https://leetcode-cn.com/problems/longest-common-prefix/description/
 *
 * algorithms
 * Easy (35.62%)
 * Likes:    816
 * Dislikes: 0
 * Total Accepted:    165.5K
 * Total Submissions: 464.6K
 * Testcase Example:  '["flower","flow","flight"]'
 *
 * 编写一个函数来查找字符串数组中的最长公共前缀。
 * 
 * 如果不存在公共前缀，返回空字符串 ""。
 * 
 * 示例 1:
 * 
 * 输入: ["flower","flow","flight"]
 * 输出: "fl"
 * 
 * 
 * 示例 2:
 * 
 * 输入: ["dog","racecar","car"]
 * 输出: ""
 * 解释: 输入不存在公共前缀。
 * 
 * 
 * 说明:
 * 
 * 所有输入只包含小写字母 a-z 。
 * 
 */
#include<string>
#include<vector>
using namespace std;
// @lc code=start
class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        int n = strs.size();
        if(strs.size()==0){
            return "";
        }
        string ans ="";
        string s = strs[0];

        for(int i = 0;i<s.size();i++){
             
             for(int j = 1;j<n;j++){
                 if(i>strs[j].size()||strs[j][i]!=s[i]){
                     return ans;
                 }
                      
                 
            }
            ans.insert(ans.end(),s[i]) ;
        }
        return ans;
    }
};
// @lc code=end

