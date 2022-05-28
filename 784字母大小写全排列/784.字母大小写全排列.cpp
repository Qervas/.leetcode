/*
 * @Author: FrankTudor
 * @Date: 2022-05-28 00:45:08
 * @LastEditors: FrankTudor
 * @Description: This file is created, edited, contributed by FrankTudor
 * Your runtime beats 89.17 % of cpp submissions
 * Your memory usage beats 97.16 % of cpp submissions (9.1 MB)
 * @LastEditTime: 2022-05-28 11:41:34
 */
/*
 * @lc app=leetcode.cn id=784 lang=cpp
 *
 * [784] 字母大小写全排列
 */
#include<iostream>
#include<vector>
#include<math.h>
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
    inline void alphaFlip(char& ch){
        if('a' <= ch && ch <= 'z' ){
            ch -= 32;
        }else{
            ch += 32;
        }
        
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
        size_t&& bit_length = std::move(1 << alphaIndex.size());
        for(size_t i = 0, j, count, cur_bit; i < bit_length;i++){
            string str = s;
            j = i, count = 0, cur_bit = 0;
            while(j != 0){
                cur_bit = j & 1;
                if(cur_bit == 1){
                    alphaFlip(str.at(alphaIndex.at(count)));
                }
                j >>= 1;
                count++;
            }
            ans.push_back(str);
        }
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