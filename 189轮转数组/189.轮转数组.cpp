/*
 * @Author: FrankTudor
 * @Date: 2022-04-30 17:52:10
 * @LastEditors: FrankTudor
 * @Description: This file is created, edited, contributed by FrankTudor
 * Your runtime beats 91.59 % of cpp submissions
 * Your memory usage beats 39.76 % of cpp submissions (24.8 MB)
 * @LastEditTime: 2022-04-30 18:44:00
 */
/*
 * @lc app=leetcode.cn id=189 lang=cpp
 *
 * [189] 轮转数组
 */
// #include<iostream>
import std.core;
#include<vector>
using namespace std;
// @lc code=start

class Solution {
    size_t mod(int a, int b){
        if(a > 0){return a%b;}
        while(a < 0){
            a += b;
        }
        return a%b;
    }
public:
    void swap(int& a, int& b){a^=b;b^=a;a^=b;}

    void rotate(vector<int>& nums, int k) {
        if(nums.size() == 1 || k == 0){return ;}
        int *swap_pool = new int[k];
        for(int i = 0; i < k; i++){
            swap_pool[i] = nums.at(mod(i-k,nums.size()));
        }
        for(int i = 0; i < nums.size(); i++){
            swap(swap_pool[mod(i,k)], nums.at(i));
        }
        delete[] swap_pool;
    }
};

// @lc code=end
int main(){
    Solution s;
    vector<int> vec{1,2,3,4,5,6,7};
    s.rotate(vec,3);
    return 0;
}
