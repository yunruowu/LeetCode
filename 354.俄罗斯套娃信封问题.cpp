/*
 * @lc app=leetcode.cn id=354 lang=cpp
 *
 * [354] 俄罗斯套娃信封问题
 *
 * https://leetcode-cn.com/problems/russian-doll-envelopes/description/
 *
 * algorithms
 * Hard (34.51%)
 * Likes:    156
 * Dislikes: 0
 * Total Accepted:    12.1K
 * Total Submissions: 33.8K
 * Testcase Example:  '[[5,4],[6,4],[6,7],[2,3]]'
 *
 * 给定一些标记了宽度和高度的信封，宽度和高度以整数对形式 (w, h)
 * 出现。当另一个信封的宽度和高度都比这个信封大的时候，这个信封就可以放进另一个信封里，如同俄罗斯套娃一样。
 * 
 * 请计算最多能有多少个信封能组成一组“俄罗斯套娃”信封（即可以把一个信封放到另一个信封里面）。
 * 
 * 说明:
 * 不允许旋转信封。
 * 
 * 示例:
 * 
 * 输入: envelopes = [[5,4],[6,4],[6,7],[2,3]]
 * 输出: 3 
 * 解释: 最多信封的个数为 3, 组合为: [2,3] => [5,4] => [6,7]。
 * 
 * 
 */
#include "useforme.h"
// @lc code=start
class Solution {
public:
    int maxEnvelopes(vector<vector<int>>& envelopes) {
        int nums = envelopes.size();
        // 排序
        if(envelopes.size()==0)
            return 0;
        // for(int i = 0; i < nums; i++){
        //     for(int j = i+1; j< nums; j++){
        //         if(envelopes[i][0]>envelopes[j][0]){
        //             swap(envelopes[i], envelopes[j]);
        //         }else{
        //             if(envelopes[i][0]==envelopes[j][0]){
        //                 if(envelopes[i][1]>envelopes[j][1]){
        //                     swap(envelopes[i], envelopes[j]);
        //                 }
        //             }
        //         }
        //     }
        // }
        sort(envelopes.begin(),envelopes.end(),[](const vector<int>& a,const vector<int>& b){
            return a[0]<b[0]||(a[0]==b[0]&&a[1]>b[1]);
        });

        int ans = 1;
        vector<int> dp(nums, 1);
        for(int i = 1 ;i<nums; i++){
            for(int j = 0;j < i; j++){
                if(envelopes[i][0]>envelopes[j][0]&&envelopes[i][1]>envelopes[j][1])
                    dp[i] = max(dp[j]+1, dp[i]);
            }
            ans = max(ans, dp[i]);
        }
        return ans;
    }
};
// @lc code=end

