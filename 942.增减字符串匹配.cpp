/*
 * @lc app=leetcode.cn id=942 lang=cpp
 *
 * [942] 增减字符串匹配
 *
 * https://leetcode-cn.com/problems/di-string-match/description/
 *
 * algorithms
 * Easy (71.06%)
 * Likes:    115
 * Dislikes: 0
 * Total Accepted:    12.8K
 * Total Submissions: 18K
 * Testcase Example:  '"IDID"'
 *
 * 给定只含 "I"（增大）或 "D"（减小）的字符串 S ，令 N = S.length。
 * 
 * 返回 [0, 1, ..., N] 的任意排列 A 使得对于所有 i = 0, ..., N-1，都有：
 * 
 * 
 * 如果 S[i] == "I"，那么 A[i] < A[i+1]
 * 如果 S[i] == "D"，那么 A[i] > A[i+1]
 * 
 * 
 * 
 * 
 * 示例 1：
 * 
 * 输出："IDID"
 * 输出：[0,4,1,3,2]
 * 
 * 
 * 示例 2：
 * 
 * 输出："III"
 * 输出：[0,1,2,3]
 * 
 * 
 * 示例 3：
 * 
 * 输出："DDI"
 * 输出：[3,2,0,1]
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 1 <= S.length <= 10000
 * S 只包含字符 "I" 或 "D"。
 * 
 * 
 */
#include "useforme.h"
// @lc code=start
class Solution {
public:
    vector<int> diStringMatch(string S) {
        int N = S.size();
        int L = 0;
        int R = N;
        vector<int> ans;
        for(int i = 0; i<S.size(); i++){
            if(S[i]=='I'){
                ans.push_back(L);
                L++;
            }else{
                ans.push_back(R);
                R--;
            }
        }
        ans.push_back(L);
        return ans;
    }
};

// @lc code=end

