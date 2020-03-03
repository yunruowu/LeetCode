/*
 * @Description: 
 * @Version: 2.0
 * @Author: yunruowu
 * @Date: 2020-03-03 11:25:45
 * @LastEditors: yunruowu
 * @LastEditTime: 2020-03-03 12:14:24
 */
/*
 * @lc app=leetcode.cn id=697 lang=cpp
 *
 * [697] 数组的度
 *
 * https://leetcode-cn.com/problems/degree-of-an-array/description/
 *
 * algorithms
 * Easy (51.17%)
 * Likes:    101
 * Dislikes: 0
 * Total Accepted:    11.8K
 * Total Submissions: 22.7K
 * Testcase Example:  '[1,2,2,3,1]'
 *
 * 给定一个非空且只包含非负数的整数数组 nums, 数组的度的定义是指数组里任一元素出现频数的最大值。
 * 
 * 你的任务是找到与 nums 拥有相同大小的度的最短连续子数组，返回其长度。
 * 
 * 示例 1:
 * 
 * 
 * 输入: [1, 2, 2, 3, 1]
 * 输出: 2
 * 解释: 
 * 输入数组的度是2，因为元素1和2的出现频数最大，均为2.
 * 连续子数组里面拥有相同度的有如下所示:
 * [1, 2, 2, 3, 1], [1, 2, 2, 3], [2, 2, 3, 1], [1, 2, 2], [2, 2, 3], [2, 2]
 * 最短连续子数组[2, 2]的长度为2，所以返回2.
 * 
 * 
 * 示例 2:
 * 
 * 
 * 输入: [1,2,2,3,1,4,2]
 * 输出: 6
 * 
 * 
 * 注意:
 * 
 * 
 * nums.length 在1到50,000区间范围内。
 * nums[i] 是一个在0到49,999范围内的整数。
 * 
 * 
 */
#include "useforme.h"
// @lc code=start
class Solution {
public:
    int findShortestSubArray(vector<int>& nums) {
        vector<int> tag (nums.size());
        
        int max_degree = 0;
        int min_len = 50001;
        int pos = 0;
        while(pos<nums.size()){
            // cout<<pos<<" ";
            int temp_max = 0;
            int lastpos = pos;
            cout<<nums.size();
            for(int i=pos;i<nums.size();i++){
                if(pos==1){
                    cout<<i;
                }
                if(nums[i]==nums[pos]){
                    tag[i]=1;
                    // cout<<nums[i];
                    temp_max++;//此时的度++
                    lastpos = i;
                }
            }
            
            if(temp_max>max_degree){
                max_degree=temp_max;
                min_len = lastpos-pos+1;
                // cout<<min_len;
            }else if(temp_max==max_degree)
                // cout<<temp_max<<"t"<<pos;
                min_len = min(lastpos-pos+1,min_len);
                // cout<<min_len;
            while(pos<nums.size()){
                if(tag[pos]==1)
                    pos++;
                else{
                    break;
                }
            }
        }
        return min_len;
    }
};
// @lc code=end

int main(int argc, const char** argv) {
    Solution s;
    vector<int> v ;
    v.push_back(1);
    v.push_back(2);
    v.push_back(2);
    v.push_back(3);
    v.push_back(1);
v.push_back(4);
    v.push_back(2);
    cout<<endl<<s.findShortestSubArray(v);
    return 0;
}