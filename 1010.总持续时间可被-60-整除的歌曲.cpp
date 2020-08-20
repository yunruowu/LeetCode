/*
 * @lc app=leetcode.cn id=1010 lang=cpp
 *
 * [1010] 总持续时间可被 60 整除的歌曲
 *
 * https://leetcode-cn.com/problems/pairs-of-songs-with-total-durations-divisible-by-60/description/
 *
 * algorithms
 * Easy (43.20%)
 * Likes:    103
 * Dislikes: 0
 * Total Accepted:    13.8K
 * Total Submissions: 32K
 * Testcase Example:  '[30,20,150,100,40]'
 *
 * 在歌曲列表中，第 i 首歌曲的持续时间为 time[i] 秒。
 * 
 * 返回其总持续时间（以秒为单位）可被 60 整除的歌曲对的数量。形式上，我们希望索引的数字 i 和 j 满足  i < j 且有 (time[i] +
 * time[j]) % 60 == 0。
 * 
 * 
 * 
 * 示例 1：
 * 
 * 输入：[30,20,150,100,40]
 * 输出：3
 * 解释：这三对的总持续时间可被 60 整数：
 * (time[0] = 30, time[2] = 150): 总持续时间 180
 * (time[1] = 20, time[3] = 100): 总持续时间 120
 * (time[1] = 20, time[4] = 40): 总持续时间 60
 * 
 * 
 * 示例 2：
 * 
 * 输入：[60,60,60]
 * 输出：3
 * 解释：所有三对的总持续时间都是 120，可以被 60 整数。
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 1 <= time.length <= 60000
 * 1 <= time[i] <= 500
 * 
 * 
 */
#include "useforme.h"
// @lc code=start
class Solution {
public:
    long long getp(int n){
        if(n==1||n==0){
            return 1;
        }
        return n*getp(n-1);
    }
    int numPairsDivisibleBy60(vector<int>& time) {
        int s=0;
        vector<int> a(60,0);
        for(int i=0;i<time.size();i++)
            a[time[i]%60]++;
        s=s+a[0]*(a[0]-1)/2+a[30]*(a[30]-1)/2;
        for(int j=1;j<30;j++)
            s=s+a[j]*a[60-j];            
        return s;
    }
};
// @lc code=end

