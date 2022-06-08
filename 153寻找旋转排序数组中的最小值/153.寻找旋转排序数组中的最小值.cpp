/*
 * @Author: FrankTudor
 * @Date: 2022-06-08 17:43:36
 * @LastEditors: FrankTudor
 *Your runtime beats 100 % of cpp submissions
 * Your memory usage beats 23.7 % of cpp submissions (10 MB) * @Description: This file is created, edited, contributed by FrankTudor
 * @LastEditTime: 2022-06-08 18:18:17
 */
/*
 * @lc app=leetcode.cn id=153 lang=cpp

 * [153] 寻找旋转排序数组中的最小值
 */
#include<iostream>
#include<vector>
using namespace std;
// @lc code=start
class Solution {
public:
    int binarySearch(vector<int>& nums, int lo, int hi){
        if(lo >= hi - 1){return nums[lo+1];}
        int mi = (lo + hi) >> 1;
        if(nums[lo] < nums[mi]){
            return binarySearch(nums, mi, hi);
        }
        return binarySearch(nums, lo, mi);
    }
    int findMin(vector<int>& nums) {
        if(nums.size() == 1){return nums.front();}
        if(nums.front() < nums.back()){
            return nums.front();
        }
        return binarySearch(nums, 0, nums.size());
    }
};
// @lc code=end

