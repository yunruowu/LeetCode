/*
 * @Description: 
 * @Version: 2.0
 * @Author: yunruowu
 * @Date: 2020-02-07 20:48:13
 * @LastEditors  : yunruowu
 * @LastEditTime : 2020-02-07 21:51:23
 */
/*
 * @lc app=leetcode.cn id=204 lang=cpp
 *
 * [204] 计数质数
 *
 * https://leetcode-cn.com/problems/count-primes/description/
 *
 * algorithms
 * Easy (31.92%)
 * Likes:    265
 * Dislikes: 0
 * Total Accepted:    40.8K
 * Total Submissions: 127.6K
 * Testcase Example:  '10'
 *
 * 统计所有小于非负整数 n 的质数的数量。
 * 
 * 示例:
 * 
 * 输入: 10
 * 输出: 4
 * 解释: 小于 10 的质数一共有 4 个, 它们是 2, 3, 5, 7 。
 * 
 * 
 */
#include "useforme.h"
// @lc code=start
class Solution {
public:
    bool isPrime(int n ){
        for(int i=2;i*i<=n;i++){
            if(n%i==0){
                return 0;
            }
        }
        return 1;
    }
    int countPrimes0(int n) {
        int count = 0;
        for(int i = 2;i<n;i++){
            count += isPrime(i);
        }
        return count;
    }
    int countPrimes(int n) {
        vector<int> count(n,1);
        for(int i = 2;i*i<n;i++){
            for(int 2;j<n;j+=i){
                count[j]=0;
                // cout<<i;
            }
        }
        int sum = 0;
        int nn=n-1;
        for(int i = 2 ;i<n;i++){
            if(count[i]==1){
                cout<<endl<<i;
                sum++;
            }
        }
        return sum;
    }
};
// @lc code=end

int main(int argc, char const *argv[])
{
    int a[10]={0};
    for(int i = 0;i<10;i++){
        cout<<a[i];
    }
    return 0;
}
