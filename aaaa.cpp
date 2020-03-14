/*
 * @Description: 
 * @Version: 2.0
 * @Author: yunruowu
 * @Date: 2020-02-18 11:21:20
 * @LastEditors: yunruowu
 * @LastEditTime: 2020-03-13 10:48:01
 */


#include "useforme.h"
void tt(){
    cout<<"  ss";
    TreeNode* r = new TreeNode(0);
    r->val = 1;
    TreeNode* l;
    r->left = l;
    l->val = 10;
    cout<<r->left->val;
}

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

int main(int argc, char const *argv[])
{
    vector<int> pos(2,0);
    Prinetvec(pos);
    return 0;
}
