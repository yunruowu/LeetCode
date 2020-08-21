/*
 * @lc app=leetcode.cn id=1013 lang=cpp
 *
 * [1013] 将数组分成和相等的三个部分
 *
 * https://leetcode-cn.com/problems/partition-array-into-three-parts-with-equal-sum/description/
 *
 * algorithms
 * Easy (40.35%)
 * Likes:    119
 * Dislikes: 0
 * Total Accepted:    36.9K
 * Total Submissions: 91.4K
 * Testcase Example:  '[0,2,1,-6,6,-7,9,1,2,0,1]'
 *
 * 给你一个整数数组 A，只有可以将其划分为三个和相等的非空部分时才返回 true，否则返回 false。
 * 
 * 形式上，如果可以找出索引 i+1 < j 且满足 A[0] + A[1] + ... + A[i] == A[i+1] + A[i+2] + ... +
 * A[j-1] == A[j] + A[j-1] + ... + A[A.length - 1] 就可以将数组三等分。
 * 
 * 
 * 
 * 示例 1：
 * 
 * 输入：[0,2,1,-6,6,-7,9,1,2,0,1]
 * 输出：true
 * 解释：0 + 2 + 1 = -6 + 6 - 7 + 9 + 1 = 2 + 0 + 1
 * 
 * 
 * 示例 2：
 * 
 * 输入：[0,2,1,-6,6,7,9,-1,2,0,1]
 * 输出：false
 * 
 * 
 * 示例 3：
 * 
 * 输入：[3,3,6,5,-2,2,5,1,-9,4]
 * 输出：true
 * 解释：3 + 3 = 6 = 5 - 2 + 2 + 5 + 1 - 9 + 4
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 3 <= A.length <= 50000
 * -10^4 <= A[i] <= 10^4
 * 
 * 
 */
#include "useforme.h"
// @lc code=start
class Solution {
public:
    bool canThreePartsEqualSum(vector<int>& A) {
        int sum = accumulate(A.begin(), A.end(), 0);
        if(sum%3!=0){
            return false;
        }
        auto i = A.begin();
        auto j = A.end()-1;
        int sum_L = *i;
        int sum_R = *j;
        sum = sum/3;
        while(i<j){
            if(sum_L!=sum){
                i++;
                sum_L += *i;
            }
            if(sum_R!=sum){
                j--;
                sum_R += *j;
            }
            if((sum_R == sum)&&(sum_L == sum)){
                if(i+1<j)
                // cout<<i-A.begin()<<j-A.begin();
                    return true;
                return false;
            }
        }
        return false;
    }
};
// @lc code=end

