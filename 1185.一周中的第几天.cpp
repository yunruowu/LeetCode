/*
 * @lc app=leetcode.cn id=1185 lang=cpp
 *
 * [1185] 一周中的第几天
 *
 * https://leetcode-cn.com/problems/day-of-the-week/description/
 *
 * algorithms
 * Easy (60.27%)
 * Likes:    29
 * Dislikes: 0
 * Total Accepted:    7.4K
 * Total Submissions: 12.3K
 * Testcase Example:  '31\n8\n2019'
 *
 * 给你一个日期，请你设计一个算法来判断它是对应一周中的哪一天。
 * 
 * 输入为三个整数：day、month 和 year，分别表示日、月、年。
 * 
 * 您返回的结果必须是这几个值中的一个 {"Sunday", "Monday", "Tuesday", "Wednesday", "Thursday",
 * "Friday", "Saturday"}。
 * 
 * 
 * 
 * 示例 1：
 * 
 * 输入：day = 31, month = 8, year = 2019
 * 输出："Saturday"
 * 
 * 
 * 示例 2：
 * 
 * 输入：day = 18, month = 7, year = 1999
 * 输出："Sunday"
 * 
 * 
 * 示例 3：
 * 
 * 输入：day = 15, month = 8, year = 1993
 * 输出："Sunday"
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 给出的日期一定是在 1971 到 2100 年之间的有效日期。
 * 
 * 
 */
#include "useforme.h"
// @lc code=start
class Solution {
public:
/*
    1582年10月4日后：w = [c/4]-2c+y+[y/4]+[26*(m+1)/10]+d-1) mod 7 ; or w + 7;
    其中w为星期几，星期0为星期日，星期1为星期一，星期-1表示星期六，以此类推，
    所以最后算出来 mod 7的结果如果是负数 需要+7变为非负；
    []表示取整；
    c为[year/100] 即 年份的前两位数;
    y为year%100 即 年份的后两位数；
    m为月数，注意：如果是1、2月需要把它当成上一年的13、14月，例如1997年1月28日应写成1996年13月28日;
    d为day
*/
    string dayOfTheWeek(int day, int month, int year) {
        vector<string> oneWeek{ "Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday" };
        int y = year, m = month;
        if (month == 1 || month == 2)
        {
            --y;
            m += 12;
        }
        int cY = y / 100, yY = y - cY * 100;
        int indexWeek = (cY / 4 - 2 * cY + yY + yY / 4 + 26 * (m + 1) / 10 + day - 1) % 7;
        if (indexWeek < 0)
            indexWeek += 7;
        return oneWeek[indexWeek];
    }
};

// @lc code=end

