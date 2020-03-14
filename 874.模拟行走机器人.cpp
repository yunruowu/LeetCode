/*
 * @Description:
 * @Version: 2.0
 * @Author: yunruowu
 * @Date: 2020-03-13 10:40:12
 * @LastEditors: yunruowu
 * @LastEditTime: 2020-03-13 11:18:36
 */
/*
 * @lc app=leetcode.cn id=874 lang=cpp
 *
 * [874] 模拟行走机器人
 *
 * https://leetcode-cn.com/problems/walking-robot-simulation/description/
 *
 * algorithms
 * Easy (31.75%)
 * Likes:    79
 * Dislikes: 0
 * Total Accepted:    6.2K
 * Total Submissions: 18.7K
 * Testcase Example:  '[4,-1,3]\n[]'
 *
 * 机器人在一个无限大小的网格上行走，从点 (0, 0) 处开始出发，面向北方。该机器人可以接收以下三种类型的命令：
 *
 *
 * -2：向左转 90 度
 * -1：向右转 90 度
 * 1 <= x <= 9：向前移动 x 个单位长度
 *
 *
 * 在网格上有一些格子被视为障碍物。
 *
 * 第 i 个障碍物位于网格点  (obstacles[i][0], obstacles[i][1])
 *
 * 如果机器人试图走到障碍物上方，那么它将停留在障碍物的前一个网格方块上，但仍然可以继续该路线的其余部分。
 *
 * 返回从原点到机器人的最大欧式距离的平方。
 *
 *
 *
 * 示例 1：
 *
 * 输入: commands = [4,-1,3], obstacles = []
 * 输出: 25
 * 解释: 机器人将会到达 (3, 4)
 *
 *
 * 示例 2：
 *
 * 输入: commands = [4,-1,4,-2,4], obstacles = [[2,4]]
 * 输出: 65
 * 解释: 机器人在左转走到 (1, 8) 之前将被困在 (1, 4) 处
 *
 *
 *
 *
 * 提示：
 *
 *
 * 0 <= commands.length <= 10000
 * 0 <= obstacles.length <= 10000
 * -30000 <= obstacle[i][0] <= 30000
 * -30000 <= obstacle[i][1] <= 30000
 * 答案保证小于 2 ^ 31
 *
 *
 */
#include "useforme.h"
// @lc code=start
class Solution {
public:
    int robotSim(vector<int>& commands, vector<vector<int>>& obstacles) {
        int Direction = 0;
        vector<int> cur_pos(2,0);
        int dis = cur_pos[0]*cur_pos[0]+cur_pos[1]*cur_pos[1];
        int next_y,next_x,obstacle;
        for(int i = 0; i<commands.size(); i++){
            switch (commands[i])
            {
            case -2:
                Direction = (Direction+3)%4;
                break;
            case -1:
                Direction = (Direction+1)%4;
                break;
            default:
                switch (Direction)
                {
                case 0://北
                    next_y = cur_pos[1]+commands[i];
                    obstacle = next_y+1;
                    for(int j = 0; j<obstacles.size(); j++){
                        if(obstacles[j][0]==cur_pos[0]){
                            if(obstacles[j][1]>cur_pos[1]&&obstacles[j][1]<=next_y){
                                obstacle = min(obstacles[j][1], obstacle);
                            }
                        }
                    }
                    if(obstacle < next_y+1){
                        next_y = obstacle-1;
                    }
                    cur_pos[1] = next_y;
                    dis = max(dis,cur_pos[0]*cur_pos[0]+cur_pos[1]*cur_pos[1]);
                    break;
                case 1://东
                    next_x = cur_pos[0]+commands[i];
                    obstacle = next_x+1;
                    for(int j = 0; j<obstacles.size(); j++){
                        if(obstacles[j][1]==cur_pos[1]){
                            if(obstacles[j][0]>cur_pos[0]&&obstacles[j][0]<=next_x){
                                obstacle = min(obstacles[j][0], obstacle);
                            }
                        }
                    }
                    if(obstacle < next_x+1){
                        next_x = obstacle-1;
                    }
                    cur_pos[0] = next_x;
                    dis = max(dis,cur_pos[0]*cur_pos[0]+cur_pos[1]*cur_pos[1]);
                    break;
                case 2://南
                    next_y = cur_pos[1]-commands[i];
                    obstacle = next_y-1;
                    for(int j = 0; j<obstacles.size(); j++){
                        if(obstacles[j][0]==cur_pos[0]){
                            if(obstacles[j][1]<cur_pos[1]&&obstacles[j][1]>=next_y){
                                obstacle = max(obstacles[j][1], obstacle);
                            }
                        }
                    }
                    if(obstacle > next_y-1){
                        next_y = obstacle+1;
                    }
                    cur_pos[1] = next_y;
                    dis = max(dis,cur_pos[0]*cur_pos[0]+cur_pos[1]*cur_pos[1]);
                    break;
                case 3:
                    next_x = cur_pos[0]-commands[i];
                    obstacle = next_x-1;
                    for(int j = 0; j<obstacles.size(); j++){
                        if(obstacles[j][1]==cur_pos[1]){
                            if(obstacles[j][0]<cur_pos[0]&&obstacles[j][0]>=next_x){
                                obstacle = max(obstacles[j][0], obstacle);
                            }
                        }
                    }
                    if(obstacle > next_x-1){
                        next_x = obstacle+1;
                    }
                    cur_pos[0] = next_x;
                    dis = max(dis,cur_pos[0]*cur_pos[0]+cur_pos[1]*cur_pos[1]);
                    break;
                default:
                    break;
                }
                break;
            }
        }
        return dis;
    }
};
// @lc code=end

