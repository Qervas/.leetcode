/*
 * @Author: FrankTudor
 * @Date: 2022-04-30 16:39:39
 * @LastEditors: FrankTudor
 * @Description: This file is created, edited, contributed by FrankTudor
 * Your runtime beats 100 % of cpp submissions
 * Your memory usage beats 76.92 % of cpp submissions (9.4 MB) 
 * @LastEditTime: 2022-04-30 16:54:06
 */
/*
 * @lc app=leetcode.cn id=35 lang=cpp
 *
 * [35] 搜索插入位置
 */

// @lc code=start
class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int lo = 0, hi = nums.size(), mi = (lo + hi) >> 1;
        while(lo < hi - 1){
            if(nums.at(mi) < target){
                lo = mi;
            }else{
                hi = mi;
            }mi = (lo + hi) >> 1;
        }
        return nums[mi] < target ? mi+1 : mi;
    }
};
// @lc code=end

