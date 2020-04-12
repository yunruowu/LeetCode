/*
 * @Description: 
 * @Version: 2.0
 * @Author: yunruowu
 * @Date: 2020-02-18 11:21:20
 * @LastEditors: yunruowu
 * @LastEditTime: 2020-03-14 11:22:32
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
vector<string> to_word(string S){
        int i =0;
        vector<string> word;
        string ins;
        while(i<S.size()){
            ins.clear();
            while(S[i]!=' '&&i<S.size()){
                ins +=S[i];
                i++;
            }
            word.push_back(ins);
            i++;
        }
        return word;
    }
// ！dsdsd
//TODO:
//*
//?
////fewfsfsfsfs
int main(int argc, char const *argv[])
{
    set< vector<int> >s;
    vector<int> a;
    a.push_back(1);
    a.push_back(2);
    vector<int> b;
    b.push_back(2);
    b.push_back(1);
    s.insert(a);
    sort(b.begin(), b.end());
        s.insert(b);
    set< vector<int> >::iterator it;
    for(it=s.begin ();it!=s.end ();it++)
    {
        vector<int> m = *it;
        Prinetvec(m);
    }
}

