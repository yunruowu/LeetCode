/*
 * @lc app=leetcode.cn id=4 lang=cpp
 *
 * [4] 寻找两个有序数组的中位数
 *
 * https://leetcode-cn.com/problems/median-of-two-sorted-arrays/description/
 *
 * algorithms
 * Hard (37.17%)
 * Likes:    2713
 * Dislikes: 0
 * Total Accepted:    204.6K
 * Total Submissions: 535.3K
 * Testcase Example:  '[1,3]\n[2]'
 *
 * 给定两个大小为 m 和 n 的正序（从小到大）数组 nums1 和 nums2。
 * 
 * 请你找出这两个正序数组的中位数，并且要求算法的时间复杂度为 O(log(m + n))。
 * 
 * 你可以假设 nums1 和 nums2 不会同时为空。
 * 
 * 
 * 
 * 示例 1:
 * 
 * nums1 = [1, 3]
 * nums2 = [2]
 * 
 * 则中位数是 2.0
 * 
 * 
 * 示例 2:
 * 
 * nums1 = [1, 2]
 * nums2 = [3, 4]
 * 
 * 则中位数是 (2 + 3)/2 = 2.5
 * 
 * 
 */
#include "useforme.h"
// @lc code=start
class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int len = nums1.size() + nums2.size();
        int cur1 = 0, cur2=0;
        int mid = len/2+1;
        int a =0; int b = 0;
        while(mid>0){
            a=b;
            if(cur1<nums1.size()&&cur2<nums2.size()){
                if(nums1[cur1]<nums2[cur2]){
                    cur1++;
                    b = nums1[cur1];
                }else{
                    cur2++;
                    b = nums2[cur2];
                }
                mid --;
            }else{
                if(cur1==nums1.size()){
                    cur2++;
                    b = nums2[cur2];
                }else{
                    if(cur2==nums2.size()){
                        cur1++;
                        b = nums1[cur1];
                    }
                }
                mid--;
            }
            
        }

        if(len%2 == 0){//偶数
            return (a+b+0.0)/2;
        }else{
            return b+0.0;
        }
        return 0;
    }
};
// @lc code=end

