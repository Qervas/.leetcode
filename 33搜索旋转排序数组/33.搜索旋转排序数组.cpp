/*
 * @Author: FrankTudor
 * @Date: 2022-05-31 13:00:41
 * @LastEditors: FrankTudor
 * @Description: This file is created, edited, contributed by FrankTudor

 * @LastEditTime: 2022-05-31 14:05:06
 */
/*
 * @lc app=leetcode.cn id=33 lang=cpp
 *
 * [33] 搜索旋转排序数组
 */
#include<vector>
#include<iostream>
using std::vector;
// @lc code=start
// #define version1
#define version2
class Solution {
public:
#ifdef version1
    /*
    * Your runtime beats 100 % of cpp submissions
    * Your memory usage beats 77.51 % of cpp submissions (10.7 MB)
    */
     int findIndex(vector<int>& nums, int lo, int hi, const int& target){
        if(lo >= hi - 1){if(nums.at(lo) == target){return lo;}return -1;}
        int mi = (lo + hi) >> 1, index;
        if(nums.at(mi) == target){
            return mi;
        }
        index = findIndex(nums, lo, mi, target);
        if( index != -1 && nums.at(index) == target ){
            return index;
        }
        index = findIndex(nums, mi, hi, target);
        if( index != -1 && nums.at(index) == target ){
            return index;
        }
        return -1;
    }
#endif
#ifdef version2
    /*
    * Your runtime beats 69.08 % of cpp submissions
    * Your memory usage beats 81.34 % of cpp submissions (10.7 MB)
    */
    bool isSorted(vector<int>& nums,const int& lo,const int& hi){
        return (nums.at(hi-1) - nums.at(lo)) == (hi - lo);
    }
    int binarySearch(vector<int>&nums, int lo, int hi, const int& target){
        if(lo >= hi - 1){if(nums.at(lo) == target){return lo;}return -1;}
        int mi =  (lo + hi) >> 1;
        if(nums.at(mi) <= target ){
            return binarySearch(nums, mi, hi, target);
        }else{
            return binarySearch(nums, lo, mi, target);
        }
    }
    int findIndex(vector<int>& nums, int lo, int hi, const int& target){
        if(lo >= hi - 1){if(nums.at(lo) == target){return lo;}return -1;}
        int mi = (lo + hi) >> 1, index;
        if(nums.at(mi) == target){
            return mi;
        }
        if(isSorted(nums, lo, mi)){
            index = binarySearch(nums, lo, mi, target);
        }else{
            index = findIndex(nums, lo, mi, target);
        }
        if( index != -1 && nums.at(index) == target ){
            return index;
        }
        if(isSorted(nums, mi, hi)){
            index = binarySearch(nums, mi, hi, target);
        }else{
            index = findIndex(nums, mi, hi, target);
        }
        if( index != -1 && nums.at(index) == target ){
            return index;
        }
        return -1;
    }
#endif
    int search(vector<int>& nums, int target) {
        if(nums.empty()){return -1;}
        int lo = 0, hi = nums.size(), mi = (lo + hi) >> 1;
        return findIndex(nums, lo, hi, target);
    }

};
// @lc code=end
int main(){
    Solution s;
    vector<int> v{7,8,9,0,1,3,4,5};
    std::cout << s.search(v,4);
    return EXIT_SUCCESS;
}
