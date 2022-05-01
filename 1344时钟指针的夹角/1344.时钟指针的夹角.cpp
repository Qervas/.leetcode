/*
 * @Author: FrankTudor
 * @Date: 2022-05-01 23:08:13
 * @LastEditors: FrankTudor
 * @Description: This file is created, edited, contributed by FrankTudor
 * @LastEditTime: 2022-05-01 23:31:12
 */
/*
 * @lc app=leetcode.cn id=1344 lang=cpp
 *
 * [1344] 时钟指针的夹角
 */
// @lc code=start
class Solution {
public:
    double angleClock(int hour, int minutes) {
        int oneMinAngle = 6;
        int oneHourAngle = 30;

        double minutesAngle = oneMinAngle * minutes;
        double hourAngle = (hour % 12 + minutes / 60.0) * oneHourAngle;
        
        double diff = abs(hourAngle - minutesAngle);
        return min(diff, 360 - diff);


    }
};
// @lc code=end

