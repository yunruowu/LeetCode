/*
 * @lc app=leetcode.cn id=970 lang=cpp
 *
 * [970] 强整数
 *
 * https://leetcode-cn.com/problems/powerful-integers/description/
 *
 * algorithms
 * Easy (39.29%)
 * Likes:    31
 * Dislikes: 0
 * Total Accepted:    6.3K
 * Total Submissions: 16K
 * Testcase Example:  '2\n3\n10'
 *
 * 给定两个正整数 x 和 y，如果某一整数等于 x^i + y^j，其中整数 i >= 0 且 j >= 0，那么我们认为该整数是一个强整数。
 * 
 * 返回值小于或等于 bound 的所有强整数组成的列表。
 * 
 * 你可以按任何顺序返回答案。在你的回答中，每个值最多出现一次。
 * 
 * 
 * 
 * 示例 1：
 * 
 * 输入：x = 2, y = 3, bound = 10
 * 输出：[2,3,4,5,7,9,10]
 * 解释： 
 * 2 = 2^0 + 3^0
 * 3 = 2^1 + 3^0
 * 4 = 2^0 + 3^1
 * 5 = 2^1 + 3^1
 * 7 = 2^2 + 3^1
 * 9 = 2^3 + 3^0
 * 10 = 2^0 + 3^2
 * 
 * 
 * 示例 2：
 * 
 * 输入：x = 3, y = 5, bound = 15
 * 输出：[2,4,6,8,10,14]
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 1 <= x <= 100
 * 1 <= y <= 100
 * 0 <= bound <= 10^6
 * 
 * 
 */
#include "useforme.h"
// @lc code=start
class Solution {
public:
    bool Present(int bound, int x, int y){
        int a,b;
        if(x!=1){
            a = log(bound)/log(x);
        }else{
            a = 0;
        }
        if(y!=1){
            b = log(bound)/log(y);
        }else{
            b = 0;
        }
        
        for(int i = 0; i<=a; i++){
            for(int j = 0; j<=b&&(pow(x,i)+pow(y,j)<=bound); j++){
                if(pow(x,i)+pow(y,j)==bound){
                    return true;
                }
            }
        }
        return false;
    }
    vector<int> powerfulIntegers(int x, int y, int bound) {
        // int a = log(bound)/log(x);
        // int b = log(bound)/log(y);
        int pos = 3;
        vector<int> ans;
        vector<int> ans0;
        ans.push_back(2);
        set<int> s;
        s.insert(2);
        if(x == 1&&y==1){
            if(bound>1){
                return ans;
            }else{
                return ans0;
            }
        }
        int a,b;
        if(x!=1){
            a = log(bound)/log(x);
        }else{
            a = 0;
        }
        if(y!=1){
            b = log(bound)/log(y);
        }else{
            b = 0;
        }
        // while(pos<=bound){
        for(int i = 0; i<=a; i++){
            for(int j = 0; j<=b&&(pow(x,i)+pow(y,j)<=bound); j++){
                int add = pow(x,i)+pow(y,j);
                // if(add<bound){
                    s.insert(add);
                // }
            }
        }
        // }
        // while(i<=bound){
        //     if(Present(i, x, y)) {
        //         ans.push_back(i);
        //     }
        //     i++;
        // }
        ans.assign(s.begin(), s.end());
        return ans;
    }
};
// @lc code=end

