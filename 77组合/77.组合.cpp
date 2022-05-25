
/*
 * @lc app=leetcode.cn id=77 lang=cpp
 *
 * [77] 组合
 */
#include<vector>
#include<stack>
#include<iostream>
using std::vector;
using std::stack;
// @lc code=start
class Solution {
public:
    vector<int> temp;
    vector<vector<int>> ans;

    vector<vector<int>> combine(int n, int k) {
        // 初始化
        // 将 temp 中 [0, k - 1] 每个位置 i 设置为 i + 1，即 [0, k - 1] 存 [1, k]
        // 末尾加一位 n + 1 作为哨兵
        for (int i = 1; i <= k; ++i) {
            temp.push_back(i);
        }
        temp.push_back(n + 1);
        
        int j = 0;
        while (j < k) {
            ans.emplace_back(temp.begin(), temp.begin() + k);
            j = 0;
            // 寻找第一个 temp[j] + 1 != temp[j + 1] 的位置 t
            // 我们需要把 [0, t - 1] 区间内的每个位置重置成 [1, t]
            while (j < k && temp[j] + 1 == temp[j + 1]) {
                temp[j] = j + 1;
                ++j;
            }
            // j 是第一个 temp[j] + 1 != temp[j + 1] 的位置
            ++temp[j];
        }
        return ans;
    }
};


//https://leetcode.cn/problems/combinations/solution/zu-he-by-leetcode-solution/

// @lc code=endq

int main(void){
    Solution s;
    vector<vector<int> > ans = s.combine(4,2);
    for(size_t i = 0; i < ans.size(); i++){
        printf("[");
        for(size_t j = 0; j < ans.at(i).size(); j++){
            printf("%d, ",ans.at(i).at(j));
        }
        printf("]\n");
    }
    printf("End\n");
    return 0;
}