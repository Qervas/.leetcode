/*
 * @lc app=leetcode.cn id=567 lang=cpp
 *
 * [567] 字符串的排列
 */
#include<string>
#include<iostream>
#include<vector>
using namespace std;
// @lc code=start
class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        if(s1.size() > s2.size()){return false;}
        vector<int> s1_charset(26,0), window_charset(26,0);
        for(int i = 0; i < s1.size(); i++){
            s1_charset[s1[i] - 'a']++;
        }
        int s1_charset_counter = 0;
        int window_charset_counter = 0;//total times when s1_charset == window_charset
        for(int i = 0; i < 26; i++){
            if(s1_charset[i]){s1_charset_counter++;}
        }
        size_t lo=0, hi=0, length = s2.size();
        while(hi < length){
            if(s1_charset[s2[hi] - 'a']> 0){
                window_charset[s2[hi] - 'a']++;
                if(window_charset[s2[hi]-'a'] == s1_charset[s2[hi] - 'a']){
                    window_charset_counter++;
                }
            }
            hi++;
            while(s1_charset_counter == window_charset_counter ){
                if(hi - lo == s1.size()){//same length
                    return true;
                }
                if(s1_charset[s2[lo] - 'a'] > 0){//if there contains unrelevant character inside of window_charset
                    window_charset[s2[lo] - 'a']--;//remove the [lo] position character out of the window
                    if(window_charset[s2[lo] - 'a'] < s1_charset[s2[lo] - 'a']){
                        window_charset_counter--;
                    }
                }
                lo++;
            }
        }
        return false;
    }
};
// @lc code=end
int main(){
    Solution s;
    s.checkInclusion("adc","dcda");
    return 0;
}

