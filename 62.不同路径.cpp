/*
 * @lc app=leetcode.cn id=62 lang=cpp
 *
 * [62] 不同路径
 *
 * https://leetcode-cn.com/problems/unique-paths/description/
 *
 * algorithms
 * Medium (59.73%)
 * Likes:    563
 * Dislikes: 0
 * Total Accepted:    110.4K
 * Total Submissions: 182.2K
 * Testcase Example:  '3\n2'
 *
 * 一个机器人位于一个 m x n 网格的左上角 （起始点在下图中标记为“Start” ）。
 * 
 * 机器人每次只能向下或者向右移动一步。机器人试图达到网格的右下角（在下图中标记为“Finish”）。
 * 
 * 问总共有多少条不同的路径？
 * 
 * 
 * 
 * 例如，上图是一个7 x 3 的网格。有多少可能的路径？
 * 
 * 
 * 
 * 示例 1:
 * 
 * 输入: m = 3, n = 2
 * 输出: 3
 * 解释:
 * 从左上角开始，总共有 3 条路径可以到达右下角。
 * 1. 向右 -> 向右 -> 向下
 * 2. 向右 -> 向下 -> 向右
 * 3. 向下 -> 向右 -> 向右
 * 
 * 
 * 示例 2:
 * 
 * 输入: m = 7, n = 3
 * 输出: 28
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 1 <= m, n <= 100
 * 题目数据保证答案小于等于 2 * 10 ^ 9
 * 
 * 
 */
#include "useforme.h"
// @lc code=start
class Solution {
public:
    int l,c;
    int get(int m , int n){//超时
        if(m == l && n == c){
            return 1;
        }
        if(m == l){
            return get(m, n+1);
        }
        if(n == c){
            return get(m+1, n);
        }
        return get(m, n+1)+ get(m+1, n);
    }
    int fun1(int m, int n) {//超时
        l = m;
        c = n;
        return get(1,1);
    }
    
    int with_mem(int m ,int n, vector<vector<int> >&mem ){
        // cout<<m<<" "<<n<<endl;
        if(mem[m][n]!=0){//直接返回
            return mem[m][n];
        }
        if(m == l-1&&n ==c-1){
            return mem[m][n];
        }
        else if(m == l-1){
            // cout<<"w";
            mem[m][n] = with_mem(m,n+1,mem);
        }
        else if(n == c-1){
            // cout<<"x";
            mem[m][n] = with_mem(m+1, n , mem);
        }else{
            // cout<<"y";
            mem[m][n] = with_mem(m+1, n , mem)+ with_mem(m,n+1,mem);
        }
        
        
        return mem[m][n];
    }
    int fun2(int m, int n){
        l = m;
        c = n;
        vector<vector<int> >mem(l,vector<int>(c,0));
        mem[l-1][c-1] = 1;
        with_mem(0,0,mem);
        // for(int i = 0; i<m;i++){
        //     for(int j =0;j<n;j++){
        //         cout<<mem[i][j]<<" ";
        //     }
        //     cout<<endl;
        // }
        return mem[0][0];
    }
    int fun3(int m, int n){
        vector<vector<int> >mem(m,vector<int>(n,0));
        
        for(int i = m-1;i>=0;i--){
            for(int j = n-1;j>=0;j--){
                // cout<<i<<" "<<j<<endl;
                if(j==n-1||i==m-1){
                    mem[i][j] = 1;
                    
                }
                else{
                    mem[i][j]=mem[i][j+1]+mem[i+1][j];
                }
                
            }
        }
        return mem[0][0];
    }
    int uniquePaths(int m, int n) {
        // return fun1(m,n); //递归
        // return fun2(m,n); //备忘录,可以通过,自己华花时间在处理else if上,值得注意
        return fun3(m,n);
    }
};
// @lc code=end

int main(int argc, char const *argv[])
{
    
    Solution s;
    cout<<s.uniquePaths(7,3);
    return 0;
}
