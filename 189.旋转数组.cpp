/*
 * @Description: 
 * @Version: 2.0
 * @Author: yunruowu
 * @Date: 2020-02-06 20:54:46
 * @LastEditors  : yunruowu
 * @LastEditTime : 2020-02-06 21:15:19
 */
/*
 * @lc app=leetcode.cn id=189 lang=cpp
 *
 * [189] 旋转数组
 *
 * https://leetcode-cn.com/problems/rotate-array/description/
 *
 * algorithms
 * Easy (40.22%)
 * Likes:    479
 * Dislikes: 0
 * Total Accepted:    94.5K
 * Total Submissions: 234.7K
 * Testcase Example:  '[1,2,3,4,5,6,7]\n3'
 *
 * 给定一个数组，将数组中的元素向右移动 k 个位置，其中 k 是非负数。
 * 
 * 示例 1:
 * 
 * 输入: [1,2,3,4,5,6,7] 和 k = 3
 * 输出: [5,6,7,1,2,3,4]
 * 解释:
 * 向右旋转 1 步: [7,1,2,3,4,5,6]
 * 向右旋转 2 步: [6,7,1,2,3,4,5]
 * 向右旋转 3 步: [5,6,7,1,2,3,4]
 * 
 * 
 * 示例 2:
 * 
 * 输入: [-1,-100,3,99] 和 k = 2
 * 输出: [3,99,-1,-100]
 * 解释: 
 * 向右旋转 1 步: [99,-1,-100,3]
 * 向右旋转 2 步: [3,99,-1,-100]
 * 
 * 说明:
 * 
 * 
 * 尽可能想出更多的解决方案，至少有三种不同的方法可以解决这个问题。
 * 要求使用空间复杂度为 O(1) 的 原地 算法。
 * 
 * 
 */
#include "useforme.h"
// @lc code=start
class Solution {
public:
    void rotate1(vector<int>& nums, int k) {
        int len  = nums.size()-1;
        for(int i = 0; i<k;i++){
            nums.insert(nums.begin(),nums[len]);
            nums.pop_back();
        }
    }
    void Prinetvec(vector<int> nums){
    for(int i = 0 ;i< nums.size();i++){
        cout<<nums[i]<<" ";
    }
    cout<<endl;
    }

    void rotate2(vector<int>& nums, int k) {
        int len  = nums.size()-1;
        int  kk = len+1;
        for(int i = 0; i<k;i++){
            nums.insert(nums.begin(),nums[len]);
            // Prinetvec(nums);
        }
        int l = nums.size();
        nums.erase(nums.begin()+kk,nums.begin()+l);
    }
    void rotate(vector<int>& nums, int k) {
        k = k%nums.size();  
        reverse(nums.begin(),nums.end());
        reverse(nums.begin(),nums.begin()+k);
        reverse(nums.begin()+k,nums.end());
        
    }
};
// @lc code=end

