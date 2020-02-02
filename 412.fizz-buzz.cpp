/*
 * @Description: 
 * @Version: 2.0
 * @Author: yunruowu
 * @Date: 2020-02-01 14:51:50
 * @LastEditors  : yunruowu
 * @LastEditTime : 2020-02-01 15:08:56
 */
/*
 * @lc app=leetcode.cn id=412 lang=cpp
 *
 * [412] Fizz Buzz
 *
 * https://leetcode-cn.com/problems/fizz-buzz/description/
 *
 * algorithms
 * Easy (62.06%)
 * Likes:    46
 * Dislikes: 0
 * Total Accepted:    26.4K
 * Total Submissions: 42.3K
 * Testcase Example:  '1'
 *
 * 写一个程序，输出从 1 到 n 数字的字符串表示。
 * 
 * 1. 如果 n 是3的倍数，输出“Fizz”；
 * 
 * 2. 如果 n 是5的倍数，输出“Buzz”；
 * 
 * 3.如果 n 同时是3和5的倍数，输出 “FizzBuzz”。
 * 
 * 示例：
 * 
 * n = 15,
 * 
 * 返回:
 * [
 * ⁠   "1",
 * ⁠   "2",
 * ⁠   "Fizz",
 * ⁠   "4",
 * ⁠   "Buzz",
 * ⁠   "Fizz",
 * ⁠   "7",
 * ⁠   "8",
 * ⁠   "Fizz",
 * ⁠   "Buzz",
 * ⁠   "11",
 * ⁠   "Fizz",
 * ⁠   "13",
 * ⁠   "14",
 * ⁠   "FizzBuzz"
 * ]
 * 
 * 
 */
#include<vector>
#include<string>
#include<stdio.h>
#include<iostream>
using namespace std;
// @lc code=start
class Solution {
public: 
    vector<string> fizzBuzz(int n) {
        vector<string> str;
        int i = 1;
        while (i<=n)
        {
            if(i%3 == 0 && i%5 == 0){
                cout<<4%3;
                str.push_back("FizzBuzz");
            }else if (i%3 == 0)
            {
                str.push_back("Fizz");
            }else if (i%5 == 0)
            {
                str.push_back("Buzz");
            }else{
                str.push_back(to_string(i));
            }
            i++;
        }
        return str;
        
    }
};
// @lc code=end

