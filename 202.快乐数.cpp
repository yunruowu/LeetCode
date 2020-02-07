/*
 * @Description: 
 * @Version: 2.0
 * @Author: yunruowu
 * @Date: 2020-02-07 18:58:14
 * @LastEditors  : yunruowu
 * @LastEditTime : 2020-02-07 19:11:17
 */
/*
 * @lc app=leetcode.cn id=202 lang=cpp
 *
 * [202] 快乐数
 *
 * https://leetcode-cn.com/problems/happy-number/description/
 *
 * algorithms
 * Easy (56.91%)
 * Likes:    218
 * Dislikes: 0
 * Total Accepted:    43.2K
 * Total Submissions: 75.8K
 * Testcase Example:  '19'
 *
 * 编写一个算法来判断一个数是不是“快乐数”。
 * 
 * 一个“快乐数”定义为：对于一个正整数，每一次将该数替换为它每个位置上的数字的平方和，然后重复这个过程直到这个数变为 1，也可能是无限循环但始终变不到
 * 1。如果可以变为 1，那么这个数就是快乐数。
 * 
 * 示例: 
 * 
 * 输入: 19
 * 输出: true
 * 解释: 
 * 1^2 + 9^2 = 82
 * 8^2 + 2^2 = 68
 * 6^2 + 8^2 = 100
 * 1^2 + 0^2 + 0^2 = 1
 * 
 * 
 */
#include "useforme.h"
// @lc code=start
class Solution {
public:
    vector<int> usednum;
    bool isHappy(int n) {
        // cout<<n<<endl;
        if(find(usednum.begin(),usednum.end(),n)!=usednum.end()){
            return false;
        }
        usednum.push_back(n);
        int sum = 0;

        while (n>0)
        {
            sum+=(n%10)*(n%10);
            n=n/10;
        }
        if(sum==1){
            return 1;
        }
        else
        {
            return isHappy(sum);
        }
        
        
    }
};
// @lc code=end

