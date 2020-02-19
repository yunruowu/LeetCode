/*
 * @Description: 
 * @Version: 2.0
 * @Author: yunruowu
 * @Date: 2020-02-19 19:07:21
 * @LastEditors: yunruowu
 * @LastEditTime: 2020-02-19 19:18:07
 */
/*
 * @lc app=leetcode.cn id=804 lang=cpp
 *
 * [804] 唯一摩尔斯密码词
 *
 * https://leetcode-cn.com/problems/unique-morse-code-words/description/
 *
 * algorithms
 * Easy (73.91%)
 * Likes:    99
 * Dislikes: 0
 * Total Accepted:    21.7K
 * Total Submissions: 29.3K
 * Testcase Example:  '["gin", "zen", "gig", "msg"]'
 *
 * 国际摩尔斯密码定义一种标准编码方式，将每个字母对应于一个由一系列点和短线组成的字符串， 比如: "a" 对应 ".-", "b" 对应 "-...",
 * "c" 对应 "-.-.", 等等。
 * 
 * 为了方便，所有26个英文字母对应摩尔斯密码表如下：
 * 
 * 
 * [".-","-...","-.-.","-..",".","..-.","--.","....","..",".---","-.-",".-..","--","-.","---",".--.","--.-",".-.","...","-","..-","...-",".--","-..-","-.--","--.."]
 * 
 * 给定一个单词列表，每个单词可以写成每个字母对应摩尔斯密码的组合。例如，"cab" 可以写成 "-.-..--..."，(即 "-.-." +
 * "-..." + ".-"字符串的结合)。我们将这样一个连接过程称作单词翻译。
 * 
 * 返回我们可以获得所有词不同单词翻译的数量。
 * 
 * 例如:
 * 输入: words = ["gin", "zen", "gig", "msg"]
 * 输出: 2
 * 解释: 
 * 各单词翻译如下:
 * "gin" -> "--...-."
 * "zen" -> "--...-."
 * "gig" -> "--...--."
 * "msg" -> "--...--."
 * 
 * 共有 2 种不同翻译, "--...-." 和 "--...--.".
 * 
 * 
 * 
 * 
 * 注意:
 * 
 * 
 * 单词列表words 的长度不会超过 100。
 * 每个单词 words[i]的长度范围为 [1, 12]。
 * 每个单词 words[i]只包含小写字母。
 * 
 * 
 */
#include "useforme.h"
// @lc code=start
class Solution {
public:
    // string change(char c){
        
    // }
    int uniqueMorseRepresentations(vector<string>& words) {
        vector<string> Morse = {".-","-...","-.-.","-..",".","..-.","--.","....","..",".---","-.-",".-..","--","-.","---",".--.","--.-",".-.","...","-","..-","...-",".--","-..-","-.--","--.."};
        vector<string> ans;
        string M;
        string s;
        for(int i = 0;i<words.size();i++){
            M = "";
            s = words[i];
            for(int j=0; j<s.size();j++){
                M = M + Morse[s[j]-'a'];
            }
            // cout<<M<<endl;
            if(find(ans.begin(),ans.end(),M)==ans.end()){
                ans.push_back(M);
            }
        }
        return ans.size();
    }
};
// @lc code=end

