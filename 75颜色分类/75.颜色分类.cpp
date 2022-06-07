/*
 * @lc app=leetcode.cn id=75 lang=cpp
 *Your runtime beats 40.61 % of cpp submissions
 * Your memory usage beats 58.51 % of cpp submissions (8 MB)
 * [75] 颜色分类
 */
#include<iostream>
#include<vector>

using namespace std;
// @lc code=start
class Solution {
public:
    void sortColors(vector<int>& nums) {
        int count[3]{0,0,0};
        for(auto& x : nums){
            count[x]++;
        }
        for(int i = 0, k = 0; i < 3; i++){
            for(int j = 0; j < count[i]; j++){
                nums.at(k++) = i;//k < nums.size()
            }
        }
    }
};
// @lc code=end

