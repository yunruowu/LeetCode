/*
 * @lc app=leetcode.cn id=81 lang=cpp
 *
 * [81] 搜索旋转排序数组 II
 *
 * https://leetcode-cn.com/problems/search-in-rotated-sorted-array-ii/description/
 *
 * algorithms
 * Medium (35.27%)
 * Likes:    167
 * Dislikes: 0
 * Total Accepted:    28.6K
 * Total Submissions: 80.2K
 * Testcase Example:  '[2,5,6,0,0,1,2]\n0'
 *
 * 假设按照升序排序的数组在预先未知的某个点上进行了旋转。
 * 
 * ( 例如，数组 [0,0,1,2,2,5,6] 可能变为 [2,5,6,0,0,1,2] )。
 * 
 * 编写一个函数来判断给定的目标值是否存在于数组中。若存在返回 true，否则返回 false。
 * 
 * 示例 1:
 * 
 * 输入: nums = [2,5,6,0,0,1,2], target = 0
 * 输出: true
 * 
 * 
 * 示例 2:
 * 
 * 输入: nums = [2,5,6,0,0,1,2], target = 3
 * 输出: false
 * 
 * 进阶:
 * 
 * 
 * 这是 搜索旋转排序数组 的延伸题目，本题中的 nums  可能包含重复元素。
 * 这会影响到程序的时间复杂度吗？会有怎样的影响，为什么？
 * 
 * 
 */
#include "useforme.h"
// @lc code=start
class Solution {
public:
    vector<int> nums;
    int target;
    bool get(int l, int r){
        int mid;
        while(l<r){
            mid = (l+r)/2;
            if(nums[mid] == target)
            {
                cout<<"1";
                return true;
            }
            if(target>nums[mid]){
                l = mid+1;
            }else{
                r = mid-1;
            }
        }
        return false;
    }
    bool search(vector<int>& nums, int target) {
        if(nums.size()==1){
            return nums[0]==target;
        }
        if(nums.size()==2){
            return nums[0]==target||nums[1]==target;
        }
        this->nums = nums;
        this->target = target;

        int l = 0;
        int r = nums.size()-1;
        int mid;
        while(l<=r){
            mid = l+((r-l)>>1);
            if(nums[mid]==target)
            {
                // cout<<"1";
                return true;
            }
            if(nums[mid] < nums[r]){//右边有序
                if(nums[r]<target||nums[mid]>=target){//不在有序区间
                    r = mid - 1;
                }else{
                    l = mid + 1;
                }
            }
            else if(nums[mid] > nums[l]){//左边有序
                if(nums[l]>target||nums[mid]<=target){//不在有序区间
                    l = mid + 1;
                }
                else{
                    r = mid - 1;
                }
            }
            else{
                // /去重
                if(nums[l] == nums[mid]) l++;
                if(nums[r] == nums[mid])    r--;
            }
        }
        return false;
    }
};
// @lc code=end

