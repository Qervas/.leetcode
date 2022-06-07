/*
 * @lc app=leetcode.cn id=169 lang=cpp
 *
 * [169] 多数元素
 */
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
// @lc code=start
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        return nums.at(nums.size() >> 1);
    }
};
// @lc code=end

