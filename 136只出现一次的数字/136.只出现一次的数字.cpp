/*
 * @Author: FrankTudor
 * @Date: 2022-05-26 16:39:42
 * @LastEditors: FrankTudor
 * @Description: This file is created, edited, contributed by FrankTudor
 * Your runtime beats 88.65 % of cpp submissions
 * Your memory usage beats 30.09 % of cpp submissions (16.5 MB)
 * @LastEditTime: 2022-05-26 16:48:51
 */
/*
 * @lc app=leetcode.cn id=136 lang=cpp
 *
 * [136] 只出现一次的数字
 */
#include<vector>
using std::vector;
// @lc code=start
class Solution {
public:
    int singleNumber(vector<int>& nums) {

        int ans = nums[0];
        for(size_t i = 1; i < nums.size(); i++){
            ans ^= nums[i];
        }
        return ans;

    }
};
// @lc code=end

