/*
 * @lc app=leetcode.cn id=1189 lang=cpp
 *
 * [1189] “气球” 的最大数量
 *
 * https://leetcode-cn.com/problems/maximum-number-of-balloons/description/
 *
 * algorithms
 * Easy (63.62%)
 * Likes:    42
 * Dislikes: 0
 * Total Accepted:    13.8K
 * Total Submissions: 21.8K
 * Testcase Example:  '"nlaebolko"'
 *
 * 给你一个字符串 text，你需要使用 text 中的字母来拼凑尽可能多的单词 "balloon"（气球）。
 * 
 * 字符串 text 中的每个字母最多只能被使用一次。请你返回最多可以拼凑出多少个单词 "balloon"。
 * 
 * 
 * 
 * 示例 1：
 * 
 * 
 * 
 * 输入：text = "nlaebolko"
 * 输出：1
 * 
 * 
 * 示例 2：
 * 
 * 
 * 
 * 输入：text = "loonbalxballpoon"
 * 输出：2
 * 
 * 
 * 示例 3：
 * 
 * 输入：text = "leetcode"
 * 输出：0
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 1 <= text.length <= 10^4
 * text 全部由小写英文字母组成
 * 
 * 
 */
#include "useforme.h"
// @lc code=start
class Solution {
public:
    int maxNumberOfBalloons(string text) {
        vector<int> alp(5,0);//(a,b,l,n,o)
        for(int i=0; i<text.length(); i++){
            switch (text[i])
            {
            case 'a':
                alp[0]++;
                break;
            case 'b':
                alp[1]++;
                break;
            case 'l':
                alp[2]++;
                break;
            case 'n':
                alp[3]++;
                break;
            case 'o':
                alp[4]++;
                break;
            default:
                break;
            }
        }
        alp[2]/=2;
        alp[4]/=2;
        int ans = 100000;
        for(int i = 0; i < alp.size(); i++){
            ans = min(ans,alp[i]);
        }
        return ans;
    }
};
// @lc code=end

