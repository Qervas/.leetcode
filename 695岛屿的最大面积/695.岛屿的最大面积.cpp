/*
 * @Author: FrankTudor
 * @Date: 2022-05-05 11:09:47
 * @LastEditors: FrankTudor
 * @Description: This file is created, edited, contributed by FrankTudor
 * Your runtime beats 72.29 % of cpp submissions
 * Your memory usage beats 39.01 % of cpp submissions (23 MB)
 * @LastEditTime: 2022-05-05 16:17:05
 */
/*
 * @lc app=leetcode.cn id=695 lang=cpp
 *
 * [695] 岛屿的最大面积
 */
#include<vector>
#include<stack>
using namespace std;
// @lc code=start
class Solution {
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        if(grid.empty()){return 0;}
        const size_t row = grid.size(), col = grid.at(0).size();
        int max = 0;
        int x,y;
        int count = 0;
        stack<pair<int,int>> coordinates;
        for(size_t i = 0,j; i < row; i++){
            for(j = 0; j < col; j++){
                if(grid[i][j] != 0){
                    coordinates.push({i,j});
                    count = 0;
                    while(coordinates.size()){
                        x = coordinates.top().first;
                        y = coordinates.top().second;
                        coordinates.pop();
                        if(grid[x][y]){
                            count++;
                            grid[x][y] = 0;
                        } 
                        if(x > 0 && grid[x-1][y] != 0){
                            coordinates.push({x-1,y});
                        }
                        if(x < row-1 && grid[x+1][y] != 0){
                            coordinates.push({x+1,y});
                        }
                        if(y > 0 && grid[x][y-1] != 0){
                            coordinates.push({x,y-1});
                        }
                        if(y < col-1 && grid[x][y+1] != 0){
                            coordinates.push({x,y+1});
                        }
                    }
                    max = max < count ? count : max;
                }
            }
        }
        return max;
    }
};
// @lc code=end

int main(void){
    Solution s;
    vector<vector<int>> grid = {{1,1,0,0,0},{1,1,0,0,0},{0,0,0,1,1},{0,0,0,1,1}};

    s.maxAreaOfIsland(grid);
}

