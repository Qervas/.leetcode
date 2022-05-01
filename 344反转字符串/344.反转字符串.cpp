/*
 * @Author: FrankTudor
 * @Date: 2022-05-01 23:32:42
 * @LastEditors: FrankTudor
 * @Description: This file is created, edited, contributed by FrankTudor
 * Your runtime beats 94.29 % of cpp submissions
 * Your memory usage beats 29.97 % of cpp submissions (22.6 MB)
 * @LastEditTime: 2022-05-01 23:35:40
 */
/*
 * @lc app=leetcode.cn id=344 lang=cpp
 *
 * [344] 反转字符串
 */

// @lc code=start
class Solution {
public:
    void reverseString(vector<char>& s) {
        size_t length = s.size();
        for(size_t i=0; i < length/2; i++){
            swap(s[i],s[length-i-1]);
        }
    }
};
// @lc code=end

