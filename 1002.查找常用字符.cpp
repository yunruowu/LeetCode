/*
 * @lc app=leetcode.cn id=1002 lang=cpp
 *
 * [1002] 查找常用字符
 *
 * https://leetcode-cn.com/problems/find-common-characters/description/
 *
 * algorithms
 * Easy (68.39%)
 * Likes:    89
 * Dislikes: 0
 * Total Accepted:    14.6K
 * Total Submissions: 21.3K
 * Testcase Example:  '["bella","label","roller"]'
 *
 * 给定仅有小写字母组成的字符串数组 A，返回列表中的每个字符串中都显示的全部字符（包括重复字符）组成的列表。例如，如果一个字符在每个字符串中出现 3
 * 次，但不是 4 次，则需要在最终答案中包含该字符 3 次。
 * 
 * 你可以按任意顺序返回答案。
 * 
 * 
 * 
 * 示例 1：
 * 
 * 输入：["bella","label","roller"]
 * 输出：["e","l","l"]
 * 
 * 
 * 示例 2：
 * 
 * 输入：["cool","lock","cook"]
 * 输出：["c","o"]
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 1 <= A.length <= 100
 * 1 <= A[i].length <= 100
 * A[i][j] 是小写字母
 * 
 * 
 */
#include "useforme.h"
// @lc code=start
class Solution {
public:
    vector<string> commonChars(vector<string>& A) {
        vector<int> nums(26, 0);
        for(int i = 0; i<A[0].size(); i++){
            nums[A[0][i]-'a']++;
        }
            
        for(int i = 1; i<A.size(); i++){
            vector<int> nums_temp(26, 0);
            for (int j = 0; j < A[i].size(); j++)
            {
                nums_temp[A[i][j]-'a']++;
            }
            
            for(int k = 0; k<26; k++){
                nums[k] = min(nums[k], nums_temp[k]);
            }
            
        }
        vector<string> ans;
        for(int k = 0; k<26; k++){
            if(nums[k]!=0)
            {
                for(int m = 0; m<nums[k]; m++){
                    string temp = "";
                    temp += 'a'+k;
                    ans.push_back(temp);
                }
                
            }
        }
        return ans;
    }
};
// @lc code=end

