/*
 * @Description: 
 * @Version: 2.0
 * @Author: yunruowu
 * @Date: 2020-01-24 11:34:37
 * @LastEditors: yunruowu
 * @LastEditTime: 2020-03-06 11:17:08
 */
/*
 * @lc app=leetcode.cn id=88 lang=cpp
 *
 * [88] 合并两个有序数组
 *
 * https://leetcode-cn.com/problems/merge-sorted-array/description/
 *
 * algorithms
 * Easy (46.02%)
 * Likes:    392
 * Dislikes: 0
 * Total Accepted:    100.7K
 * Total Submissions: 217.7K
 * Testcase Example:  '[1,2,3,0,0,0]\n3\n[2,5,6]\n3'
 *
 * 给定两个有序整数数组 nums1 和 nums2，将 nums2 合并到 nums1 中，使得 num1 成为一个有序数组。
 * 
 * 说明:
 * 
 * 
 * 初始化 nums1 和 nums2 的元素数量分别为 m 和 n。
 * 你可以假设 nums1 有足够的空间（空间大小大于或等于 m + n）来保存 nums2 中的元素。
 * 
 * 
 * 示例:
 * 
 * 输入:
 * nums1 = [1,2,3,0,0,0], m = 3
 * nums2 = [2,5,6],       n = 3
 * 
 * 输出: [1,2,2,3,5,6]
 * 
 */
#include<vector>
#include<algorithm>
using namespace std;

// @lc code=start
class Solution {
public:
    void Prinetvec(vector<int> nums){
        for(int i = 0 ;i< nums.size();i++){
            cout<<nums[i]<<" ";
        }
        cout<<endl;
    };

    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int insert_pos = 0;
        int i = 0;
        int len = m;
        
        if(n == 0){
            return;
        }
        if(m==0)
        while(i<n){
            nums1[i]=nums2[i];
            i++;
        }
        
        while(i<n){
            // Prinetvec(nums1);
            
            if(insert_pos==0&&nums1[insert_pos]>nums2[i]){
                nums1.insert(nums1.begin(),nums2[i]);
                i++;
                // insert_pos++;
                // cout<<1;
                len++;
            }else{
                if(insert_pos == len-1){//最后
                    while (i<n)
                    {
                        nums1[insert_pos+1]=nums2[i];
                        i++;
                        insert_pos++;
                        len++;
                    }
                }else{
                    if(nums1[insert_pos]<=nums2[i]&&nums1[insert_pos+1]>nums2[i]){
                        nums1.insert(nums1.begin()+insert_pos+1,nums2[i]);
                        i++;
                        // cout<<2;
                        insert_pos++;
                        len++;
                    }else{
                        insert_pos++;
                    }
                }
            }
        }
        
        int ll = nums1.size();
        int size = m+n;
        while(size<nums1.size()){
            nums1.pop_back();
        
        }
    }
};
// @lc code=end

