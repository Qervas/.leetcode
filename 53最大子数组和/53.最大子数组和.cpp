/*
 * @Author: FrankTudor
 * @Date: 2022-05-02 13:33:53
 * @LastEditors: FrankTudor
 * @Description: This file is created, edited, contributed by FrankTudor
 * Your runtime beats 70.96 % of cpp submissions
 * Your memory usage beats 37.94 % of cpp submissions (66.2 MB)
 * @LastEditTime: 2022-05-02 22:53:33
 */
/*
 * @lc app=leetcode.cn id=53 lang=cpp
 *
 * [53] 最大子数组和
 */
#include<iostream>
#include<vector>
using namespace std;
// @lc code=start
class Solution {
public:


    int maxSubArray(vector<int>& nums){
        int max = nums[0];
        for(size_t i = 1; i < nums.size(); i++){
            nums[i] = nums[i-1] > 0 ? nums[i] + nums[i-1] : nums[i];
            max = max < nums[i] ? nums[i] : max;
        }
        return max;
    }
};
// @lc code=end
int main(void){
    Solution s;    
    vector<int> nums{2,-1,1,1};
    cout << s.maxSubArray(nums) << endl;
    return 0;
}

