/*
 * @Description: 
 * @Version: 2.0
 * @Author: yunruowu
 * @Date: 2020-02-18 11:21:20
 * @LastEditors: yunruowu
 * @LastEditTime: 2020-03-04 18:28:45
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
    // t();
    // tt();
    char a[20];//姓
    char b[50];
    char Name[10];//名
    char pass;//接收逗号
    int age;
    char Num[4];//假设学号四位;
    int grade_First;//第一学年平均
    int grade_Second;//第二
    int grade_Third;//第三
    int grade_Fourth;//第四
    //输入 姓 空格 名 逗号 年龄 逗号 学号 逗号 成绩
    // cin>>a>>b;//姓名
    // if(cin.get()==',' ){
    //     cin>>pass;
    // }
    
    cin>>a;
    cout<<a;
    cin>>b;
    cout<<b;
    int i = 0;
    while(i<50&&b[i]!='\0'){
        while(b[i]!=','){
            Name[i]=b[i];
            i++;
        }
        //b[i]==','
        i++;
        int temp=0;
        while(b[i]!=','){
            temp=temp*10+(b[i]-'0');
            i++;
        }
        
        age = temp;
        //b[i]==','
        i++;
        int j = 0;
        while(b[i]!=','){
            Num[j]=b[i];
            i++;
            j++;
        }
        
        //b[i]==','
        i++;
        temp=0;
        while(b[i]!=','){
            temp=temp*10+(b[i]-'0');
            i++;
        }
        grade_First = temp;
        i++;

        temp=0;
        while(b[i]!=','){
            temp=temp*10+(b[i]-'0');
            i++;
        }
        grade_Second = temp;
        i++;

        temp=0;
        while(b[i]!=','){
            temp=temp*10+(b[i]-'0');
            i++;
        }
        grade_Third = temp;
        i++;

        temp=0;
        while(b[i]!=','&&b[i]!='\0'){
            temp=temp*10+(b[i]-'0');
            i++;
        }
        grade_Fourth = temp;
        //b[i]=='\0'
        
    }

    cout<<endl<<grade_Fourth;
    // cout<<"s";
    return 0;
}
