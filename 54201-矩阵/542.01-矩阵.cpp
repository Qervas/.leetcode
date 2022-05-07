/*
 * @Author: FrankTudor
 * @Date: 2022-05-07 08:44:37
 * @LastEditors: FrankTudor
 * @LastEditTime: 2022-05-07 22:59:27
 */
/*
 * @lc app=leetcode.cn id=542 lang=cpp
 *
 * [542] 01 矩阵
 */
#include<iostream>
#include<vector>
#include<queue>
#include<utility>
using std::pair;
using std::queue;
using std::vector;
// @lc code=start
class Solution {
private:
    const pair<int,int> dir[4] = {{-1,0},{1,0},{0,-1},{0,1}};

public:

    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        if(mat.empty()){return mat;}
        size_t row = mat.size() , col = mat.at(0).size();
        vector<vector<int>> dist(mat);
        vector<vector<int>> seen(row, vector<int>(col));
        queue<pair<int,int>> pList;
        int r,c;
        for(size_t i = 0, j; i < row; ++i){
            for(j = 0; j < col; ++j){
                if(mat[i][j]==0){
                    pList.push({i,j});
                    seen[i][j] = 1;
                }
            }
        }
        while(!pList.empty()){
            auto [i, j] = pList.front();
            pList.pop();
            for(int d = 0; d < 4; ++d){
                int ii = i + dir[d].first;
                int jj = j + dir[d].second;
                if(ii >= 0 && ii < row && jj >= 0 && jj < col && !seen[ii][jj]){
                    dist[ii][jj] = dist[i][j] + 1;
                    pList.push({ii, jj});
                    seen[ii][jj] = 1;
                }
            }
        }
        return dist;
        
    }
};
// @lc code=end

