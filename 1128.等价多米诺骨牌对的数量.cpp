/*
 * @lc app=leetcode.cn id=1128 lang=cpp
 *
 * [1128] 等价多米诺骨牌对的数量
 *
 * https://leetcode-cn.com/problems/number-of-equivalent-domino-pairs/description/
 *
 * algorithms
 * Easy (45.60%)
 * Likes:    31
 * Dislikes: 0
 * Total Accepted:    7.4K
 * Total Submissions: 16.1K
 * Testcase Example:  '[[1,2],[2,1],[3,4],[5,6]]'
 *
 * 给你一个由一些多米诺骨牌组成的列表 dominoes。
 * 
 * 如果其中某一张多米诺骨牌可以通过旋转 0 度或 180 度得到另一张多米诺骨牌，我们就认为这两张牌是等价的。
 * 
 * 形式上，dominoes[i] = [a, b] 和 dominoes[j] = [c, d] 等价的前提是 a==c 且 b==d，或是 a==d 且
 * b==c。
 * 
 * 在 0 <= i < j < dominoes.length 的前提下，找出满足 dominoes[i] 和 dominoes[j] 等价的骨牌对
 * (i, j) 的数量。
 * 
 * 
 * 
 * 示例：
 * 
 * 输入：dominoes = [[1,2],[2,1],[3,4],[5,6]]
 * 输出：1
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 1 <= dominoes.length <= 40000
 * 1 <= dominoes[i][j] <= 9
 * 
 * 
 */
#include "useforme.h"
// @lc code=start
class Solution {
public:
    bool comp(vector<int>& i , vector<int>& j){
        return i[0]<j[0]?true:(i[1]<j[1]);
    }
    int getnum(int n ){
        return (n-1)*n/2;
    }
    int numEquivDominoPairs(vector<vector<int>>& dominoes) {
        for(int i=0; i<dominoes.size();i++) {
            auto cur = dominoes[i];
            if(cur[0]>cur[1]){
                swap(dominoes[i][0],dominoes[i][1]);
            }
        }
    //     for(int i=0;i<dominoes.size();i++){
    //     cout<<dominoes[i][0]<<' '<<dominoes[i][1]<<endl;
    // }
        sort(dominoes.begin(), dominoes.end(),
                    [](vector<int>& i , vector<int>& j)
                        {
                            return i[0]<j[0]?true:(i[0]==j[0]?i[1]<j[1]:false);
                        }
        );
    // for(int i=0;i<dominoes.size();i++){
    //     cout<<dominoes[i][0]<<' '<<dominoes[i][1]<<endl;
    // }
        int left = 0;
        int right = 1;
        int ans = 0;
        while(right<dominoes.size()){
            while(right<dominoes.size()&&dominoes[right][0]==dominoes[left][0]&&dominoes[right][1]==dominoes[left][1])
            {
                right++;
            }
            ans += getnum(right-left);
            left = right;
            right++;
        }
        return ans;
    }
};
// @lc code=end

