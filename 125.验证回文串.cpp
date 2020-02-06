/*
 * @Description: 
 * @Version: 2.0
 * @Author: yunruowu
 * @Date: 2020-02-05 18:12:57
 * @LastEditors  : yunruowu
 * @LastEditTime : 2020-02-05 18:51:57
 */
/*
 * @lc app=leetcode.cn id=125 lang=cpp
 *
 * [125] 验证回文串
 *
 * https://leetcode-cn.com/problems/valid-palindrome/description/
 *
 * algorithms
 * Easy (42.16%)
 * Likes:    151
 * Dislikes: 0
 * Total Accepted:    75K
 * Total Submissions: 177.8K
 * Testcase Example:  '"A man, a plan, a canal: Panama"'
 *
 * 给定一个字符串，验证它是否是回文串，只考虑字母和数字字符，可以忽略字母的大小写。
 * 
 * 说明：本题中，我们将空字符串定义为有效的回文串。
 * 
 * 示例 1:
 * 
 * 输入: "A man, a plan, a canal: Panama"
 * 输出: true
 * 
 * 
 * 示例 2:
 * 
 * 输入: "race a car"
 * 输出: false
 * 
 * 
 */
#include "useforme.h"
// @lc code=start
class Solution {
public:
    bool isEqual(char t1,char t2){
        if((isalpha(t1)!=0)&&(isalpha(t2)!=0))
            return (t1-'a'== t2-'a')
                || (t1-'A'== t2-'a')
                || (t1-'a'== t2-'A')
                || (t1-'A'== t2-'A');
        else
        {
            return t1 - '0' == t2 - '0';
        }
        
    }

    bool isPalindrome(string s) {
        if(s == ""){
            return true;
        }
        int j = s.size() - 1;
        int i = 0;
        while(i<j){
            cout<<s[i]<<" dfsfs "<<s[j]<<endl;
            
            while (isalnum(s[i])==0 && i< j){
                // cout<<i<< " ";
                i++;
            }
            cout<< endl;
            while (isalnum(s[j])==0 && j>i){
                // cout<<j<<" ";
                j--;
            }
            // cout<<endl;
            // cout<<"     sasasa";
            if(i>=j){
                return true;
            }
            if(isEqual(s[i],s[j])==true){
                i++;
                j--;
            }else{
                return false;
            }
        }
        return true;
    }
};
// @lc code=end
int main(int argc, char const *argv[])
{
    cout<<isalnum('1');
    return 0;
}
