/*
 * @Author: FrankTudor
 * @Date: 2022-05-28 00:14:23
 * @LastEditors: FrankTudor
 * @Description: This file is created, edited, contributed by FrankTudor
 * Your runtime beats 93.86 % of cpp submissions
 * Your memory usage beats 82.41 % of cpp submissions (8.3 MB)
 * @LastEditTime: 2022-05-28 00:44:50
 */
/*
 * @lc app=leetcode.cn id=120 lang=cpp
 *
 * [120] 三角形最小路径和
 */
#include<iostream>
#include<vector>
using std::vector;
// @lc code=start
class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        if(triangle.size() == 1){return triangle.at(0).at(0); }
        size_t num_iter = 0;
        int &&layer_iter = triangle.size() - 2;//start from the second layer reversely
        for(; layer_iter > -1; layer_iter--){
            vector<int>& cur_layer = triangle.at(layer_iter);
            vector<int>& next_layer = triangle.at(layer_iter+1);
            for( num_iter = 0; num_iter < cur_layer.size(); num_iter++){
                int& left_num = next_layer.at(num_iter);
                int& right_num = next_layer.at(num_iter+1);
                cur_layer.at(num_iter) += left_num < right_num ? left_num : right_num;
                // printf("%d, ",  cur_layer.at(num_iter));
            }
            // printf("\n");
        }
        return triangle.at(0).at(0);
    }
};
// @lc code=end
int main(void){
    Solution s;
    vector<vector<int>> v{{2},{3,4},{6,5,7},{4,1,8,3}};
    std::cout << s.minimumTotal(v) << "\n";
}
