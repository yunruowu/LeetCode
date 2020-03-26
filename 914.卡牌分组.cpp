/*
 * @Description: 
 * @Version: 2.0
 * @Author: yunruowu
 * @Date: 2020-03-26 09:55:51
 * @LastEditors: yunruowu
 * @LastEditTime: 2020-03-26 10:17:14
 */
/*
 * @lc app=leetcode.cn id=914 lang=cpp
 *
 * [914] 卡牌分组
 *
 * https://leetcode-cn.com/problems/x-of-a-kind-in-a-deck-of-cards/description/
 *
 * algorithms
 * Easy (32.80%)
 * Likes:    86
 * Dislikes: 0
 * Total Accepted:    10K
 * Total Submissions: 30.4K
 * Testcase Example:  '[1,2,3,4,4,3,2,1]'
 *
 * 给定一副牌，每张牌上都写着一个整数。
 * 
 * 此时，你需要选定一个数字 X，使我们可以将整副牌按下述规则分成 1 组或更多组：
 * 
 * 
 * 每组都有 X 张牌。
 * 组内所有的牌上都写着相同的整数。
 * 
 * 
 * 仅当你可选的 X >= 2 时返回 true。
 * 
 * 
 * 
 * 示例 1：
 * 
 * 输入：[1,2,3,4,4,3,2,1]
 * 输出：true
 * 解释：可行的分组是 [1,1]，[2,2]，[3,3]，[4,4]
 * 
 * 
 * 示例 2：
 * 
 * 输入：[1,1,1,2,2,2,3,3]
 * 输出：false
 * 解释：没有满足要求的分组。
 * 
 * 
 * 示例 3：
 * 
 * 输入：[1]
 * 输出：false
 * 解释：没有满足要求的分组。
 * 
 * 
 * 示例 4：
 * 
 * 输入：[1,1]
 * 输出：true
 * 解释：可行的分组是 [1,1]
 * 
 * 
 * 示例 5：
 * 
 * 输入：[1,1,2,2,2,2]
 * 输出：true
 * 解释：可行的分组是 [1,1]，[2,2]，[2,2]
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 1 <= deck.length <= 10000
 * 0 <= deck[i] < 10000
 * 
 * 
 * 
 * 
 */
#include "useforme.h"
// @lc code=start
class Solution {
public:
    bool hasGroupsSizeX(vector<int>& deck) {
        vector<int> ans;
        vector<int> num;
        for(int i = 0; i<deck.size(); i++){
            int tag = 0;
            for(int j = 0;j<ans.size()&&tag==0; j++){
                if(deck[i]==ans[j])
                {   
                    num[j]++;
                    tag = 1;
                }
            }
            if(tag == 0){
                ans.push_back(deck[i]);
                num.push_back(1);
            }
        }
        
        int minval = num[0];
        for(int i = 1; i<num.size(); i++){
            minval = min(minval, num[i]);
        }
        if(minval<=1){
            return false;
        }
        for(int n = 2; n<=minval; n++)
        {
            int tag = 1;
            for(int i = 0; i<num.size(); i++){
                if(num[i]%n!=0)
                    tag = 0;
            }
            if(tag != 0)
                return true;
        }
        return false;
    }
};
// @lc code=end

