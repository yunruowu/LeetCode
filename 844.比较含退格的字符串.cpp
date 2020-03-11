/*
 * @Description: 
 * @Version: 2.0
 * @Author: yunruowu
 * @Date: 2020-03-11 11:52:39
 * @LastEditors: yunruowu
 * @LastEditTime: 2020-03-11 12:12:53
 */
/*
 * @lc app=leetcode.cn id=844 lang=cpp
 *
 * [844] 比较含退格的字符串
 *
 * https://leetcode-cn.com/problems/backspace-string-compare/description/
 *
 * algorithms
 * Easy (49.89%)
 * Likes:    92
 * Dislikes: 0
 * Total Accepted:    16.1K
 * Total Submissions: 32K
 * Testcase Example:  '"ab#c"\n"ad#c"'
 *
 * 给定 S 和 T 两个字符串，当它们分别被输入到空白的文本编辑器后，判断二者是否相等，并返回结果。 # 代表退格字符。
 * 
 * 
 * 
 * 示例 1：
 * 
 * 输入：S = "ab#c", T = "ad#c"
 * 输出：true
 * 解释：S 和 T 都会变成 “ac”。
 * 
 * 
 * 示例 2：
 * 
 * 输入：S = "ab##", T = "c#d#"
 * 输出：true
 * 解释：S 和 T 都会变成 “”。
 * 
 * 
 * 示例 3：
 * 
 * 输入：S = "a##c", T = "#a#c"
 * 输出：true
 * 解释：S 和 T 都会变成 “c”。
 * 
 * 
 * 示例 4：
 * 
 * 输入：S = "a#c", T = "b"
 * 输出：false
 * 解释：S 会变成 “c”，但 T 仍然是 “b”。
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 1 <= S.length <= 200
 * 1 <= T.length <= 200
 * S 和 T 只含有小写字母以及字符 '#'。
 * 
 * 
 * 
 * 
 */
#include "useforme.h"
// @lc code=start
class Solution {
public:
    bool backspaceCompare(string S, string T) {
        for(int i=0; i<S.size(); i++){
            while(i==0&&S[i]=='#'){
                S.erase(i,1);
            }
            if(S[i]=='#'){
                S.erase(i-1,2);
                cout<<S<<i<<"  ";
                i-=2;
            }
        }
        for(int i=0; i<T.size(); i++){
            while(i==0&&T[i]=='#'){
                T.erase(i,1);
            }
            if(T[i]=='#'){
                T.erase(i-1,2);
                i-=2;
                cout<<T<<"   ";
            }
        }
        cout<<S<<" "<<T;
    return S==T;
    }
};
// @lc code=end

