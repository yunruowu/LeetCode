/*
 * @lc app=leetcode.cn id=1005 lang=cpp
 *
 * [1005] K 次取反后最大化的数组和
 *
 * https://leetcode-cn.com/problems/maximize-sum-of-array-after-k-negations/description/
 *
 * algorithms
 * Easy (51.98%)
 * Likes:    53
 * Dislikes: 0
 * Total Accepted:    10K
 * Total Submissions: 19.1K
 * Testcase Example:  '[4,2,3]\n1'
 *
 * 给定一个整数数组 A，我们只能用以下方法修改该数组：我们选择某个索引 i 并将 A[i] 替换为 -A[i]，然后总共重复这个过程 K
 * 次。（我们可以多次选择同一个索引 i。）
 * 
 * 以这种方式修改数组后，返回数组可能的最大和。
 * 
 * 
 * 
 * 示例 1：
 * 
 * 输入：A = [4,2,3], K = 1
 * 输出：5
 * 解释：选择索引 (1,) ，然后 A 变为 [4,-2,3]。
 * 
 * 
 * 示例 2：
 * 
 * 输入：A = [3,-1,0,2], K = 3
 * 输出：6
 * 解释：选择索引 (1, 2, 2) ，然后 A 变为 [3,1,0,2]。
 * 
 * 
 * 示例 3：
 * 
 * 输入：A = [2,-3,-1,5,-4], K = 2
 * 输出：13
 * 解释：选择索引 (1, 4) ，然后 A 变为 [2,3,-1,5,4]。
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 1 <= A.length <= 10000
 * 1 <= K <= 10000
 * -100 <= A[i] <= 100
 * 
 * 
 */
#include "useforme.h"
// @lc code=start
class Solution {
public:
    int largestSumAfterKNegations(vector<int>& A, int K) {
        sort(A.begin(), A.end());
        int i = 0;
        int sum = 0;
        while (i<A.size()&&K>0)
        {
            if(A[i]<=0){
                sum+=-A[i];
                i++;
                K--;
            }else{
                break;
            }
        }
        if(K>0){//要么K大于数组长度且全是负数，已经到正数了
            if(K%2!=0){
            
                if(i==A.size()){
                    sum -= 2*A[i-1];
                }
                else
                {
                    if(i==0){
                        sum -= 2*A[i];
                    }else{
                        sum -= 2*min(abs(A[i-1]), abs(A[i]));
                    }
                    
                }
                
            }
        }
        while(i<A.size()){
            sum += A[i];
            i++;
        }
        
        return sum;
    }
};
// @lc code=end

