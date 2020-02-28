/*
 * @Description: 
 * @Version: 2.0
 * @Author: yunruowu
 * @Date: 2020-02-28 11:08:09
 * @LastEditors: yunruowu
 * @LastEditTime: 2020-02-28 11:25:36
 */
/*
 * @lc app=leetcode.cn id=645 lang=cpp
 *
 * [645] 错误的集合
 *
 * https://leetcode-cn.com/problems/set-mismatch/description/
 *
 * algorithms
 * Easy (40.35%)
 * Likes:    70
 * Dislikes: 0
 * Total Accepted:    10K
 * Total Submissions: 24.5K
 * Testcase Example:  '[1,2,2,4]'
 *
 * 集合 S 包含从1到 n
 * 的整数。不幸的是，因为数据错误，导致集合里面某一个元素复制了成了集合里面的另外一个元素的值，导致集合丢失了一个整数并且有一个元素重复。
 * 
 * 给定一个数组 nums 代表了集合 S 发生错误后的结果。你的任务是首先寻找到重复出现的整数，再找到丢失的整数，将它们以数组的形式返回。
 * 
 * 示例 1:
 * 
 * 
 * 输入: nums = [1,2,2,4]
 * 输出: [2,3]
 * 
 * 
 * 注意:
 * 
 * 
 * 给定数组的长度范围是 [2, 10000]。
 * 给定的数组是无序的。
 * 
 * 
 */
#include "useforme.h"
// @lc code=start
class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int copy;
        int lose = 1;
        int c_tag = 0;
        int l_tag = 0;
        
        for(int i = 0; i<nums.size(); i++){
            if(c_tag==0)
            { 
                if(nums[i]==nums[i+1]&&i+1<nums.size()){
                    copy=nums[i];
                    c_tag=1;
                }
            }
        }
        for(int i = 0; i<nums.size(); i++){
            if(nums[i]==lose){
                if(nums[i]==copy){
                    lose = lose+1;
                    i+=1;
                }else{
                    lose+=1;
                }
                
            }
            
        }

        vector<int> ans;
        ans.push_back(copy);
        ans.push_back(lose);
        return ans;
    }
};
// @lc code=end

