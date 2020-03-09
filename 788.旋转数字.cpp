/*
 * @Description: 
 * @Version: 2.0
 * @Author: yunruowu
 * @Date: 2020-03-09 10:22:10
 * @LastEditors: yunruowu
 * @LastEditTime: 2020-03-09 11:01:19
 */
/*
 * @lc app=leetcode.cn id=788 lang=cpp
 *
 * [788] 旋转数字
 *
 * https://leetcode-cn.com/problems/rotated-digits/description/
 *
 * algorithms
 * Easy (58.70%)
 * Likes:    56
 * Dislikes: 0
 * Total Accepted:    8.7K
 * Total Submissions: 14.7K
 * Testcase Example:  '10'
 *
 * 我们称一个数 X 为好数, 如果它的每位数字逐个地被旋转 180 度后，我们仍可以得到一个有效的，且和 X 不同的数。要求每位数字都要被旋转。
 * 
 * 如果一个数的每位数字被旋转以后仍然还是一个数字， 则这个数是有效的。0, 1, 和 8 被旋转后仍然是它们自己；2 和 5 可以互相旋转成对方；6 和
 * 9 同理，除了这些以外其他的数字旋转以后都不再是有效的数字。
 * 
 * 现在我们有一个正整数 N, 计算从 1 到 N 中有多少个数 X 是好数？
 * 
 * 
 * 示例:
 * 输入: 10
 * 输出: 4
 * 解释: 
 * 在[1, 10]中有四个好数： 2, 5, 6, 9。
 * 注意 1 和 10 不是好数, 因为他们在旋转之后不变。
 * 
 * 
 * 注意:
 * 
 * 
 * N 的取值范围是 [1, 10000]。
 * 
 * 
 */
#include "useforme.h"
// @lc code=start
class Solution {
public:
    int isGoodNum(int num){
        int temp = num;
        int Reverse = 1;
        int pos = 1;
        while(num!=0){
            // cout<<endl<<num;
            int i = num%10;
            num=num/10;
            switch (i)
            {
            case 2:
                i = 5;
                break;
            case 5:
                i = 2;
                break;
            case 6:
                i = 9;
                break;
            case 9:
                i = 6;
                break;
            case 0:
                break;
            case 1:
                break;
            case 8:
                break;
            default:
                return -1;
                break;
            }
            int a = Reverse % pos;
            pos = 10*pos;
            int b = Reverse / pos;
            Reverse = b*pos+i*pos/10+a;
            
        }
        cout<<Reverse;
        cout<<temp<<endl;
        if(Reverse==temp){
            return -1;
        }
        
        return 1;
    }
    int rotatedDigits(int N) {
        int i = 2;
        int ans = 0;
        for(;i<N+1;i++){
            if(isGoodNum(i)==1){
                ans++;
            }
        }
        return ans;
    }
};
// @lc code=end

int main(int argc, const char** argv) {
    Solution s;
    int i = 100;
    s.rotatedDigits(i);
    return 0;
}
