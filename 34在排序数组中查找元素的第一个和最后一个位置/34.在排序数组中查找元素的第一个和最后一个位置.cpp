/*
 * @Author: FrankTudor
 * @Date: 2022-05-30 13:11:13
 * @LastEditors: FrankTudor
 * @Description: This file is created, edited, contributed by FrankTudor
 * Your runtime beats 100 % of cpp submissions
 * Your memory usage beats 99.24 % of cpp submissions (13.1 MB)
 * @LastEditTime: 2022-05-30 16:12:10
 */
/*
 * @lc app=leetcode.cn id=34 lang=cpp
 *
 * [34] 在排序数组中查找元素的第一个和最后一个位置
 */
#include<vector>
using std::vector;
// @lc code=start
class Solution {
public:
    int binarySearch(vector<int> &nums, int lo, int hi, const int& target ){
        if(lo >= hi - 1){return lo;}
        int mi = (lo + hi) >> 1;
        if( nums.at(mi) <= target){
            return binarySearch(nums, mi, hi, target);
        }else{
            return binarySearch(nums, lo, mi, target);
        }
    }
    vector<int> searchRange(vector<int>& nums, int target) {
        if(nums.empty()){return {-1,-1};}
        int lo = 0, hi = nums.size(), mi = (lo + hi ) >> 1;
        int right = binarySearch(nums, lo, hi, target);
        if(nums.at(right) != target){return {-1,-1};}
        int i = right;
        for(; i > -1 && nums.at(i) == target; i--);

        // printf("[%d, %d]\n",  i+1, right);
        return {i+1,right};
    }
};
// @lc code=end
int main(void){
    Solution s;
    vector<int> v{5,7,7,8,8,8,10};
    s.searchRange(v,9);
    return EXIT_SUCCESS;
}