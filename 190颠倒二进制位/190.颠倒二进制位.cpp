/*
 * @Author: FrankTudor
 * @Date: 2022-05-26 15:39:42
 * @LastEditors: FrankTudor
 * @Description: This file is created, edited, contributed by FrankTudor
 * Your runtime beats 100 % of cpp submissions
 * Your memory usage beats 85.26 % of cpp submissions (5.8 MB)
 * @LastEditTime: 2022-05-26 16:27:53
 */
/*
 * @lc app=leetcode.cn id=190 lang=cpp
 *
 * [190] 颠倒二进制位
 */
#include<iostream>
// @lc code=start
class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        const uint32_t magic_number = 0b1;
        uint32_t ans = 0;//least significant bit
        int i = 0;
        while(1){
            ans |= (n&magic_number);
            if(i == 31){break;}
            ans <<= 1;
            n >>= 1;
            i++;
        }
        return ans;
    }
};
// @lc code=end
