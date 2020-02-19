/*
 * @Description: 
 * @Version: 2.0
 * @Author: yunruowu
 * @Date: 2020-02-18 10:55:31
 * @LastEditors: yunruowu
 * @LastEditTime: 2020-02-18 11:58:52
 */
/*
 * @lc app=leetcode.cn id=447 lang=cpp
 *
 * [447] 回旋镖的数量
 *
 * https://leetcode-cn.com/problems/number-of-boomerangs/description/
 *
 * algorithms
 * Easy (56.51%)
 * Likes:    76
 * Dislikes: 0
 * Total Accepted:    9.3K
 * Total Submissions: 16.3K
 * Testcase Example:  '[[0,0],[1,0],[2,0]]'
 *
 * 给定平面上 n 对不同的点，“回旋镖” 是由点表示的元组 (i, j, k) ，其中 i 和 j 之间的距离和 i 和 k
 * 之间的距离相等（需要考虑元组的顺序）。
 * 
 * 找到所有回旋镖的数量。你可以假设 n 最大为 500，所有点的坐标在闭区间 [-10000, 10000] 中。
 * 
 * 示例:
 * 
 * 
 * 输入:
 * [[0,0],[1,0],[2,0]]
 * 
 * 输出:
 * 2
 * 
 * 解释:
 * 两个回旋镖为 [[1,0],[0,0],[2,0]] 和 [[1,0],[2,0],[0,0]]
 * 
 * 
 */
#include "useforme.h"
// @lc code=start
class Solution {
public:
    int getNUM(vector<int> dic){
        int i = dic.size();
        int j = 0;
        int ans  = 0;
        while(j<i){
            ans += dic[i]*(dic[i]-1);
            j++;
        }
        return ans;
    }
    int numberOfBoomerangs(vector<vector<int>>& points) {
        vector<int> dic;
        int p =0;
        vector<int> numberOfDic;
        
        int ans = 0;
        for(int i = 0; i<points.size(); i++){
            for(int j = 0;j<points.size();j++){
                if(j==i){
                    continue;
                }
                int len = (points[i][0]-points[j][0])*(points[i][0]-points[j][0])+(points[i][1]-points[j][1])*(points[i][1]-points[j][1]);
                // int len = 0;
                vector<int>::iterator findResult=find(dic.begin(),dic.end(),len);
                if(findResult!=dic.end()){
                    // numberOfDic[findResult-dic.begin()]++;
                }else{
                    dic.push_back(len);
                    numberOfDic.push_back(0);
                }
            }
            ans += getNUM(numberOfDic);
        }
        return ans;
    }
};
// @lc code=end

