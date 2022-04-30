/*
 * @Author: FrankTudor
 * @Date: 2022-04-30 16:57:55
 * @LastEditors: FrankTudor
 * @Description: This file is created, edited, contributed by FrankTudor
 * Your runtime beats 98.75 % of cpp submissions
 * Your memory usage beats 77.52 % of cpp submissions (25.2 MB)
 * @LastEditTime: 2022-04-30 17:51:39
 */
/*
 * @lc app=leetcode.cn id=977 lang=cpp
 *
 * [977] 有序数组的平方
 */

// @lc code=start
class Solution {
public:
    void square(int& num){num *= num;}
    void swap(int& a, int& b){a^=b; b^=a; a^=b;}
    int findNegIdx(const vector<int>& nums){
        int lo = 0, hi = nums.size(), mi = (lo + hi) >> 1, target = 0;
        while(lo < hi -1){
            if(nums.at(mi) > target){
                hi = mi;
            }else{
                lo = mi;
            }mi = (lo + hi) >> 1;
        }
        return nums.at(mi) < 0 ? mi : mi - 1;
    }

    vector<int> sortedSquares(vector<int>& nums) {
        if(nums.size() == 1){square(nums.at(0));return nums;}
        int negBegin = findNegIdx(nums), nonNegBegin = negBegin+1;//[begin, end)
        vector<int> answer;
        answer.reserve(nums.size());
        for(size_t i = 0; i < nums.size(); i++){
            square(nums.at(i));
        }
        while(negBegin > -1 && nonNegBegin < nums.size()){
            if(nums.at(negBegin) <= nums.at(nonNegBegin)){
                answer.push_back(nums.at(negBegin--));
            }else{
                answer.push_back(nums.at(nonNegBegin++));
            }
        }
        while(negBegin > -1){
            answer.push_back(nums.at(negBegin--));
        }
        while(nonNegBegin < nums.size()){
            answer.push_back(nums.at(nonNegBegin++));
        }      
        return answer;

        
    }
};
// @lc code=end

