/*
 * @lc app=leetcode.cn id=18 lang=cpp
 *
 * [18] 四数之和
 */
#include "useforme.h"
// @lc code=start
class Solution {
public:
//比我的答案添加了剪枝
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
    vector<vector<int>> result;
        if(nums.size() < 4)
            return result;
        sort(nums.begin(), nums.end());
        int size_n = nums.size();
        int sum;
        for(int i = 0; i < size_n - 3; i++)
        {
            if(target <= 0 && nums[i] > 0) break;
            if(nums[i] + nums[i+1] + nums[i+2] +nums[i+3] > target) break;
            if(nums[i] + nums[size_n - 3] + nums[size_n - 2] + nums[size_n - 1] < target) continue;
            if(i > 0 && nums[i]==nums[i-1]) continue;
            for(int j = i + 1; j < size_n - 2; j++)
            {
                if(nums[i] + nums[j] + nums[j+1] + nums[j+2] > target) break;
                if(nums[i] + nums[j] + nums[size_n-2] + nums[size_n-1] < target) continue;
                if(j > i+1 && nums[j]==nums[j-1]) continue;
                int left = j + 1, right = size_n - 1;
                while(left < right) {
                    sum = nums[i] + nums[j] + nums[left] + nums[right];
                    if(sum > target) {
                        right--;
                    } else if(sum < target) {
                        left++;
                    } else {
                        result.push_back(vector<int> {nums[i],nums[j],nums[left], nums[right]});
                        do{left++;} while(left < right && nums[left] == nums[left-1]);
                        do{right--;} while(left < right && nums[right] == nums[right+1]);
                    }
                    
                    
                }
            }
        }
        return result;
    }
};
//!DASD
//todo
//?
//*
// @lc code=end

