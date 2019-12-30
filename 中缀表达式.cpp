#include <iostream>
#include <vector>
#include <stack>
#include <string>
#include <stdlib.h>
using namespace std;
class Solution
{
public:
    stack<int> data_stack;
    stack<char> op_stack;

    int evalRPN(vector<string> &tokens)
    {

        for (int i = 0; i < tokens.size(); i++)
        {
            
            switch ((char)tokens[i][0])
            {
            case '+':
                if (op_stack.top() != '(')
                {
                    data_stack.push(cal());
                }
                op_stack.push('+');
                break;
            case '-':
            if (op_stack.top() != '(')
                {
                    data_stack.push(cal());
                }
                op_stack.push('-');
                break;
            case '*':
            if (op_stack.top() != '('&&op_stack.top() != '+'&&op_stack.top() != '-')
                {
                    cout<<"error2";
                    data_stack.push(cal());
                }
                cout<<"error1";
                op_stack.push('*');
                break;
            case '/':
             if (op_stack.top() != '('&&op_stack.top() != '+'&&op_stack.top() != '-')
                {
                    data_stack.push(cal());
                }
                op_stack.push('/');
                break;
            case '(':
                op_stack.push('(');
                break;
            case ')':
                while (op_stack.top()!= '(')
                {
                    data_stack.push(cal());
                }
                op_stack.pop();
                break;
            default:
                int n = atoi(tokens[i].c_str());
                data_stack.push(n);
                break;
            }
            cout<<tokens[i]<<" ";
            if(!op_stack.empty()){
                cout<<" "<<op_stack.top();
            }
            if(!data_stack.empty()){
                cout<<" "<<data_stack.top();
            }
            cout<<endl;
        }
        while (!data_stack.empty())
        {
            /* code */
            cout << data_stack.top() << endl;
            data_stack.pop();
        }
        while (!op_stack.empty())
        {
            /* code */
            cout << op_stack.top() << endl;
            op_stack.pop();
        }
        return 6;
    }
    int cal()
    {
        char op = op_stack.top();
        op_stack.pop();
        int b = data_stack.top();
        data_stack.pop();
        int a = data_stack.top();
        data_stack.pop();
        switch (op)
        {
        case '+':
            /* code */
            return a + b;
        case '-':
            /* code */
            return a - b;
        case '*':
            /* code */
            return a * b;
        case '/':
            /* code */
            return a / b;
        default:
            break;
        }
    }
};
int main()
{
    Solution s;
    vector<string> v;
     v.push_back("(");
      v.push_back("(");
    v.push_back("2");
    v.push_back("+");
    v.push_back("1");
     v.push_back(")");
    v.push_back("*");
    v.push_back("3");
    
    v.push_back(")");
    // v.push_back("123");
    // v.push_back("3");
    // v.push_back("2");
    // v.push_back("2");
    // v.push_back("2324");
    s.evalRPN(v);
    return 0;
}