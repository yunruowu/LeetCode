/*
 * @lc app=leetcode.cn id=347 lang=cpp
 *
 * [347] 前 K 个高频元素
 *
 * https://leetcode-cn.com/problems/top-k-frequent-elements/description/
 *
 * algorithms
 * Medium (60.64%)
 * Likes:    461
 * Dislikes: 0
 * Total Accepted:    84.4K
 * Total Submissions: 138.1K
 * Testcase Example:  '[1,1,1,2,2,3]\n2'
 *
 * 给定一个非空的整数数组，返回其中出现频率前 k 高的元素。
 * 
 * 
 * 
 * 示例 1:
 * 
 * 输入: nums = [1,1,1,2,2,3], k = 2
 * 输出: [1,2]
 * 
 * 
 * 示例 2:
 * 
 * 输入: nums = [1], k = 1
 * 输出: [1]
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 你可以假设给定的 k 总是合理的，且 1 ≤ k ≤ 数组中不相同的元素的个数。
 * 你的算法的时间复杂度必须优于 O(n log n) , n 是数组的大小。
 * 题目数据保证答案唯一，换句话说，数组中前 k 个高频元素的集合是唯一的。
 * 你可以按任意顺序返回答案。
 * 
 * 
 */
#include "useforme.h"
// @lc code=start
class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        vector<int> ans;
        vector<int> s(nums.size(),1);
        // if(nums.size()==1){
        //     return nums;
        // }
        int num_min = -1;
        int pos = 0;
        // s[pos]=1;
        pos++;
        while(pos<nums.size()){
            if(nums[pos]==nums[pos-1]){
                s[pos] = s[pos-1]+1;
                s[pos-1]=0;
            }
            pos++;
        }
        vector<int> temp = s;
        int j = 0;
        sort(s.begin(), s.end(), greater<int>());
        int t = k-1;
        for(int i=0; i<nums.size(); i++){
            if(temp[i]>=s[t]){
                ans.push_back(nums[i]);
                j++;
                if(j==k){
                    return ans;
                }
            }
        }
        return ans;
    }
};
// @lc code=end

