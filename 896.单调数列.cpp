/*
 * @Description: 
 * @Version: 2.0
 * @Author: yunruowu
 * @Date: 2020-03-25 19:04:36
 * @LastEditors: yunruowu
 * @LastEditTime: 2020-03-25 19:27:49
 */
/*
 * @lc app=leetcode.cn id=896 lang=cpp
 *
 * [896] 单调数列
 *
 * https://leetcode-cn.com/problems/monotonic-array/description/
 *
 * algorithms
 * Easy (50.68%)
 * Likes:    54
 * Dislikes: 0
 * Total Accepted:    13.2K
 * Total Submissions: 25.5K
 * Testcase Example:  '[1,2,2,3]'
 *
 * 如果数组是单调递增或单调递减的，那么它是单调的。
 * 
 * 如果对于所有 i <= j，A[i] <= A[j]，那么数组 A 是单调递增的。 如果对于所有 i <= j，A[i]> = A[j]，那么数组 A
 * 是单调递减的。
 * 
 * 当给定的数组 A 是单调数组时返回 true，否则返回 false。
 * 
 * 
 * 
 * 
 * 
 * 
 * 示例 1：
 * 
 * 输入：[1,2,2,3]
 * 输出：true
 * 
 * 
 * 示例 2：
 * 
 * 输入：[6,5,4,4]
 * 输出：true
 * 
 * 
 * 示例 3：
 * 
 * 输入：[1,3,2]
 * 输出：false
 * 
 * 
 * 示例 4：
 * 
 * 输入：[1,2,4,5]
 * 输出：true
 * 
 * 
 * 示例 5：
 * 
 * 输入：[1,1,1]
 * 输出：true
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 1 <= A.length <= 50000
 * -100000 <= A[i] <= 100000
 * 
 * 
 */
#include "useforme.h"
// @lc code=start
class Solution {
public:
    bool isMonotonic(vector<int>& A) {
        // if(A.size()<=1){
        //     return true;
        // }
        // int j = 0;
        // while(j+1<A.size()&&A[j]==A[j+1]){
        //     j++;
        // }
        // if(j+1>=A.size()){
        //     return true;
        // }
        // if(A[j]<A[j+1]){
        //     cout<<1;
        //     for(int i = j+1; i<A.size(); i++){
        //         if(A[i-1]>A[i])
        //             return false;
        //     }
        //     return true;
        // }else{
        //     for(int i = j+1; i<A.size(); i++){
        //         cout<<2;
        //         if(A[i-1]<A[i])
        //             return false;
        //     }
        //     return true;
        // }
        // return false;
        //法2
        if(A.size()<=1){
            return true;
        }
        int a = 0;
        int b = 0;
        for(int i = 1; i<A.size(); i++){
            if(A[i-1]>A[i])
                a = 1;
            if(A[i-1]<A[i])
                b = 1;
            if(a+b==2)
                return false;
        }
        
        return true;
    }
};
// @lc code=end

