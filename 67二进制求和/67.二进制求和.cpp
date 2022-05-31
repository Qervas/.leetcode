/*
 * @Author: FrankTudor
 * @Date: 2022-05-31 16:10:54
 * @LastEditors: FrankTudor
 * @Description: This file is created, edited, contributed by FrankTudor
 * Your runtime beats 100 % of cpp submissions
 * Your memory usage beats 74.69 % of cpp submissions (6.1 MB)
 * @LastEditTime: 2022-05-31 17:12:48
 */
/*
 * @lc app=leetcode.cn id=67 lang=cpp
 *
 * [67] 二进制求和
 */
#include<iostream>
#include<string>
#include<algorithm>
using std::string;
// @lc code=start
class Solution {
public:
    string addBinary(string& a, string& b) {
        string& small = a.size() < b.size() ? a : b;
        string& big   = a.size() < b.size() ? b : a;
        int carry = 0;
        int cur_bit;
        string answer;
        auto is = small.rbegin(), ib = big.rbegin();
        for(; is != small.rend();is++, ib++){
            int sum = (*is)+(*ib) + carry - '0' - '0';
            cur_bit = sum % 2;
            carry = sum >> 1;
            answer.push_back(cur_bit + '0');            
        }
        if(carry){
            while(ib != big.rend()){
                int sum = (*ib) - '0' + carry;
                cur_bit = sum % 2;
                carry = sum >> 1;
                ib++;
                answer.push_back(cur_bit + '0');   
            }
            if(carry){answer.push_back('1');}
        }else{
            while(ib != big.rend()){    
                answer.push_back((*ib));
                ib++;
            }
        }
        std::reverse(answer.begin(), answer.end());
        return answer;
    }
};
// @lc code=end

int main(){
    Solution s;
    string a = "101111", b = "10";
    std::cout << s.addBinary(a, b);
    return EXIT_SUCCESS;
}