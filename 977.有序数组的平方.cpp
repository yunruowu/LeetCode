/*
 * @lc app=leetcode.cn id=977 lang=cpp
 *
 * [977] 有序数组的平方
 *
 * https://leetcode-cn.com/problems/squares-of-a-sorted-array/description/
 *
 * algorithms
 * Easy (71.15%)
 * Likes:    92
 * Dislikes: 0
 * Total Accepted:    36.9K
 * Total Submissions: 51.7K
 * Testcase Example:  '[-4,-1,0,3,10]'
 *
 * 给定一个按非递减顺序排序的整数数组 A，返回每个数字的平方组成的新数组，要求也按非递减顺序排序。
 * 
 * 
 * 
 * 示例 1：
 * 
 * 输入：[-4,-1,0,3,10]
 * 输出：[0,1,9,16,100]
 * 
 * 
 * 示例 2：
 * 
 * 输入：[-7,-3,2,3,11]
 * 输出：[4,9,9,49,121]
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 1 <= A.length <= 10000
 * -10000 <= A[i] <= 10000
 * A 已按非递减顺序排序。
 * 
 * 
 */
#include "useforme.h"
// @lc code=start
class Solution {
public:
    vector<int> sortedSquares(vector<int>& A) {
        // 方法一。之间排序法。
        // vector<int> ans;
        // // set<int> s;
        // for(int i = 0; i<A.size(); i++){
        //     ans.push_back(A[i]*A[i]);
        // }
        // // ans.assign(s.begin(), s.end());
        // sort(ans.begin(), ans.end());
        // return ans;

        //方法2 双指针
        int i = 0;
        int j = 0;
        vector<int> ans;
        if(A.size()==0)
            return ans;
        if(A.size()==1){
            ans.push_back(A[0]*A[0]);
            return ans;
        }
        while(A[i]<0&&i<A.size())
            i++;
        //i指向第一个大于等于0的位置。
        j = i-1;
        while(j>=0&&i<A.size()){
            if(A[j]*A[j]>A[i]*A[i])
            {
                ans.push_back(A[i]*A[i]);
                i++;
            }else{
                ans.push_back(A[j]*A[j]);
                j--;
            }
        }
        while(j>=0){
            ans.push_back(A[j]*A[j]);
            j--;
        }
        while(i<A.size()){
            ans.push_back(A[i]*A[i]);
            i++;
        }
        return ans;
    }
};
// @lc code=end

