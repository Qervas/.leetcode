/*
 * @Author: FrankTudor
 * @Date: 2022-04-26 23:04:06
 * @LastEditors: FrankTudor
 * @Description: This file is created, edited, contributed by FrankTudor
 * @LastEditTime: 2022-04-27 00:47:50
 */
/*
 * @lc app=leetcode.cn id=15 lang=cpp
 *
 * [15] 三数之和
 */

// @lc code=start
#include<algorithm>
#include<vector>
#include<iostream>
#include<iterator>
#include<iomanip>
using namespace std;
class Solution {
public:
// Your runtime beats 97.84 % of cpp submissions
// Your memory usage beats 41.55 % of cpp submissions (19.5 MB)
    bool isDuplicate(const vector<vector<int>>& nums, const int& x,const int& y,const int& z){
        if(nums.empty()){return false;}
        size_t index = nums.size() - 1;
        if(nums[index][0] == x && nums[index][1] == y && nums[index][2] ==z){
           return true;
        }
        return false;
    }

    vector<vector<int>> threeSum(vector<int>& nums) {
        size_t size = nums.size();
        if(size < 3){return {};}
        vector<vector<int>> answer;
        
        sort(nums.begin(), nums.end(), [](const int& lhs, const int& rhs){return lhs < rhs;});
        if(nums.at(0) > 0 || nums.at(nums.size()-1) < 0){return {};}
        int outcome,sum;
        for(int i = 0,j,k; i < size-2; i++){
            if(i > 0&&nums[i]==nums[i-1]){continue;}
            outcome = -nums.at(i);
            for(j = i+1, k = size-1;j < k;){
                sum = nums[j] + nums[k];
                if(sum < outcome){
                    j++;
                }
                else if(sum > outcome){
                    k--;
                }
                else{//sum == outcome
                    if(!isDuplicate(answer,nums[i],nums[j],nums[k])){
                       answer.push_back({nums[i],nums[j],nums[k]});
                    }
                    j++;
                    k--;
                }
            }
        }

        return answer;
        
    }
};
// @lc code=end
// int main(){
//     Solution s;
//     vector<int> seq{0,0,0};
//     auto answer = s.threeSum(seq);
//     for(auto& x:answer){
//         for(auto & y:x){
//             cout << y << ", ";
//         }
//         cout << endl;
//     }
//     return 0;
// }
