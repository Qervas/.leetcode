/*
 * @Author: FrankTudor
 * @Date: 2022-05-26 02:39:25
 * @LastEditors: FrankTudor
 * @Description: This file is created, edited, contributed by FrankTudor
 * Your runtime beats 99.91 % of cpp submissions
 * Your memory usage beats 81.51 % of cpp submissions (17 MB)
 * @LastEditTime: 2022-05-26 12:49:33
 */
/*
 * @lc app=leetcode.cn id=455 lang=cpp
 *
 * [455] 分发饼干
 */
#include<iostream>
#include<vector>
#include<algorithm>
using std::vector;

// @lc code=start
class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        std::sort(g.begin(), g.end());
        std::sort(s.begin(), s.end());
        size_t i_s, i_g;
        int count = 0;
        for(i_s = 0, i_g = 0; i_s < s.size() && i_g < g.size(); i_s++){
            if(s[i_s] >= g[i_g]){
                count++;
                i_g++;
            }
        }
        return count;
    }
};
// @lc code=end q

int main(void){
    Solution s;
    std::vector<int> v_g = {1,2,3};
    vector<int>  v_s = {1,1};
    std::cout << s.findContentChildren(v_g,v_s) <<"\n";
    return 0;
}