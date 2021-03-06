/*
 * @lc app=leetcode.cn id=397 lang=cpp
 *
 * [397] 整数替换
 *
 * https://leetcode-cn.com/problems/integer-replacement/description/
 *
 * algorithms
 * Medium (35.93%)
 * Likes:    70
 * Dislikes: 0
 * Total Accepted:    8.5K
 * Total Submissions: 23.5K
 * Testcase Example:  '8'
 *
 * 给定一个正整数 n，你可以做如下操作：
 * 
 * 1. 如果 n 是偶数，则用 n / 2替换 n。
 * 2. 如果 n 是奇数，则可以用 n + 1或n - 1替换 n。
 * n 变为 1 所需的最小替换次数是多少？
 * 
 * 示例 1:
 * 
 * 
 * 输入:
 * 8
 * 
 * 输出:
 * 3
 * 
 * 解释:
 * 8 -> 4 -> 2 -> 1
 * 
 * 
 * 示例 2:
 * 
 * 
 * 输入:
 * 7
 * 
 * 输出:
 * 4
 * 
 * 解释:
 * 7 -> 8 -> 4 -> 2 -> 1
 * 或
 * 7 -> 6 -> 3 -> 2 -> 1
 * 
 * 
 */
#include "useforme.h"
// @lc code=start
class Solution {
public:
    int get(int n ){
        if(n==1){
            return 0;
        }
        
        if(n%2==0){
            return get(n/2)+1;
        }
        return min(get((n/2)+1)+1, get(n-1))+1;
    }
    int integerReplacement(long long int n) {
        int i = 0;
        while(n!=1){
            if(n%2==0){
                n/=2;
            }else{
                if(((n-1)/2)%2==0||(n-1)/2==1){
                    n=n-1;
                }else{
                    n++;
                }
            }
            i++; //
        }
        return i;
        // return get(n);
    }
};
// @lc code=end

