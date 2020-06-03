/*
 * @lc app=leetcode.cn id=93 lang=cpp
 *
 * [93] 复原IP地址
 *
 * https://leetcode-cn.com/problems/restore-ip-addresses/description/
 *
 * algorithms
 * Medium (46.23%)
 * Likes:    272
 * Dislikes: 0
 * Total Accepted:    43.9K
 * Total Submissions: 93.8K
 * Testcase Example:  '"25525511135"'
 *
 * 给定一个只包含数字的字符串，复原它并返回所有可能的 IP 地址格式。
 * 
 * 有效的 IP 地址正好由四个整数（每个整数位于 0 到 255 之间组成），整数之间用 '.' 分隔。
 * 
 * 
 * 
 * 示例:
 * 
 * 输入: "25525511135"
 * 输出: ["255.255.11.135", "255.255.111.35"]
 * 
 */
#include "useforme.h"
// @lc code=start
class Solution {
public:
    string str;
    vector<string> ans;
    void dfs(int cur,int numOfPoint, string now){
        if(numOfPoint==3){
            if(cur>=str.size())
                return;
            int fin = atoi(str.substr(cur, str.size()-cur).c_str());
            
            if(fin>=0 && fin<256){
                if(str.size()-cur==1||str[cur]!='0')
                {
                    now += str.substr(cur, str.size()-cur);
                    ans.push_back(now);
                }
            }
            return ;
        }
        for(int i = 1; i<3&&cur+i<str.size(); i++){
            if(i == 1){
                dfs(cur+i, numOfPoint+1, now + str.substr(cur, i)+'.');
            }
            if(i == 2&&str[cur]!='0'){
                dfs(cur+i, numOfPoint+1, now + str.substr(cur, i)+'.');
            }
        }
        if(cur+3<str.size()){
            int fina = atoi(str.substr(cur, 3).c_str());
        
            if(fina>=0 && fina<256&&str[cur]!='0'){
                dfs(cur+3, numOfPoint+1, now + str.substr(cur, 3)+'.');
            }
        
        }
    }
    vector<string> restoreIpAddresses(string s) {
        str = s;
        dfs(0,0,"");
        return ans;
    }
};
// @lc code=end

