/*
 * @Author: FrankTudor
 * @Date: 2022-05-31 14:14:15
 * @LastEditors: FrankTudor
 * @Description: This file is created, edited, contributed by FrankTudor
 * @LastEditTime: 2022-05-31 16:07:13
 */
/*
 * @lc app=leetcode.cn id=42 lang=cpp
 *
 * [42] 接雨水
 */
#include<iostream>
#include<vector>
using std::vector;
// @lc code=start
// #define version1
#define version2
class Solution {
public:
#ifdef version1
    // Your runtime beats 65.79 % of cpp submissions
    // Your memory usage beats 5.02 % of cpp submissions (20.4 MB)
    int trap(vector<int>& height) {
        const int _SIZE = height.size();
        int volume = 0;
        vector<vector<int>> data;
        //data[0]: maxLeftHeight
        //data[1]: maxRightHeight
        int cur_height = height.front();
        vector<int> cur(_SIZE);
        for(size_t i = 0; i < _SIZE; i++){
            cur_height = cur_height < height.at(i) ? height.at(i) : cur_height;
            cur[i] = cur_height;
        }
        data.push_back(cur);
        cur_height = height.back();
        for(int i = _SIZE - 1; i > -1 ;i--){
            cur_height = cur_height < height.at(i) ? height.at(i) : cur_height;
            cur[i] = cur_height;
        }
        data.push_back(cur);
        auto min = [&](const int& a, const int& b){return a < b ? a : b;};
        for(size_t i = 0; i < _SIZE; i++){
            int diff =  min(data[0][i], data[1][i]) - height[i];
            cur[i] = diff;
            if(diff > 0){
                volume += diff;
            }
        }
        return volume;
    }
#endif
#ifdef version2
    // Your runtime beats 99.41 % of cpp submissions
    // Your memory usage beats 7.51 % of cpp submissions (19.2 MB)
    int trap(vector<int>& height) {
        const int _SIZE = height.size();
        int volume = 0;
        int left_iter = 0, right_iter = _SIZE - 1;
        int maxL = height[left_iter], maxR = height[right_iter];
        auto max = [](const int& a, const int& b){return a < b ? b : a;};
        while(left_iter != right_iter){
            if(maxL<= maxR){
                left_iter++;
                maxL = max(maxL, height[left_iter]);
                volume += maxL - height[left_iter];
            }
            if(maxR < maxL){
                right_iter--;
                maxR = max(maxR, height[right_iter]);
                volume += maxR - height[right_iter]; 
            }
        }

        return volume;
    }
#endif
};
// @lc code=end
int main(void){
    Solution s;
    vector<int> v{4,2,0,3,2,5};
    std::cout << s.trap(v) << std::endl;
    return 0;
}
