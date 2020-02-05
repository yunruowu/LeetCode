/*
 * @Description: 
 * @Version: 2.0
 * @Author: yunruowu
 * @Date: 2020-02-04 11:59:40
 * @LastEditors  : yunruowu
 * @LastEditTime : 2020-02-04 17:04:26
 */
/*
 * @lc app=leetcode.cn id=38 lang=cpp
 *
 * [38] 外观数列
 *
 * https://leetcode-cn.com/problems/count-and-say/description/
 *
 * algorithms
 * Easy (54.30%)
 * Likes:    392
 * Dislikes: 0
 * Total Accepted:    70.7K
 * Total Submissions: 130.2K
 * Testcase Example:  '1'
 *
 * 「外观数列」是一个整数序列，从数字 1 开始，序列中的每一项都是对前一项的描述。前五项如下：
 * 
 * 1.     1
 * 2.     11
 * 3.     21
 * 4.     1211
 * 5.     111221
 * 
 * 
 * 1 被读作  "one 1"  ("一个一") , 即 11。
 * 11 被读作 "two 1s" ("两个一"）, 即 21。
 * 21 被读作 "one 2",  "one 1" （"一个二" ,  "一个一") , 即 1211。
 * 
 * 给定一个正整数 n（1 ≤ n ≤ 30），输出外观数列的第 n 项。
 * 
 * 注意：整数序列中的每一项将表示为一个字符串。
 * 
 * 
 * 
 * 示例 1:
 * 
 * 输入: 1
 * 输出: "1"
 * 解释：这是一个基本样例。
 * 
 * 示例 2:
 * 
 * 输入: 4
 * 输出: "1211"
 * 解释：当 n = 3 时，序列是 "21"，其中我们有 "2" 和 "1" 两组，"2" 可以读作 "12"，也就是出现频次 = 1 而 值 =
 * 2；类似 "1" 可以读作 "11"。所以答案是 "12" 和 "11" 组合在一起，也就是 "1211"。
 * 
 */
#include "useforme.h"
// @lc code=start
class Solution {
public:
    string countAndSay(int n)
    {
        int j = 1;
        string str="1";
        if(n==1){
            return str;
        }
        while (j<n)
        {
            string ans;
            cout<<str<<"  "<<str.size()<<endl;
            int i = 0;
            while (i<str.size())
            {
                char test = str[i];
                int sum = 0;
                while(i<str.size() && str[i]==test){
                    i++;
                    sum++;
                }
                ans = ans + to_string(sum) + test;
            }
            j++;
            str = ans;
        }
        return str;
    }
    
};
// @lc code=end

int main(int argc, const char** argv) {
    Solution sol;
    cout<<sol.countAndSay(9);
    return 0;
}