/*
 * @Author: FrankTudor
 * @Date: 2022-05-26 18:02:07
 * @LastEditors: FrankTudor
 * @Description: This file is created, edited, contributed by FrankTudor
 * Your runtime beats 100 % of cpp submissions
 * Your memory usage beats 79.66 % of cpp submissions (5.8 MB)
 * stairs[i] = stairs[i-2] + stairs[i-1];
 * current stair = 1-case jump + 2-case jump
 * 
 * @LastEditTime: 2022-05-27 16:29:05
 */
/*
 * @lc app=leetcode.cn id=70 lang=cpp
 *
 * [70] 爬楼梯
 */
#include<vector>
using std::vector;
// @lc code=start
class Solution {
public:
    int climbStairs(int n) {
        if(n <= 0){return 0;}
        else if(n == 1){return 1;}
        else if(n == 2){return 2;}
        int cur_left = 2, cur_left_left = 1, cur = 0;
        for(int i = 2; i < n; i++){
            cur = cur_left + cur_left_left;
            cur_left_left = cur_left;
            cur_left = cur;

        }
        return cur;
    }
};
// @lc code=end
int main(void){

    Solution s;
    s.climbStairs(3);
    return EXIT_SUCCESS;
}

