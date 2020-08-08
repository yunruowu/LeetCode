/*
 * @lc app=leetcode.cn id=96 lang=cpp
 *
 * [96] 不同的二叉搜索树
 *
 * https://leetcode-cn.com/problems/unique-binary-search-trees/description/
 *
 * algorithms
 * Medium (65.19%)
 * Likes:    561
 * Dislikes: 0
 * Total Accepted:    48K
 * Total Submissions: 73K
 * Testcase Example:  '3'
 *
 * 给定一个整数 n，求以 1 ... n 为节点组成的二叉搜索树有多少种？
 * 
 * 示例:
 * 
 * 输入: 3
 * 输出: 5
 * 解释:
 * 给定 n = 3, 一共有 5 种不同结构的二叉搜索树:
 * 
 * ⁠  1         3     3      2      1
 * ⁠   \       /     /      / \      \
 * ⁠    3     2     1      1   3      2
 * ⁠   /     /       \                 \
 * ⁠  2     1         2                 3
 * 
 */
#include "useforme.h"
// @lc code=start
class Solution {
public:
    int numTrees(int n) {
        vector<int> dp(n+1, 0);
        dp[0]=1;
        dp[1]=1;
        int i = 2;
        while(i<n+1){
            int sum = 0;
            for(int j = 0; j<i;j++){
                sum+=dp[j]*dp[i-1-j];
            }
            dp[i]=sum;
            i++;
        }
        return dp[n];
    }
};
// @lc code=end

int main(int argc, char const *argv[])
{
    
    Solution s;
    cout<<s.numTrees(3);
    return 0;
}
