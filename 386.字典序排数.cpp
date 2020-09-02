/*
 * @lc app=leetcode.cn id=386 lang=cpp
 *
 * [386] 字典序排数
 *
 * https://leetcode-cn.com/problems/lexicographical-numbers/description/
 *
 * algorithms
 * Medium (71.47%)
 * Likes:    120
 * Dislikes: 0
 * Total Accepted:    11.8K
 * Total Submissions: 16.4K
 * Testcase Example:  '13'
 *
 * 给定一个整数 n, 返回从 1 到 n 的字典顺序。
 * 
 * 例如，
 * 
 * 给定 n =1 3，返回 [1,10,11,12,13,2,3,4,5,6,7,8,9] 。
 * 
 * 请尽可能的优化算法的时间复杂度和空间复杂度。 输入的数据 n 小于等于 5,000,000。
 * 
 */
#include "useforme.h"
// @lc code=start
class Solution {
public:
    vector<int> lexicalOrder(int n) {
        vector<int> ans(n);
        int cur = 1;  
        for(int i = 0; i < n; i++){
            ans[i]=cur;
            if(cur*10<=n){
                cur = cur*10;
            }
            else{
                if(cur<n){
                    cur++;
                }else{
                    cur = cur/10;
                    cur++;
                }
                while(cur%10==0){
                    cur/=10;
                }
            }
        }
        return ans;
    }
};
// @lc code=end

