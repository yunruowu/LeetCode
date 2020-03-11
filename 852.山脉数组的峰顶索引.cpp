/*
 * @Description: 
 * @Version: 2.0
 * @Author: yunruowu
 * @Date: 2020-03-11 12:26:35
 * @LastEditors: yunruowu
 * @LastEditTime: 2020-03-11 12:40:05
 */
/*
 * @lc app=leetcode.cn id=852 lang=cpp
 *
 * [852] 山脉数组的峰顶索引
 *
 * https://leetcode-cn.com/problems/peak-index-in-a-mountain-array/description/
 *
 * algorithms
 * Easy (69.10%)
 * Likes:    71
 * Dislikes: 0
 * Total Accepted:    20.7K
 * Total Submissions: 29.7K
 * Testcase Example:  '[0,1,0]'
 *
 * 我们把符合下列属性的数组 A 称作山脉：
 * 
 * 
 * A.length >= 3
 * 存在 0 < i < A.length - 1 使得A[0] < A[1] < ... A[i-1] < A[i] > A[i+1] > ... >
 * A[A.length - 1]
 * 
 * 
 * 给定一个确定为山脉的数组，返回任何满足 A[0] < A[1] < ... A[i-1] < A[i] > A[i+1] > ... >
 * A[A.length - 1] 的 i 的值。
 * 
 * 
 * 
 * 示例 1：
 * 
 * 输入：[0,1,0]
 * 输出：1
 * 
 * 
 * 示例 2：
 * 
 * 输入：[0,2,1,0]
 * 输出：1
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 3 <= A.length <= 10000
 * 0 <= A[i] <= 10^6
 * A 是如上定义的山脉
 * 
 * 
 * 
 * 
 */
#include "useforme.h"
// @lc code=start
class Solution {
public:
    int peakIndexInMountainArray(vector<int>& A) {
        int l = 0;
        int r = A.size()-1;
        int mid =  (l+r)/2;
        while(l<=r){
            cout<<mid;
            if(A[mid]>A[mid-1]&&A[mid]>A[mid+1]){
                cout<<"s";
                return mid;
            }
            if(A[mid]<A[mid+1]){
                l = mid+1;
                mid = (l+r)/2;
            }else{
                r= mid-1;
                mid = (l+r)/2;
            }
        }
        return mid;
    }
};
// @lc code=end

