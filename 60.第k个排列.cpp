/*
 * @lc app=leetcode.cn id=60 lang=cpp
 *
 * [60] 第k个排列
 *
 * https://leetcode-cn.com/problems/permutation-sequence/description/
 *
 * algorithms
 * Medium (48.55%)
 * Likes:    246
 * Dislikes: 0
 * Total Accepted:    34.6K
 * Total Submissions: 71.1K
 * Testcase Example:  '3\n3'
 *
 * 给出集合 [1,2,3,…,n]，其所有元素共有 n! 种排列。
 * 
 * 按大小顺序列出所有排列情况，并一一标记，当 n = 3 时, 所有排列如下：
 * 
 * 
 * "123"
 * "132"
 * "213"
 * "231"
 * "312"
 * "321"
 * 
 * 
 * 给定 n 和 k，返回第 k 个排列。
 * 
 * 说明：
 * 
 * 
 * 给定 n 的范围是 [1, 9]。
 * 给定 k 的范围是[1,  n!]。
 * 
 * 
 * 示例 1:
 * 
 * 输入: n = 3, k = 3
 * 输出: "213"
 * 
 * 示例 2:
 * 
 * 输入: n = 4, k = 9
 * 输出: "2314"
 * 
 */
#include "useforme.h"
// @lc code=start
class Solution {
public:
    vector<string> ans;
    int final;
    int num; 
    void dfs(string s, int nowP, vector<int>tags){
        // cout<<s<<endl;
        // Prinetvec(tags);
        if(ans.size()==num){
            return;
        }
        if(final==nowP){
            ans.push_back(s);
            return;
        }
        for(int i = 0; i<final; i++){
            // cout<<tags[i]<<"zheli"<<endl;
            if(tags[i] == 0)
            {
                // cout<<"zheli"<<endl;
                tags[i]=1;
                char a = (i+1)+'0';
                dfs(s+(a), nowP+1, tags);
                tags[i]=0;
            }
        }
        return;
    }
    int getmul(int n){
        // cout<<n<<endl;
        int ans =1;
        for(int i = 1 ; i<=n; i++){
            ans = i*ans;
            // cout<<n<<endl;
        }
        return ans;
    }
    string getPermutation(int n, int k) {
        if(n==1)
            return "1";
        int num = 0;
        k=k-1;
        vector<int> tags(9,0);
        int nn = n;
        string s = "";
        while(n>1){
            int p = getmul(n-1);
            num = k/p;
            int temp = 0;
            cout<<num<<endl;
            for (int i = 0; i < nn; i++)
            {
                if(tags[i]==0){
                    temp++;
                }
                if(temp==num+1){
                    temp = i+1;
                    break;
                }
            }
            tags[temp-1]=1;
            s += temp+'0';
            k = k%p;
            // cout<<k<<endl;
            n--;
        }
        // cout<<k;
        if(k==0){
            for (int i = 0; i < nn; i++)
            {
                if(tags[i]==0){
                    s += (i+1)+'0';
                }
                
            }
        }else{
            for (int i = nn-1; i >=0; i--)
            {
                if(tags[i]==0){
                    s += (i+1)+'0';
                }
                
            }
        }
        
        return s;
    }
};


// @lc code=end

int main(int argc, char const *argv[])
{
    Solution s;
    // cout<<"1111";
    cout<<s.getPermutation(4,9);
    return 0;
}
