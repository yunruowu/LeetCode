'''
@Description: 
@Version: 2.0
@Author: yunruowu
@Date: 2020-01-02 08:47:49
@LastEditors  : yunruowu
@LastEditTime : 2020-01-10 21:48:39
'''
#
# @lc app=leetcode.cn id=58 lang=python3
#
# [58] 最后一个单词的长度
#
# https://leetcode-cn.com/problems/length-of-last-word/description/
#
# algorithms
# Easy (31.89%)
# Likes:    158
# Dislikes: 0
# Total Accepted:    59.2K
# Total Submissions: 185.5K
# Testcase Example:  '"Hello World"'
#
# 给定一个仅包含大小写字母和空格 ' ' 的字符串，返回其最后一个单词的长度。
# 
# 如果不存在最后一个单词，请返回 0 。
# 
# 说明：一个单词是指由字母组成，但不包含任何空格的字符串。
# 
# 示例:
# 
# 输入: "Hello World"
# 输出: 5
# 
# 
#

# @lc code=start
class Solution:
    def lengthOfLastWord(self, s: str) -> int:
        i = 0
        j = 0
        while i<len(s):
            print(i)
            if s[i-1]==' ' and s[i]!=' ':
                j=0
            if s[i]!=' ':
                i = i + 1
                j = j + 1
            else:
                i = i+ 1
        return j;
        
# @lc code=end
