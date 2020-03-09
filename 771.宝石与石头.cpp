/*
 * @Description: 
 * @Version: 2.0
 * @Author: yunruowu
 * @Date: 2020-03-08 23:14:27
 * @LastEditors: yunruowu
 * @LastEditTime: 2020-03-08 23:16:06
 */
/*
 * @lc app=leetcode.cn id=771 lang=cpp
 *
 * [771] 宝石与石头
 *
 * https://leetcode-cn.com/problems/jewels-and-stones/description/
 *
 * algorithms
 * Easy (81.58%)
 * Likes:    509
 * Dislikes: 0
 * Total Accepted:    71.2K
 * Total Submissions: 86.9K
 * Testcase Example:  '"aA"\n"aAAbbbb"'
 *
 *  给定字符串J 代表石头中宝石的类型，和字符串 S代表你拥有的石头。 S 中每个字符代表了一种你拥有的石头的类型，你想知道你拥有的石头中有多少是宝石。
 * 
 * J 中的字母不重复，J 和 S中的所有字符都是字母。字母区分大小写，因此"a"和"A"是不同类型的石头。
 * 
 * 示例 1:
 * 
 * 输入: J = "aA", S = "aAAbbbb"
 * 输出: 3
 * 
 * 
 * 示例 2:
 * 
 * 输入: J = "z", S = "ZZ"
 * 输出: 0
 * 
 * 
 * 注意:
 * 
 * 
 * S 和 J 最多含有50个字母。
 * J 中的字符不重复。
 * 
 * 
 */
#include "useforme.h"
// @lc code=start
class Solution {
public:
    int numJewelsInStones(string J, string S) {
        int ans = 0;
        for(int i = 0; i<S.size();i++){
            for(int j = 0; j<J.size();j++){
                if(S[i]==J[j]){
                    ans++;
                }
            }
        }
        return ans;
    }
};
// @lc code=end

