/*
 * @lc app=leetcode.cn id=949 lang=cpp
 *
 * [949] 给定数字能组成的最大时间
 *
 * https://leetcode-cn.com/problems/largest-time-for-given-digits/description/
 *
 * algorithms
 * Easy (34.99%)
 * Likes:    38
 * Dislikes: 0
 * Total Accepted:    4.3K
 * Total Submissions: 12.3K
 * Testcase Example:  '[1,2,3,4]'
 *
 * 给定一个由 4 位数字组成的数组，返回可以设置的符合 24 小时制的最大时间。
 * 
 * 最小的 24 小时制时间是 00:00，而最大的是 23:59。从 00:00 （午夜）开始算起，过得越久，时间越大。
 * 
 * 以长度为 5 的字符串返回答案。如果不能确定有效时间，则返回空字符串。
 * 
 * 
 * 
 * 示例 1：
 * 
 * 输入：[1,2,3,4]
 * 输出："23:41"
 * 
 * 
 * 示例 2：
 * 
 * 输入：[5,5,5,5]
 * 输出：""
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * A.length == 4
 * 0 <= A[i] <= 9
 * 
 * 
 */
#include "useforme.h"



// @lc code=start
class Solution {
public:
    bool isTime(vector<int>A){
        cout<<A[0]<<A[1]<<A[2]<<A[3]<<"sds"<<endl;
        if(A[0]>2){
            return false;
        }
        if(A[0]==2&&A[1]>3){
            return false;
        }
        if(A[2]>5){
            return false;
        }
        return true;
    }
    int tonum(vector<int> num){
        int i =0;
        int ans =0;
        while(i<4){
            // cout<<ans;
            ans = ans*10+num[i];
            i++;
        }
        cout<<ans;
        return ans;
    }
    string largestTimeFromDigits(vector<int>& A) {
        vector<int> a(4,1);
        vector<int> use;
        // cout<<use[0];
        vector<vector<int>> ans;
        int maxT = -1;    
        for(int i = 0; i<4;i++){
            a[i]=0;
            use.push_back(A[i]);
            for(int j = 0; j<4; j++){
                if(a[j]==0){
                    continue;
                }
                a[j] = 0;
                use.push_back(A[j]);
                for(int m =0 ;m<4;m++){
                    if(a[m]==0){
                        continue;
                    }
                    a[m]=0;
                    use.push_back(A[m]);
                    for(int n = 0; n<4;n++){
                        

                        // cout<<endl;
                        if(a[n]==0){
                            continue;
                        }
                        a[n]=0;
                        use.push_back(A[n]);
                        
                        if(isTime(use))
                        {
                            int numa = tonum(use);
                            cout<<numa<<endl;
                            if(numa>maxT){
                                maxT = numa;
                                ans.push_back(use);
                            }
                        }
                        a[n]=1;
                        use.pop_back();
                    }
                    a[m]=1;
                    use.pop_back();
                }
                a[j]=1;
                use.pop_back();
            }
            a[i]=1;
            use.pop_back();
        }
        if(maxT==-1){
            return "";
        }
        string re = "";
        int i =0 ;
        vector<int> temp = ans[ans.size()-1];
        for(int k = 0; k<4;k++){
            cout<<temp[k]<<" e";
        }
        while(i<4){
            if(i==2){
                re += ':';
            }
            re+=temp[i]+'0';
            i++;
        }
        return re;
    }
};
// @lc code=end

