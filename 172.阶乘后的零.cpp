/*
 * @Description: 
 * @Version: 2.0
 * @Author: yunruowu
 * @Date: 2020-02-06 11:29:07
 * @LastEditors  : yunruowu
 * @LastEditTime : 2020-02-06 11:40:06
 */
/*
 * @lc app=leetcode.cn id=172 lang=cpp
 *
 * [172] 阶乘后的零
 *
 * https://leetcode-cn.com/problems/factorial-trailing-zeroes/description/
 *
 * algorithms
 * Easy (39.51%)
 * Likes:    201
 * Dislikes: 0
 * Total Accepted:    26.4K
 * Total Submissions: 66.7K
 * Testcase Example:  '3'
 *
 * 给定一个整数 n，返回 n! 结果尾数中零的数量。
 * 
 * 示例 1:
 * 
 * 输入: 3
 * 输出: 0
 * 解释: 3! = 6, 尾数中没有零。
 * 
 * 示例 2:
 * 
 * 输入: 5
 * 输出: 1
 * 解释: 5! = 120, 尾数中有 1 个零.
 * 
 * 说明: 你算法的时间复杂度应为 O(log n) 。
 * 
 */
#include "useforme.h"
// @lc code=start
class Solution {
public:
    int trailingZeroes(int n) {
        int sum = 0;
        while(n!=0){
            sum += n/5;
            n = n/5;
        }
        return sum;
    }
};
// @lc code=end

int main(int argc, char const *argv[])
{
    Solution s;
    cout<<s.trailingZeroes(25);
    return 0;
}

