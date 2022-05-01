/*
 * @Author: FrankTudor
 * @Date: 2022-05-01 23:36:34
 * @LastEditors: FrankTudor
 * @Description: This file is created, edited, contributed by FrankTudor
 * @LastEditTime: 2022-05-01 23:58:04
 */
/*
 * @lc app=leetcode.cn id=557 lang=cpp
 *
 * [557] 反转字符串中的单词 III
 */
#include<iostream>
#include<string>
using namespace std;
// @lc code=start
class Solution {
public:
    void reverseString(string& s, int lo, int hi){//[lo, hi)
        char tmp;
        for(int length = hi - lo, i = lo; i < lo + length/2; i++){
            tmp = s[i];
            s[i] = s[hi-i+lo-1];
            s[hi-i+lo-1] = tmp;
        }
    }
    string reverseWords(string s) {
       for(int lo=0,hi=0; lo < s.size();){
           if(s[lo] != ' '){
               hi = lo+1;
               while(s[hi] != ' ' && hi < s.size() ){
                   hi++;
               }//hi is at a blank or end of string
               reverseString(s, lo, hi);
               lo = hi+1;
           }
       }
       return s;

    }
};
// @lc code=end

int main(){
    Solution s;
    s.reverseWords("Frank is");
}