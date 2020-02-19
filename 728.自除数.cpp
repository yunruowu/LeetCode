/*
 * @Description: 
 * @Version: 2.0
 * @Author: yunruowu
 * @Date: 2020-02-19 15:59:32
 * @LastEditors: yunruowu
 * @LastEditTime: 2020-02-19 16:09:40
 */
/*
 * @lc app=leetcode.cn id=728 lang=cpp
 *
 * [728] 自除数
 *
 * https://leetcode-cn.com/problems/self-dividing-numbers/description/
 *
 * algorithms
 * Easy (72.22%)
 * Likes:    86
 * Dislikes: 0
 * Total Accepted:    17.4K
 * Total Submissions: 24K
 * Testcase Example:  '1\n22'
 *
 * 自除数 是指可以被它包含的每一位数除尽的数。
 * 
 * 例如，128 是一个自除数，因为 128 % 1 == 0，128 % 2 == 0，128 % 8 == 0。
 * 
 * 还有，自除数不允许包含 0 。
 * 
 * 给定上边界和下边界数字，输出一个列表，列表的元素是边界（含边界）内所有的自除数。
 * 
 * 示例 1：
 * 
 * 
 * 输入： 
 * 上边界left = 1, 下边界right = 22
 * 输出： [1, 2, 3, 4, 5, 6, 7, 8, 9, 11, 12, 15, 22]
 * 
 * 
 * 注意：
 * 
 * 
 * 每个输入参数的边界满足 1 <= left <= right <= 10000。
 * 
 * 
 */
#include "useforme.h"
// @lc code=start
class Solution {
public:
    bool isSelfDividingNumbers(int num){
        int t = num;
        while(num>0){
            int mod = num%10;
            if(mod == 0){
                return false;
            }
            if(t%mod!=0){
                return false;
            }
            num = num/10;
        }
        return 10;
    }
    vector<int> selfDividingNumbers(int left, int right) {
        vector<int> ans;
        for(int i = left;i<=right; i++){
            if(isSelfDividingNumbers(i)){
                ans.push_back(i);
            }
        }
        return ans;
    }
};
// @lc code=end

