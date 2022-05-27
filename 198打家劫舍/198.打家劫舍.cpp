/*
 * @Author: FrankTudor
 * @Date: 2022-05-27 16:31:40
 * @LastEditors: FrankTudor
 * @Description: This file is created, edited, contributed by FrankTudor
 * Your runtime beats 100 % of cpp submissions
 * Your memory usage beats 89.9 % of cpp submissions (7.4 MB)
 * @LastEditTime: 2022-05-28 00:13:30
 */
/*
 * @lc app=leetcode.cn id=198 lang=cpp
 *
 * [198] 打家劫舍
 */
#include<iostream>
#include<vector>
using std::vector;
// @lc code=start
class Solution {
public:
    int rob(vector<int>& nums) {
        if(nums.empty()){return 0;}
        if(nums.size() == 1){return nums.at(0);}
        if(nums.size() == 2){return nums.at(0) < nums.at(1) ? nums.at(1) : nums.at(0);}
        size_t i = 2, choice1 = nums.at(0),\
                 choice2 = nums.at(0) < nums.at(1) ? nums.at(1) : nums.at(0), sum = 0;
        int steal_cur;
        while(i < nums.size()){
            steal_cur = choice1 + nums.at(i);
            choice1 = choice2;
            if( steal_cur > choice2){
                choice2 = steal_cur;
            };
            i++;
        }
        return choice2;
    }
};
// @lc code=end

int main(){
    Solution s;
    vector<int> v{2,7,9,3,1};
    std::cout << s.rob(v) << "\n";
    return EXIT_SUCCESS;
}
