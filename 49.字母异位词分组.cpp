/*
 * @lc app=leetcode.cn id=49 lang=cpp
 *
 * [49] 字母异位词分组
 *
 * https://leetcode-cn.com/problems/group-anagrams/description/
 *
 * algorithms
 * Medium (61.17%)
 * Likes:    313
 * Dislikes: 0
 * Total Accepted:    63.7K
 * Total Submissions: 104.1K
 * Testcase Example:  '["eat","tea","tan","ate","nat","bat"]'
 *
 * 给定一个字符串数组，将字母异位词组合在一起。字母异位词指字母相同，但排列不同的字符串。
 * 
 * 示例:
 * 
 * 输入: ["eat", "tea", "tan", "ate", "nat", "bat"],
 * 输出:
 * [
 * ⁠ ["ate","eat","tea"],
 * ⁠ ["nat","tan"],
 * ⁠ ["bat"]
 * ]
 * 
 * 说明：
 * 
 * 
 * 所有输入均为小写字母。
 * 不考虑答案输出的顺序。
 * 
 * 
 */
#include "useforme.h"
#include <unordered_map>
// @lc code=start
class Solution {
public:
    bool isGroup(vector<int> aMap, vector<int> bMap){
        for(int i = 0; i<26; i++){
            if(aMap[i]!=bMap[i])
                return false;
        }
        return true;
    }
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> ans;
        // vector<int>tags(strs.size(), 0);
        // vector<vector<int>> alpha;
        // for(int i = 0; i<strs.size(); i++){
        //     vector<int>curMap(26,0);
        //     for(int j = 0; j<strs[i].size(); j++){
        //         curMap[strs[i][j]-'a']++;
        //     }
        //     alpha.push_back(curMap);
        // }
        unordered_map<string, vector<string>> h;
        // cout<<1;
        vector<string> ins;
        for(int i = 0; i<strs.size(); i++){
            string temp = strs[i];
            sort(temp.begin(), temp.end());
            h[temp].push_back(strs[i]);
        }
        for(auto i:h)
        {
            ans.push_back(i.second);
        }
//时间通不过
        // for(int i = 0; i<strs.size(); i++){
        //     ins.clear();
        //     if(tags[i]!=0){
        //         continue;
        //     }
        //     else{
        //         ins.push_back(strs[i]);
        //         tags[i]=1;
        //         // cout<<1;
        //         // cout<<strs[i].size()<<endl;
        //         for(int j = i+1 ; j<strs.size();j++){
        //             // cout<<2;
        //             // cout<<strs[i].size()<<" "<<strs[j].size()<<endl;
        //             if(strs[i].size()==strs[j].size())
        //             {
        //                 if(isGroup(alpha[i], alpha[j]))
        //                 {
        //                     ins.push_back(strs[j]);
        //                     tags[j]=1;
        //                 }
        //             }
                        
        //         }
        //         ans.push_back(ins);
        //     }
        // }
        return ans;
    }
};
// @lc code=end

