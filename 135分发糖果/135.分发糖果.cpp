/*
 * @Author: FrankTudor
 * @Date: 2022-05-26 13:24:33
 * @LastEditors: FrankTudor
 * @Description: This file is created, edited, contributed by FrankTudor
 * Your runtime beats 47.29 % of cpp submissions
 * Your memory usage beats 45.04 % of cpp submissions (17.3 MB)
 * @LastEditTime: 2022-05-26 14:49:10
 */
/*
 * @lc app=leetcode.cn id=135 lang=cpp
 *
 * [135] 分发糖果
 */
#include<iostream>
#include<vector>
using std::vector;
// @lc code=start
class Solution {
public:
    int candy(vector<int>& ratings) {
        size_t size = ratings.size();
        vector<int> each(size);
        for(auto& x:each){x = 1;}
        for(size_t i = 1; i < size; i++){
            if(ratings.at(i-1) < ratings.at(i) ){
                each.at(i) = each.at(i-1) + 1;
            }
        }
        for(int i = size-1; i > 0; i--){
            if(ratings.at(i-1) > ratings.at(i) && each.at(i-1) <= each.at(i) ){
                each.at(i-1) = each.at(i) + 1;
            }
        }
        int count = 0;
        for(auto& x:each){
            count += x;
        }
        return count; 
    }
};
// @lc code=end
int main(void){
    vector<int> v{1,3,4,5,2};
    Solution s;
    std::cout << s.candy(v) << "\n";
    return 0;
}
