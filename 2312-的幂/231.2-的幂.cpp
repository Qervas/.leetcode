/*
 * @Author: FrankTudor
 * @Date: 2022-05-26 15:19:15
 * @LastEditors: FrankTudor
 * @Description: This file is created, edited, contributed by FrankTudor
 * Your runtime beats 100 % of cpp submissions
 * Your memory usage beats 63.53 % of cpp submissions (5.8 MB)
 * Explaination: Since the trait of a power of two number, say "n", if n == 2^x,
 * you have x bits binary base number like "10...0", only single "1" at most significant bit(MSB).
 * Therefore, as we minus 1, n-1 == "01...1", only single "0" at MSB. So we do an AND within (n,n-1)
 * Complexity: O(1)
 * @LastEditTime: 2022-05-26 15:31:50
 */
/*
 * @lc app=leetcode.cn id=231 lang=cpp
 *
 * [231] 2 的幂
 */
#include<iostream>
// @lc code=start
class Solution {
public:
    bool isPowerOfTwo(int n) {
        if(n <= 0){return false;}
        if((n & (n-1)) == 0){return true;}
        return false;
    }
};
// @lc code=end
int main(){
    Solution s;
    std::cout << s.isPowerOfTwo(16) << "\n";
}
