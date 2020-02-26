/*
 * @Description: 
 * @Version: 2.0
 * @Author: yunruowu
 * @Date: 2020-02-26 22:25:37
 * @LastEditors: yunruowu
 * @LastEditTime: 2020-02-26 23:03:25
 */
/*
 * @lc app=leetcode.cn id=500 lang=cpp
 *
 * [500] 键盘行
 *
 * https://leetcode-cn.com/problems/keyboard-row/description/
 *
 * algorithms
 * Easy (68.06%)
 * Likes:    78
 * Dislikes: 0
 * Total Accepted:    14.4K
 * Total Submissions: 21.1K
 * Testcase Example:  '["Hello","Alaska","Dad","Peace"]'
 *
 * 给定一个单词列表，只返回可以使用在键盘同一行的字母打印出来的单词。键盘如下图所示。
 * 
 * 
 * 
 * 
 * 
 * 
 * 
 * 示例：
 * 
 * 输入: ["Hello", "Alaska", "Dad", "Peace"]
 * 输出: ["Alaska", "Dad"]
 * 
 * 
 * 
 * 
 * 注意：
 * 
 * 
 * 你可以重复使用键盘上同一字符。
 * 你可以假设输入的字符串将只包含字母。
 * 
 */
#include "useforme.h"
// @lc code=start
class Solution {
public:
    int findkeyline(char c){
        vector<char> first = {'q','w','e','r','t','y','u','i','o','p'};
        vector<char> second = {'a','s','d','f','g','h','j','k','l'};
        vector<char> third = {'z','x','c','v','b','n','m'};
        
        if(find(first.begin(),first.end(),c)!=first.end()){
            return 1;
        }
        if(find(second.begin(),second.end(),c)!=second.end()){
            return 2;
        }
        if(find(third.begin(),third.end(),c)!=third.end()){
            return 3;
        }
        return 0;
    }
    int tag = 0;
    vector<string> findWords(vector<string>& words) {
        vector<string> ans;
        
        for(int i = 0; i<words.size(); i++){
            string temp = words[i];
            // cout<<endl;
            tag = 0;
            transform(temp.begin(),temp.end(),temp.begin(),::tolower);
            int pos = findkeyline(temp[0]);
            for(int j = 1; j<temp.size(); j++){
                // cout<<pos;
                if(pos!=findkeyline(temp[j])){
                    
                    tag = 1;
                    break;
                }
            }
            if(tag != 1){
                ans.push_back(words[i]);
            }
            
        }
        return ans;
    }
};
// @lc code=end

