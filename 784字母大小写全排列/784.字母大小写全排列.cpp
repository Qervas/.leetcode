/*
 * @Author: FrankTudor
 * @Date: 2022-05-28 00:45:08
 * @LastEditors: FrankTudor
 * @Description: This file is created, edited, contributed by FrankTudor
 * @LastEditTime: 2022-05-28 01:12:33
 */
/*
 * @lc app=leetcode.cn id=784 lang=cpp
 *
 * [784] 字母大小写全排列
 */
#include<iostream>
#include<vector>
#include<string>
using std::string;
using std::vector;
// @lc code=start
class Solution {
public:
    inline bool isAlpha(const char& ch){
        if(('a' <= ch && ch <= 'z' )|| ('A' <= ch && ch <= 'Z')){
            return true;
        }
        return false;
    }
    vector<string> letterCasePermutation(string s) {
        vector<int> alphaIndex;
        for(size_t i = 0; i < s.size(); i++){
            bool flag = isAlpha(const_cast<char&>(s.at(i)));
            if(flag){
                alphaIndex.push_back(i);
            }
        }
        vector<string> ans;

        return ans;
    }
};
// @lc code=end

int main(){
    Solution s;
    string str = "a1b2";
    s.letterCasePermutation(str);
    return EXIT_SUCCESS;
}