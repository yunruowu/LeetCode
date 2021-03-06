/*
 * @Description: 
 * @Version: 2.0
 * @Author: yunruowu
 * @Date: 2020-03-02 23:32:07
 * @LastEditors: yunruowu
 * @LastEditTime: 2020-03-03 00:00:50
 */
/*
 * @lc app=leetcode.cn id=690 lang=cpp
 *
 * [690] 员工的重要性
 *
 * https://leetcode-cn.com/problems/employee-importance/description/
 *
 * algorithms
 * Easy (56.43%)
 * Likes:    69
 * Dislikes: 0
 * Total Accepted:    9.4K
 * Total Submissions: 16.4K
 * Testcase Example:  '[[1,2,[2]], [2,3,[]]]\n2'
 *
 * 给定一个保存员工信息的数据结构，它包含了员工唯一的id，重要度 和 直系下属的id。
 * 
 * 比如，员工1是员工2的领导，员工2是员工3的领导。他们相应的重要度为15, 10, 5。那么员工1的数据结构是[1, 15,
 * [2]]，员工2的数据结构是[2, 10, [3]]，员工3的数据结构是[3, 5,
 * []]。注意虽然员工3也是员工1的一个下属，但是由于并不是直系下属，因此没有体现在员工1的数据结构中。
 * 
 * 现在输入一个公司的所有员工信息，以及单个员工id，返回这个员工和他所有下属的重要度之和。
 * 
 * 示例 1:
 * 
 * 
 * 输入: [[1, 5, [2, 3]], [2, 3, []], [3, 3, []]], 1
 * 输出: 11
 * 解释:
 * 员工1自身的重要度是5，他有两个直系下属2和3，而且2和3的重要度均为3。因此员工1的总重要度是 5 + 3 + 3 = 11。
 * 
 * 
 * 注意:
 * 
 * 
 * 一个员工最多有一个直系领导，但是可以有多个直系下属
 * 员工数量不超过2000。
 * 
 * 
 */
class Employee {
public:
    // It's the unique ID of each node.
    // unique id of this employee
    int id;
    // the importance value of this employee
    int importance;
    // the id of direct subordinates
    vector<int> subordinates;
};
#include "useforme.h"
class Employee {
public:
    // It's the unique ID of each node.
    // unique id of this employee
    int id;
    // the importance value of this employee
    int importance;
    // the id of direct subordinates
    vector<int> subordinates;
};
// @lc code=start
/*
// Employee info
class Employee {
public:
    // It's the unique ID of each node.
    // unique id of this employee
    int id;
    // the importance value of this employee
    int importance;
    // the id of direct subordinates
    vector<int> subordinates;
};
*/
class Solution {
public:
vector<Employee*> E;
    int find_e(int id){
        for(int i = 0;i<E.size();i++){
            if(E[i]->id==id){
                return i;
            }
        }
        return -1;
    }
    int getImportance(vector<Employee*> employees, int id) {
        E = employees;
        int sum = 0;
        queue<int> que;
        int pos = find_e(id);
        if(id == -1){
            return 0;
        }
        que.push(pos);
        while(!que.empty())
        {
            int cur = que.front();
            que.pop();
            cout<<"s";
            sum+=employees[cur]->importance;
            for(int i = 0;i<employees[cur]->subordinates.size();i++){
                cout<<"s";
                que.push(find_e
                (employees[cur]->subordinates[i]));
            }
        }
        return sum;
    }
};
// @lc code=end

