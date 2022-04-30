/*
 * @Author: FrankTudor
 * @Date: 2022-04-30 16:26:41
 * @LastEditors: FrankTudor
 * @Description: This file is created, edited, contributed by FrankTudor
 * Your runtime beats 100 % of cpp submissions
 * Your memory usage beats 98.8 % of cpp submissions (5.7 MB)
 * @LastEditTime: 2022-04-30 16:38:00
 */
/*
 * @lc app=leetcode.cn id=278 lang=cpp
 *
 * [278] 第一个错误的版本
 */

// @lc code=start
// The API isBadVersion is defined for you.
// bool isBadVersion(int version);

class Solution {
public:
    int firstBadVersion(int n) {
        size_t lo = 0, hi = n, mi = (lo + hi) >> 1;
        while(lo < hi - 1){
            if(isBadVersion(mi)){
               hi = mi; 
            }else{
                lo = mi;
            }
            mi = (lo + hi) >>1;
        }
        return mi+1;
    }
};
// @lc code=end

