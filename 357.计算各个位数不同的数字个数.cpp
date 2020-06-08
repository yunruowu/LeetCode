/*
 * @lc app=leetcode.cn id=357 lang=cpp
 *
 * [357] 计算各个位数不同的数字个数
 *
 * https://leetcode-cn.com/problems/count-numbers-with-unique-digits/description/
 *
 * algorithms
 * Medium (50.81%)
 * Likes:    62
 * Dislikes: 0
 * Total Accepted:    9.9K
 * Total Submissions: 19.4K
 * Testcase Example:  '2'
 *
 * 给定一个非负整数 n，计算各位数字都不同的数字 x 的个数，其中 0 ≤ x < 10^n 。
 * 
 * 示例:
 * 
 * 输入: 2
 * 输出: 91 
 * 解释: 答案应为除去 11,22,33,44,55,66,77,88,99 外，在 [0,100) 区间内的所有数字。
 * 
 * 
 */
#include "useforme.h"
// @lc code=start
class Solution {
public:
    int ans =1;
    int n;
    void dfs(int num,int cur, vector<int>tags){
        
        // for (int i = 0; i < tags.size(); i++)
        // {
        //     cout<<tags[i]<<" ";
        // }
        // cout<<endl;
        if(num == this->n){
            return ;
        }
        if(num == 0){
            for(int i = 1; i<10; i++){
                
                // cout<<10*cur+/i<<endl;
                if(tags[i]==0){
                    tags[i] = 1;
                    ans++;
                    dfs(num+1, 10*cur+i, tags);
                    tags[i] = 0;
                }
            }
        }else{
            for(int i = 0; i<10; i++){
                
                // cout<<10*cur+i<<endl;
                if(tags[i]==0){
                    tags[i] = 1;
                    ans++;
                    dfs(num+1,10*cur+i, tags);
                    tags[i] = 0;
                }
            }
        }
        return;
    }
    int countNumbersWithUniqueDigits(int n) {
        this->n = n;
        if(n>10){
            return 0;
        }
        
        vector<int> tags(10, 0);

        dfs(0,0,tags);
        return ans;
    }
};
// @lc code=end

