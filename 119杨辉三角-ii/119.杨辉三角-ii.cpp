/*
 * @Author: FrankTudor
 * @Date: 2022-06-09 17:56:26
 * @LastEditors: FrankTudor
 * @Description: This file is created, edited, contributed by FrankTudor
 * Your runtime beats 100 % of cpp submissions
 * Your memory usage beats 90.65 % of cpp submissions (6.1 MB)
 * @LastEditTime: 2022-06-09 18:46:11
 */
/*
 * @lc app=leetcode.cn id=119 lang=cpp
 *
 * [119] 杨辉三角 II
 */
#include<iostream>
#include<vector>
using std::vector;
// @lc code=start
class Solution {
public:

    vector<int> getRow(int rowIndex) {
        vector<int> ans(rowIndex+1);
        ans.front() = ans.back() = 1;
        int mid = (ans.size() >> 1) + 1;
        for(int i = 1, j = ans.size() - 2; i < mid; i++, j--){
            ans[i] =  1LL * ans[i - 1] * (rowIndex - i + 1) / i;
            ans[j] = ans[i];
        }
        return ans;
    }
};
// @lc code=end

