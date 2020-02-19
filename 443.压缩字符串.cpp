/*
 * @Description: 
 * @Version: 2.0
 * @Author: yunruowu
 * @Date: 2020-02-17 22:08:23
 * @LastEditors: yunruowu
 * @LastEditTime: 2020-02-18 10:40:16
 */
/*
 * @lc app=leetcode.cn id=443 lang=cpp
 *
 * [443] 压缩字符串
 *
 * https://leetcode-cn.com/problems/string-compression/description/
 *
 * algorithms
 * Easy (38.93%)
 * Likes:    92
 * Dislikes: 0
 * Total Accepted:    11.7K
 * Total Submissions: 29.9K
 * Testcase Example:  '["a","a","b","b","c","c","c"]'
 *
 * 给定一组字符，使用原地算法将其压缩。
 * 
 * 压缩后的长度必须始终小于或等于原数组长度。
 * 
 * 数组的每个元素应该是长度为1 的字符（不是 int 整数类型）。
 * 
 * 在完成原地修改输入数组后，返回数组的新长度。
 * 
 * 
 * 
 * 进阶：
 * 你能否仅使用O(1) 空间解决问题？
 * 
 * 
 * 
 * 示例 1：
 * 
 * 
 * 输入：
 * ["a","a","b","b","c","c","c"]
 * 
 * 输出：
 * 返回6，输入数组的前6个字符应该是：["a","2","b","2","c","3"]
 * 
 * 说明：
 * "aa"被"a2"替代。"bb"被"b2"替代。"ccc"被"c3"替代。
 * 
 * 
 * 示例 2：
 * 
 * 
 * 输入：
 * ["a"]
 * 
 * 输出：
 * 返回1，输入数组的前1个字符应该是：["a"]
 * 
 * 说明：
 * 没有任何字符串被替代。
 * 
 * 
 * 示例 3：
 * 
 * 
 * 输入：
 * ["a","b","b","b","b","b","b","b","b","b","b","b","b"]
 * 
 * 输出：
 * 返回4，输入数组的前4个字符应该是：["a","b","1","2"]。
 * 
 * 说明：
 * 由于字符"a"不重复，所以不会被压缩。"bbbbbbbbbbbb"被“b12”替代。
 * 注意每个数字在数组中都有它自己的位置。
 * 
 * 
 * 注意：
 * 
 * 
 * 所有字符都有一个ASCII值在[35, 126]区间内。
 * 1 <= len(chars) <= 1000。
 * 
 * 
 */
#include "useforme.h"
// @lc code=start
class Solution {
public:
    int getIntLen(int n){
        int len = 0;
        if(n==0)
            return 0;
        while(n>=10){
            n = n/10;
            len++;
        }
        return len+1;
    }
    void Prinetvec(vector<char> nums){
    for(int i = 0 ;i< nums.size();i++){
        cout<<nums[i]<<" ";
    }
    cout<<endl;
    };
    int compress(vector<char>& chars) {
        int i = 1;
        // int chars.size() = chars.size();
        int ans = 1;
        char temp = chars[0];
        while (i<chars.size())
        {
            // return 0;
            int sum = 1;
            // cout<<temp<<endl;
            // cout<<chars[i]<<"   "<<temp<<endl;
            // cout<<"     "<<i<<"   "<<chars.size()<<endl;
            while(chars[i] == temp && i<chars.size()){
                sum++;
                // cout<<chars[i]<<"   "<<temp<<endl;
                temp = chars[i];
                chars.erase(chars.begin()+i);
                // chars.size()=chars.size();
                
                // i++;
            }
            if(sum==1&&i<chars.size()){
                temp = chars[i];
                i++;
                // cout<<chars[i]<<"   "<<temp<<endl;
                // cout<<"     "<<i<<"   "<<chars.size()<<endl;
                
                // chars.insert(chars.begin()+i-1,sum+'0');
                // ans++;
                // i++;
                // chars.size()++;
            }else{
                
                while(sum>=10){
                    int mod = sum%10;
                    chars.insert(chars.begin()+i,mod+'0');
                    sum = sum/10;
                    ans++;
                }
                chars.insert(chars.begin()+i,sum+'0');
                // cout<<sum;
                // ans++;
                // chars.size() += getIntchars.size()(sum);
                // cout<<getIntchars.size()(sum)<<endl;
                    // temp = chars[i-getIntchars.size()(sum)];
                // cout<<chars[i-getIntchars.size()(sum)]<<endl;
                i+=getIntLen(sum);
                // i++;
            }
            // cout<<i<<"       "<<len;
        }
        // Prinetvec(chars);   
        return chars.size(); 
        
    }
};
// @lc code=end

int main(int argc, char const *argv[])
{
    Solution s;
    cout<<endl<<s.getIntLen(12)<<endl<<s.getIntLen(2)<<endl<<s.getIntLen(102)<<endl<<s.getIntLen(0);
    return 0;
}
