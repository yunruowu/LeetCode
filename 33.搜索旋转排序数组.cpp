/*
 * @lc app=leetcode.cn id=33 lang=cpp
 *
 * [33] 搜索旋转排序数组
 *
 * https://leetcode-cn.com/problems/search-in-rotated-sorted-array/description/
 *
 * algorithms
 * Medium (36.53%)
 * Likes:    594
 * Dislikes: 0
 * Total Accepted:    92.9K
 * Total Submissions: 253.8K
 * Testcase Example:  '[4,5,6,7,0,1,2]\n0'
 *
 * 假设按照升序排序的数组在预先未知的某个点上进行了旋转。
 * 
 * ( 例如，数组 [0,1,2,4,5,6,7] 可能变为 [4,5,6,7,0,1,2] )。
 * 
 * 搜索一个给定的目标值，如果数组中存在这个目标值，则返回它的索引，否则返回 -1 。
 * 
 * 你可以假设数组中不存在重复的元素。
 * 
 * 你的算法时间复杂度必须是 O(log n) 级别。
 * 
 * 示例 1:
 * 
 * 输入: nums = [4,5,6,7,0,1,2], target = 0
 * 输出: 4
 * 
 * 
 * 示例 2:
 * 
 * 输入: nums = [4,5,6,7,0,1,2], target = 3
 * 输出: -1
 * 
 */
#include "useforme.h"
// @lc code=start
class Solution {
public:
    int search(vector<int>& nums, int target) {
        // int ans = -1;
        if(nums.size()==0){
            return -1;
        }
        if(nums.size()==1){
            if(nums[0]==target){
                return 0;
            }
            return -1;
        }
        int l = 0;
        int len = nums.size();
        int r = len -1;
        int mid = (l+r)/2;
        int cur = l;
        if(nums[0]>nums[len-1])
        { 
            while(l<r){
                if(nums[l]<nums[mid]){
                    l = mid;
                }else{
                    r = mid;
                }
                mid = (l+r)/2;
                cout<<mid;
            }
            l = 0;
            r = len -1;
            // mid = (l+r)/2;
            // cout<<mid<<endl;
            // while(nums[cur]!=target){
            if(nums[cur]==target){
                return cur;
            }
            if(nums[cur]<target)
            {
                r = mid;
            }else{
                l = mid+1;
            }
        }
        // cout<<l<<r<<endl;
        while (l<=r)
        {
            // cout<<l<<r<<endl;
            if(target>nums[r]||target<nums[l]){
                return -1;
            }
            // cout<<"as";
            mid = (l+r)/2;
            if(nums[mid]==target){
                return mid;
            }
            // cout<<"a1";
            if(nums[mid]<target){
                l = mid+1;
            }else{
                r = mid-1;
            }
            // cout<<l<<r<<endl;
        }
        return -1;
    }
};
// @lc code=end

int main(int argc, char const *argv[])
{
    
    vector<int> a ;
    a.push_back(7);
    a.push_back(8);
    a.push_back(9);
    // a.push_back(2);
    // a.push_back(4);
    // a.push_back(7);
    Solution mm;
    int as = mm.search(a, 1);
    return 0;
}
