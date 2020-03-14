/*
 * @Description: 
 * @Version: 2.0
 * @Author: yunruowu
 * @Date: 2020-03-13 09:10:22
 * @LastEditors: yunruowu
 * @LastEditTime: 2020-03-13 10:05:24
 */
/*
 * @lc app=leetcode.cn id=868 lang=cpp
 *
 * [868] 二进制间距
 *
 * https://leetcode-cn.com/problems/binary-gap/description/
 *
 * algorithms
 * Easy (59.92%)
 * Likes:    45
 * Dislikes: 0
 * Total Accepted:    8.1K
 * Total Submissions: 13.5K
 * Testcase Example:  '22'
 *
 * 给定一个正整数 N，找到并返回 N 的二进制表示中两个连续的 1 之间的最长距离。 
 * 
 * 如果没有两个连续的 1，返回 0 。
 * 
 * 
 * 
 * 
 * 
 * 
 * 示例 1：
 * 
 * 输入：22
 * 输出：2
 * 解释：
 * 22 的二进制是 0b10110 。
 * 在 22 的二进制表示中，有三个 1，组成两对连续的 1 。
 * 第一对连续的 1 中，两个 1 之间的距离为 2 。
 * 第二对连续的 1 中，两个 1 之间的距离为 1 。
 * 答案取两个距离之中最大的，也就是 2 。
 * 
 * 
 * 示例 2：
 * 
 * 输入：5
 * 输出：2
 * 解释：
 * 5 的二进制是 0b101 。
 * 
 * 
 * 示例 3：
 * 
 * 输入：6
 * 输出：1
 * 解释：
 * 6 的二进制是 0b110 。
 * 
 * 
 * 示例 4：
 * 
 * 输入：8
 * 输出：0
 * 解释：
 * 8 的二进制是 0b1000 。
 * 在 8 的二进制表示中没有连续的 1，所以返回 0 。
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 1 <= N <= 10^9
 * 
 * 
 */
#include "useforme.h"
// @lc code=start
class Solution {
public:
    vector<int> to_Binary(int N){
        vector<int> bin;
        int i = 0;
        while(N!=0){
            int a = N%2;
            if(a == 1)
                bin.push_back(i);
            N=N/2;
            i++;
        }
        return bin;
    }
    int binaryGap(int N) {
        vector<int> bin = to_Binary(N);
        if(bin.size()<=1){
            return 0;
        }
        int max_gap  =-1;
        for(int i = 0; i<bin.size()-1; i++){
            max_gap = max(max_gap, abs(bin[i]-bin[i+1]));
        }
        return max_gap;
    }
};
// @lc code=end

