/*
 * @Author: FrankTudor
 * @Date: 2022-04-30 15:52:40
 * @LastEditors: FrankTudor
 * @Description: This file is created, edited, contributed by FrankTudor
 * Your runtime beats 79.35 % of cpp submissions
 * Your memory usage beats 98.93 % of cpp submissions (26.7 MB)
 * @LastEditTime: 2022-04-30 16:20:05
 */
/*
 * @lc app=leetcode.cn id=704 lang=cpp
 *
 * [704] 二分查找
 */

// @lc code=start
#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:

    int search(vector<int>& nums, int target) {//[lo, hi)
        // if(nums.size() <= 1){return 0;}
        if(target < nums.at(0) || target > nums.at(nums.size()-1)){return -1;}
        int hi = nums.size();
        int lo = 0, mi = (lo + hi)>>1;
        while(lo < hi-1){
            if(nums.at(mi) > target){
                hi = mi;
            }
            else{
                lo = mi;
            }
            mi = (lo + hi) >> 1;
        }
        // return mi;//return an index which's not greater than the target value
        return nums[mi] == target ? mi : -1;
    }
};
// @lc code=end

int main(void){
    vector<int> vec{-1,0,3,5,9,12};
    Solution s;
    s.search(vec,2);
    return 0;
}