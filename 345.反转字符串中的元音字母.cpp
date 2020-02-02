/*
 * @Description: 
 * @Version: 2.0
 * @Author: yunruowu
 * @Date: 2020-01-31 10:58:19
 * @LastEditors  : yunruowu
 * @LastEditTime : 2020-01-31 13:30:04
 */
/*
 * @lc app=leetcode.cn id=345 lang=cpp
 *
 * [345] 反转字符串中的元音字母
 *
 * https://leetcode-cn.com/problems/reverse-vowels-of-a-string/description/
 *
 * algorithms
 * Easy (48.44%)
 * Likes:    73
 * Dislikes: 0
 * Total Accepted:    22.6K
 * Total Submissions: 46.4K
 * Testcase Example:  '"hello"'
 *
 * 编写一个函数，以字符串作为输入，反转该字符串中的元音字母。
 * 
 * 示例 1:
 * 
 * 输入: "hello"
 * 输出: "holle"
 * 
 * 
 * 示例 2:
 * 
 * 输入: "leetcode"
 * 输出: "leotcede"
 * 
 * 说明:
 * 元音字母不包含字母"y"。
 * 
 */
#include<string>
#include<vector>
using namespace std;
// @lc code=start
class Solution {
public:
    bool isVowel(char c){
        if(c == 'a'||c == 'e'||c == 'i'||c == 'o'||c == 'u'){
            return true;
        }if(c == 'A'||c == 'E'||c == 'I'||c == 'O'||c == 'U'){
            return true;
        }
        return false;
    }
    string reverseVowels(string s) {
        int n = s.size();
        // int len = 0;
        int end = n-1;
        string t;
        int i =0;
        
        i =0;
        // int j = 0;
        while(i<end){            
            if(isVowel(s[i])==true){
                while (isVowel(s[end])!=true)
                {
                    end--;
                }

                char c = s[end];
                char r = s[i];
                s[i]=c;
                s[end]=r;
                end--;
                // j++;
            }
            
            i++;
        }
        return s;        
    }
};
// @lc code=end

