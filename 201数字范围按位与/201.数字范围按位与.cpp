/*
 * @Author: FrankTudor
 * @Date: 2022-06-08 18:49:25
 * @LastEditors: FrankTudor
 * @Description: This file is created, edited, contributed by FrankTudor
 * Your runtime beats 93.7 % of cpp submissions
 * Your memory usage beats 52.51 % of cpp submissions (5.8 MB)
 * @LastEditTime: 2022-06-08 22:46:23
 */
/*
 * @lc app=leetcode.cn id=201 lang=cpp
 *
 * [201] 数字范围按位与
 */
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
// @lc code=start
class Solution {
public:
    int binaryGetLength(int num){
        int len = 0;
        while(num != 0){
            num >>= 1;
        }
        return len;
    }
    int rangeBitwiseAnd(int left, int right) {
        int count = 0;
        int left_len = binaryGetLength(left);
        int right_len = binaryGetLength(right);
        if( left_len != right_len){return 0;}
        while(left != right){
            left >>= 1;
            right>>=1;
            count++;
        }
        return right << count;
    }
};
// @lc code=end

