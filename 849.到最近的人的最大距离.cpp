/*
 * @Description: 
 * @Version: 2.0
 * @Author: yunruowu
 * @Date: 2020-03-11 12:14:24
 * @LastEditors: yunruowu
 * @LastEditTime: 2020-03-11 12:25:06
 */
/*
 * @lc app=leetcode.cn id=849 lang=cpp
 *
 * [849] 到最近的人的最大距离
 *
 * https://leetcode-cn.com/problems/maximize-distance-to-closest-person/description/
 *
 * algorithms
 * Easy (38.17%)
 * Likes:    84
 * Dislikes: 0
 * Total Accepted:    8K
 * Total Submissions: 20.4K
 * Testcase Example:  '[1,0,0,0,1,0,1]'
 *
 * 在一排座位（ seats）中，1 代表有人坐在座位上，0 代表座位上是空的。
 * 
 * 至少有一个空座位，且至少有一人坐在座位上。
 * 
 * 亚历克斯希望坐在一个能够使他与离他最近的人之间的距离达到最大化的座位上。
 * 
 * 返回他到离他最近的人的最大距离。
 * 
 * 示例 1：
 * 
 * 输入：[1,0,0,0,1,0,1]
 * 输出：2
 * 解释：
 * 如果亚历克斯坐在第二个空位（seats[2]）上，他到离他最近的人的距离为 2 。
 * 如果亚历克斯坐在其它任何一个空位上，他到离他最近的人的距离为 1 。
 * 因此，他到离他最近的人的最大距离是 2 。 
 * 
 * 
 * 示例 2：
 * 
 * 输入：[1,0,0,0]
 * 输出：3
 * 解释： 
 * 如果亚历克斯坐在最后一个座位上，他离最近的人有 3 个座位远。
 * 这是可能的最大距离，所以答案是 3 。
 * 
 * 
 * 提示：
 * 
 * 
 * 1 <= seats.length <= 20000
 * seats 中只含有 0 和 1，至少有一个 0，且至少有一个 1。
 * 
 * 
 */
#include "useforme.h"
// @lc code=start
class Solution {
public:

    int maxDistToClosest(vector<int>& seats) {
        int minval = 0;
        for(int i = 0;i<seats.size();i++){
            if(seats[i]==0){
                int l = i-1;
                int dis_l = 1;
                while(l>=0&&seats[l]==0){
                    l--;
                    dis_l++;
                }
                if(l<0){
                    dis_l = 999;
                }
                int r = i+1;
                int dis_r = 1;
                while(r<seats.size()&&seats[r]==0){
                    r++;
                    dis_r ++;
                }
                if(r>seats.size()-1){
                    dis_r = 999;
                }
                minval = max(minval, min(dis_r,dis_l));
            }
        }
        return minval;
    }
};
// @lc code=end

