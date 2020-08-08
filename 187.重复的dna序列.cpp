/*
 * @lc app=leetcode.cn id=187 lang=cpp
 *
 * [187] 重复的DNA序列
 *
 * https://leetcode-cn.com/problems/repeated-dna-sequences/description/
 *
 * algorithms
 * Medium (43.95%)
 * Likes:    94
 * Dislikes: 0
 * Total Accepted:    17.9K
 * Total Submissions: 40.3K
 * Testcase Example:  '"AAAAACCCCCAAAAACCCCCCAAAAAGGGTTT"'
 *
 * 所有 DNA 都由一系列缩写为 A，C，G 和 T 的核苷酸组成，例如：“ACGAATTCCG”。在研究 DNA 时，识别 DNA
 * 中的重复序列有时会对研究非常有帮助。
 * 
 * 编写一个函数来查找目标子串，目标子串的长度为 10，且在 DNA 字符串 s 中出现次数超过一次。
 * 
 * 
 * 
 * 示例：
 * 
 * 输入：s = "AAAAACCCCCAAAAACCCCCCAAAAAGGGTTT"
 * 输出：["AAAAACCCCC", "CCCCCAAAAA"]
 * 
 */
#include "useforme.h"
// @lc code=start
class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        vector<string> ans1;
        set<string> ans;
        set<string> ans2;
        if(s ==""){
            return ans1;
        }
        if(s.size()<10){
            return ans1;
        }
        for(int i = 0; i<s.size()-9; i++){
            string temp = s.substr(i, 10);
            cout<<temp<<endl;
            if(ans.find(temp)==ans.end()){
                ans.insert(temp);
                
            }else{
                ans2.insert(temp);
            }
        }
        ans1.assign(ans2.begin(), ans2.end());
        return ans1;
    }
};
// @lc code=end

