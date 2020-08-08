/*
 * @lc app=leetcode.cn id=264 lang=cpp
 *
 * [264] 丑数 II
 *
 * https://leetcode-cn.com/problems/ugly-number-ii/description/
 *
 * algorithms
 * Medium (50.89%)
 * Likes:    306
 * Dislikes: 0
 * Total Accepted:    27.2K
 * Total Submissions: 51.9K
 * Testcase Example:  '10'
 *
 * 编写一个程序，找出第 n 个丑数。
 * 
 * 丑数就是质因数只包含 2, 3, 5 的正整数。
 * 
 * 示例:
 * 
 * 输入: n = 10
 * 输出: 12
 * 解释: 1, 2, 3, 4, 5, 6, 8, 9, 10, 12 是前 10 个丑数。
 * 
 * 说明:  
 * 
 * 
 * 1 是丑数。
 * n 不超过1690。
 * 
 * 
 */
#include "useforme.h"
// @lc code=start
class ugly
{
public:
    vector<int> sq;
    ugly(){
        vector<int> sq1(1690,1);
        // sq.push_back(1);
        sq.assign(sq1.begin(),sq1.end());
        int pos2 = 0;
        int pos3 = 0;
        int pos5 = 0;
        int i = 1; 
        int temp;
        while(i<1690){
            // cout<<"111-"<<pos2<<" ";
            temp = min(sq[pos2]*2, min(sq[pos3]*3, sq[pos5]*5));
            sq[i]=temp;
            // cout<<temp<<" ";
            if(temp == sq[pos2]*2){
                pos2++;
            }
            if(temp == sq[pos3]*3){
                pos3++;
            }
            if(temp == sq[pos5]*5){
                pos5++;
            }
            i++;
        }
    }
};



class Solution {
public:
    int nthUglyNumber(int n) {
        vector<int> sq(n,1);
        // sq.push_back(1);
        // sq.assign(sq1.begin(),sq1.end());
        int pos2 = 0,pos3 = 0,pos5 = 0;
        int i = 1; 
        int temp;
        while(i<n){
            // cout<<"111-"<<pos2<<" ";
            temp = min(sq[pos2]*2, min(sq[pos3]*3, sq[pos5]*5));
            sq[i]=temp;
            // cout<<temp<<" ";
            if(temp == sq[pos2]*2){
                pos2++;
            }
            if(temp == sq[pos3]*3){
                pos3++;
            }
            if(temp == sq[pos5]*5){
                pos5++;
            }
            i++;
        }
        return sq[n-1];
        
    }
};
// @lc code=end

