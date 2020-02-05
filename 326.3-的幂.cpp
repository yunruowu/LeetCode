








/*
 * @Description: 
 * @Version: 2.0
 * @Author: yunruowu
 * @Date: 2020-01-31 10:35:36
 * @LastEditors  : yunruowu
 * @LastEditTime : 2020-01-31 10:40:39
 */
/*
 * @lc app=leetcode.cn id=326 lang=cpp
 *
 * [326] 3的幂
 *
 * https://leetcode-cn.com/problems/power-of-three/description/
 *
 * algorithms
 * Easy (45.90%)
 * Likes:    86
 * Dislikes: 0
 * Total Accepted:    34.1K
 * Total Submissions: 73.8K
 * Testcase Example:  '27'
 *
 * 给定一个整数，写一个函数来判断它是否是 3 的幂次方。
 * 
 * 示例 1:
 * 
 * 输入: 27
 * 输出: true
 * 
 * 
 * 示例 2:
 * 
 * 输入: 0
 * 输出: false
 * 
 * 示例 3:
 * 
 * 输入: 9
 * 输出: true
 * 
 * 示例 4:
 * 
 * 输入: 45
 * 输出: false
 * 
 * 进阶：
 * 你能不使用循环或者递归来完成本题吗？
 * 
 */

// @lc code=start
class Solution {
public:
    bool isPowerOfThree(int n) {
        int power = n;
        if(n == 0){
            return false;
        }
        while (power!=1)
        {
            int mod = power % 3;
            power = power / 3;
            if(power==2||mod !=0){
                return false;
            }
            /* code */
        }
        return true;
    }
};
// @lc code=end

