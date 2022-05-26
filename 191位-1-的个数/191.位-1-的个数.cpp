/*
 * @Author: FrankTudor
 * @Date: 2022-05-26 15:33:11
 * @LastEditors: FrankTudor
 * @Description: This file is created, edited, contributed by FrankTudor
 * Your runtime beats 100 % of cpp submissions
 * Your memory usage beats 79.57 % of cpp submissions (5.8 MB)
 * @LastEditTime: 2022-05-26 15:38:38
 */
/*
 * @lc app=leetcode.cn id=191 lang=cpp
 *
 * [191] 位1的个数
 */
#include<iostream>
// @lc code=start
class Solution {
public:
    int hammingWeight(uint32_t n) {
        int count = 0;
        uint32_t magic_number = 1;
        while(n != 0){
            if((n & magic_number) == magic_number){count++;}
            n>>=1;
        }
        return count;
    }
};
// @lc code=end

