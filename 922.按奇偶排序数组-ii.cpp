/*
 * @lc app=leetcode.cn id=922 lang=cpp
 *
 * [922] 按奇偶排序数组 II
 *
 * https://leetcode-cn.com/problems/sort-array-by-parity-ii/description/
 *
 * algorithms
 * Easy (66.76%)
 * Likes:    83
 * Dislikes: 0
 * Total Accepted:    25.7K
 * Total Submissions: 38.3K
 * Testcase Example:  '[4,2,5,7]'
 *
 * 给定一个非负整数数组 A， A 中一半整数是奇数，一半整数是偶数。
 * 
 * 对数组进行排序，以便当 A[i] 为奇数时，i 也是奇数；当 A[i] 为偶数时， i 也是偶数。
 * 
 * 你可以返回任何满足上述条件的数组作为答案。
 * 
 * 
 * 
 * 示例：
 * 
 * 输入：[4,2,5,7]
 * 输出：[4,5,2,7]
 * 解释：[4,7,2,5]，[2,5,4,7]，[2,7,4,5] 也会被接受。
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 2 <= A.length <= 20000
 * A.length % 2 == 0
 * 0 <= A[i] <= 1000
 * 
 * 
 * 
 * 
 */
#include "useforme.h"
// @lc code=start
class Solution {
public:
    vector<int> sortArrayByParityII(vector<int>& A) {
        int i = 0;
        int j = 1;
        int len = A.size();
        while(i<len&&j<len){
            // cout<<i<<j;
            while(i<len&&A[i]%2==0){
                i+=2;
            }
            // cout<<1;
            while(j<len&&A[j]%2==1){
                j+=2;
            }
            // cout<<2;
            if(i<len&&j<len&&A[i]%2==1&&A[j]%2==0)
            {
                // cout<<3;
                int temp = A[i];
                A[i] = A[j];
                A[j] = temp;
                
            }
            j+=2;
            i+=2;
            // cout<<i<<j;
        }
        return A;
    }
};
// @lc code=end

