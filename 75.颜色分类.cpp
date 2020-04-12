/*
 * @lc app=leetcode.cn id=75 lang=cpp
 *
 * [75] 颜色分类
 *
 * https://leetcode-cn.com/problems/sort-colors/description/
 *
 * algorithms
 * Medium (54.70%)
 * Likes:    389
 * Dislikes: 0
 * Total Accepted:    72.4K
 * Total Submissions: 132.4K
 * Testcase Example:  '[2,0,2,1,1,0]'
 *
 * 给定一个包含红色、白色和蓝色，一共 n 个元素的数组，原地对它们进行排序，使得相同颜色的元素相邻，并按照红色、白色、蓝色顺序排列。
 * 
 * 此题中，我们使用整数 0、 1 和 2 分别表示红色、白色和蓝色。
 * 
 * 注意:
 * 不能使用代码库中的排序函数来解决这道题。
 * 
 * 示例:
 * 
 * 输入: [2,0,2,1,1,0]
 * 输出: [0,0,1,1,2,2]
 * 
 * 进阶：
 * 
 * 
 * 一个直观的解决方案是使用计数排序的两趟扫描算法。
 * 首先，迭代计算出0、1 和 2 元素的个数，然后按照0、1、2的排序，重写当前数组。
 * 你能想出一个仅使用常数空间的一趟扫描算法吗？
 * 
 * 
 */
#include "useforme.h"
// @lc code=start
class Solution {
public:
    void sortColors(vector<int>& nums) {
        int l = 0;
        int r = nums.size()-1;
        while(l<nums.size()&&nums[l]==0)//第一个不为0
            l++;
        while(r>=0&&nums[r]==2)//第一个不为2
            r--;
        int m = l;
        int temp;
        while(m<=r){
            cout<<l<<m<<r<<endl;
            switch (nums[m])
            {
            case 0:
                temp = nums[m];
                nums[m] = nums[l];
                nums[l] = temp;
                l++;
                m++;
                break;
            case 1:
                m++;
                break;
            case 2:
                temp = nums[m];
                nums[m] = nums[r];
                nums[r] = temp;
                r--;
                // m++;
                break;
            default:
                break;
            }
        }
        // return nums;
    }
};
// @lc code=end

