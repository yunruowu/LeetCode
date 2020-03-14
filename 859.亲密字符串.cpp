/*
 * @Description: 
 * @Version: 2.0
 * @Author: yunruowu
 * @Date: 2020-03-12 09:14:41
 * @LastEditors: yunruowu
 * @LastEditTime: 2020-03-12 09:30:39
 */
/*
 * @lc app=leetcode.cn id=859 lang=cpp
 *
 * [859] 亲密字符串
 *
 * https://leetcode-cn.com/problems/buddy-strings/description/
 *
 * algorithms
 * Easy (27.81%)
 * Likes:    78
 * Dislikes: 0
 * Total Accepted:    10.7K
 * Total Submissions: 37.1K
 * Testcase Example:  '"ab"\n"ba"'
 *
 * 给定两个由小写字母构成的字符串 A 和 B ，只要我们可以通过交换 A 中的两个字母得到与 B 相等的结果，就返回 true ；否则返回 false
 * 。
 * 
 * 
 * 
 * 示例 1：
 * 
 * 输入： A = "ab", B = "ba"
 * 输出： true
 * 
 * 
 * 示例 2：
 * 
 * 输入： A = "ab", B = "ab"
 * 输出： false
 * 
 * 
 * 示例 3:
 * 
 * 输入： A = "aa", B = "aa"
 * 输出： true
 * 
 * 
 * 示例 4：
 * 
 * 输入： A = "aaaaaaabc", B = "aaaaaaacb"
 * 输出： true
 * 
 * 
 * 示例 5：
 * 
 * 输入： A = "", B = "aa"
 * 输出： false
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 0 <= A.length <= 20000
 * 0 <= B.length <= 20000
 * A 和 B 仅由小写字母构成。
 * 
 * 
 */
#include "useforme.h"
// @lc code=start
class Solution {
public:
    bool buddyStrings(string A, string B) {
        if(A.size()==2){
            return A[0]==B[1]&&A[1]==B[0];
        }
        if(A.size()>=2){
            if(A==B){}
        }

        int i = 0;
        if(A.size()!=B.size()){
            return false;
        }
        int pos1 = -1;
        int pos2 = -1;
        while(i<A.size()){
            if(A[i]!=B[i]){
                if(pos1==-1){
                    pos1 = i;
                }
                else{
                    pos2 = i;
                    char c = A[pos1];
                    A[pos1] = A[pos2];
                    A[pos2] = c;
                    return A==B;
                }
            }
            i++;
        }
        if(pos1+pos2==-2){
            int a[26]={0};
            for(int i=0;i<A.size();i++){
                a[A[i]-'a']++;
            }
            for(int i=0;i<26;i++){
                if(a[i]>=2) return true;
            }
        }
        return false;
    }
};
// @lc code=end

