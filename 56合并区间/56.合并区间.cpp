/*
 * @lc app=leetcode.cn id=56 lang=cpp
 * Your runtime beats 78.02 % of cpp submissions
 * Your memory usage beats 71.53 % of cpp submissions (18.5 MB)
 * [56] 合并区间
 */
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
// @lc code=start
class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        if(intervals.size() < 2){return intervals;}
        vector<vector<int>> ans;
        sort(intervals.begin(), intervals.end(),
                        [](const vector<int>&a, const vector<int>&b){
                            return a[0] < b[0];});
        for(int i = 0; i < intervals.size(); ){
            int rmax = intervals[i][1], rvalue = rmax;
            int j = i;
            while(j < intervals.size() && rmax >= intervals[j][0]){
                rmax = max(rmax, intervals[j][1]);
                j++;
            }
            ans.push_back({intervals[i][0], rmax});
            i = j;
        }
        return ans;
    }
};
// @lc code=end

