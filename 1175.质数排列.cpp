/*
 * @lc app=leetcode.cn id=1175 lang=cpp
 *
 * [1175] 质数排列
 *
 * https://leetcode-cn.com/problems/prime-arrangements/description/
 *
 * algorithms
 * Easy (46.97%)
 * Likes:    21
 * Dislikes: 0
 * Total Accepted:    4.7K
 * Total Submissions: 9.9K
 * Testcase Example:  '5'
 *
 * 请你帮忙给从 1 到 n 的数设计排列方案，使得所有的「质数」都应该被放在「质数索引」（索引从 1 开始）上；你需要返回可能的方案总数。
 * 
 * 让我们一起来回顾一下「质数」：质数一定是大于 1 的，并且不能用两个小于它的正整数的乘积来表示。
 * 
 * 由于答案可能会很大，所以请你返回答案 模 mod 10^9 + 7 之后的结果即可。
 * 
 * 
 * 
 * 示例 1：
 * 
 * 输入：n = 5
 * 输出：12
 * 解释：举个例子，[1,2,5,4,3] 是一个有效的排列，但 [5,2,3,4,1] 不是，因为在第二种情况里质数 5 被错误地放在索引为 1
 * 的位置上。
 * 
 * 
 * 示例 2：
 * 
 * 输入：n = 100
 * 输出：682289015
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 1 <= n <= 100
 * 
 * 
 */

// @lc code=start
class Solution {
public:
    bool isPrime(int n){      
        for(int i=3;i<n;i+=2) if(!(n%i)) return 0;
        return 1;
    }//判断从3开始的数是否是质数

    long fac(int n){
        long ans=1;
        while(n>1){
            ans*=n; ans=ans%1000000007; n--;
        }
        return ans;
    }// 阶乘的实现

    int ansGet(int n,int numOfPrime){
        return ((fac(numOfPrime)*fac(n-numOfPrime))%1000000007);
    }//计算最终结果

    int numPrimeArrangements(int n) {
        int numOfPrime=0;
        if(n>=2) numOfPrime++;
        for(int i=3;i<=n;i+=2){
            if(isPrime(i)) numOfPrime++;
        }
        return ansGet(n,numOfPrime);
    }
};

// @lc code=end

