/*
 * @Description: 
 * @Version: 2.0
 * @Author: yunruowu
 * @Date: 2020-03-11 09:39:04
 * @LastEditors: yunruowu
 * @LastEditTime: 2020-03-11 10:08:01
 */
/*
 * @lc app=leetcode.cn id=830 lang=cpp
 *
 * [830] 较大分组的位置
 *
 * https://leetcode-cn.com/problems/positions-of-large-groups/description/
 *
 * algorithms
 * Easy (45.38%)
 * Likes:    40
 * Dislikes: 0
 * Total Accepted:    8.1K
 * Total Submissions: 17.5K
 * Testcase Example:  '"abbxxxxzzy"'
 *
 * 在一个由小写字母构成的字符串 S 中，包含由一些连续的相同字符所构成的分组。
 * 
 * 例如，在字符串 S = "abbxxxxzyy" 中，就含有 "a", "bb", "xxxx", "z" 和 "yy" 这样的一些分组。
 * 
 * 我们称所有包含大于或等于三个连续字符的分组为较大分组。找到每一个较大分组的起始和终止位置。
 * 
 * 最终结果按照字典顺序输出。
 * 
 * 示例 1:
 * 
 * 
 * 输入: "abbxxxxzzy"
 * 输出: [[3,6]]
 * 解释: "xxxx" 是一个起始于 3 且终止于 6 的较大分组。
 * 
 * 
 * 示例 2:
 * 
 * 
 * 输入: "abc"
 * 输出: []
 * 解释: "a","b" 和 "c" 均不是符合要求的较大分组。
 * 
 * 
 * 示例 3:
 * 
 * 
 * 输入: "abcdddeeeeaabbbcd"
 * 输出: [[3,5],[6,9],[12,14]]
 * 
 * 说明:  1 <= S.length <= 1000
 * 
 */
#include "useforme.h"
// @lc code=start
class Solution {
public:
    vector<vector<int>> largeGroupPositions(string S) {
        vector<vector<int>> ans;
        
        int i = 1;
        int left = 0;
        int len = 1;
        while(i<S.size()){
            while(S[i]==S[left]&&i<S.size()){
                len++;
                i++;
                
            }
            if(len>=3){
                vector<int> ins;
                ins.push_back(left),
                ins.push_back(left+len-1);
                ans.push_back(ins);
            }
            left = i;
            i++;
            len = 1;
        }
        return ans;
    }
};
// @lc code=end

