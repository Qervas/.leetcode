/*
 * @Author: FrankTudor
 * @Date: 2022-06-08 18:20:15
 * @LastEditors: FrankTudor
 * @Description: This file is created, edited, contributed by FrankTudor
 * Spoil Alert: You only need to return one of the peak values.
 * Not all of them as a list.
 * @LastEditTime: 2022-06-08 18:45:53
 */
/*
 * @lc app=leetcode.cn id=162 lang=cpp
 *
 * [162] 寻找峰值
 */
#include<iostream>
#include<vector>
using namespace std;
// @lc code=start
class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int left = 0, right = nums.size() - 1;
        while(left < right){
            int mid = left + ((right - left) >> 1);
            if(nums[mid] < nums[mid + 1]){
                left = mid + 1;
            }else{
                right = mid;
            }
        }
        return left;
    }
};
// @lc code=end

