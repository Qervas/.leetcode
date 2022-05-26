/*
 * @lc app=leetcode.cn id=46 lang=cpp
 * Your runtime beats 100 % of cpp submissions
 * Your memory usage beats 73.18 % of cpp submissions (7.5 MB)
 * [46] 全排列
 */
#include<iostream>
#include<vector>
using std::vector;
// @lc code=start
class Solution {
public:
    void backtrack(vector<int>& nums, vector<vector<int>>& ans, int level){
        if(level == nums.size() - 1){
            ans.push_back(nums);
            return ;
        }
        for(int i = level; i < nums.size(); i++){
            std::swap(nums[i], nums[level]);
            backtrack(nums, ans, level+1);
            std::swap(nums[i], nums[level]);
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> ans;
        backtrack(nums, ans, 0);
        return ans;
    }
};
// @lc code=end

int main(void){
    vector<int> v{1,2,3};
    Solution s;
    s.permute(v);
    return EXIT_SUCCESS;
}