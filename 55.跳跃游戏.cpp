/*
 * @lc app=leetcode.cn id=55 lang=cpp
 *
 * [55] 跳跃游戏
 *
 * https://leetcode-cn.com/problems/jump-game/description/
 *
 * algorithms
 * Medium (38.54%)
 * Likes:    539
 * Dislikes: 0
 * Total Accepted:    77.9K
 * Total Submissions: 201.8K
 * Testcase Example:  '[2,3,1,1,4]'
 *
 * 给定一个非负整数数组，你最初位于数组的第一个位置。
 * 
 * 数组中的每个元素代表你在该位置可以跳跃的最大长度。
 * 
 * 判断你是否能够到达最后一个位置。
 * 
 * 示例 1:
 * 
 * 输入: [2,3,1,1,4]
 * 输出: true
 * 解释: 我们可以先跳 1 步，从位置 0 到达 位置 1, 然后再从位置 1 跳 3 步到达最后一个位置。
 * 
 * 
 * 示例 2:
 * 
 * 输入: [3,2,1,0,4]
 * 输出: false
 * 解释: 无论怎样，你总会到达索引为 3 的位置。但该位置的最大跳跃长度是 0 ， 所以你永远不可能到达最后一个位置。
 * 
 * 
 */
#include "useforme.h"
// @lc code=start
class Solution {
public:
    bool jump(int cur, vector<int> nums){
        // cout<<cur;
        if(cur == nums.size()-1){
            return true;
        }else{
            for(int i=1; i<=nums[cur]&&(cur+i)<nums.size(); i++)
            {
                // cout<<endl<<cur;
                if(jump(cur+i, nums)){
                    return true;
                }
            }
        }
        return false;
    }
    bool canJump(vector<int>& nums) {
        //!超时
        // return jump(0, nums);
        //如果某一个作为 起跳点 的格子可以跳跃的距离是 3，那么表示后面 3 个格子都可以作为 起跳点。
//      可以对每一个能作为 起跳点 的格子都尝试跳一次，把 能跳到最远的距离 不断更新。
//      如果可以一直跳到最后，就成功了。
//D        核心特性：如果一个位置能够到达，那么这个位置左侧所有位置
// 能到达。 想到这一点，解法就呼之欲出了~

        int k = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            if (i > k) return false;
            k = max(k, i + nums[i]);
        }
        return true;
    }
};
// @lc code=end

