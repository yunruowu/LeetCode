/*
 * @Description: 
 * @Version: 2.0
 * @Author: yunruowu
 * @Date: 2020-03-26 09:40:34
 * @LastEditors: yunruowu
 * @LastEditTime: 2020-03-26 09:53:20
 */
/*
 * @lc app=leetcode.cn id=908 lang=cpp
 *
 * [908] 最小差值 I
 *
 * https://leetcode-cn.com/problems/smallest-range-i/description/
 *
 * algorithms
 * Easy (67.21%)
 * Likes:    46
 * Dislikes: 0
 * Total Accepted:    9.8K
 * Total Submissions: 14.4K
 * Testcase Example:  '[1]\n0'
 *
 * 给定一个整数数组 A，对于每个整数 A[i]，我们可以选择任意 x 满足 -K <= x <= K，并将 x 加到 A[i] 中。
 * 
 * 在此过程之后，我们得到一些数组 B。
 * 
 * 返回 B 的最大值和 B 的最小值之间可能存在的最小差值。
 * 
 * 
 * 
 * 
 * 
 * 
 * 示例 1：
 * 
 * 输入：A = [1], K = 0
 * 输出：0
 * 解释：B = [1]
 * 
 * 
 * 示例 2：
 * 
 * 输入：A = [0,10], K = 2
 * 输出：6
 * 解释：B = [2,8]
 * 
 * 
 * 示例 3：
 * 
 * 输入：A = [1,3,6], K = 3
 * 输出：0
 * 解释：B = [3,3,3] 或 B = [4,4,4]
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 1 <= A.length <= 10000
 * 0 <= A[i] <= 10000
 * 0 <= K <= 10000
 * 
 * 
 */
#include "useforme.h"
// @lc code=start
class Solution {
public:
    int smallestRangeI(vector<int>& A, int K) {
        int minval = A[0];
        int maxval = A[0];
        for(int i = 0; i<A.size(); i++)
        {
            minval = min(minval, A[i]);
            maxval = max(maxval, A[i]);
        }
        return max(0, maxval-minval-2*K);
    }
};
// @lc code=end

