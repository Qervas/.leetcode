#include<iostream>
#include<vector>
#include<queue>
using namespace std;

// Runtime: 8 ms, faster than 69.27% of C++ online submissions for Rotting Oranges.
// Memory Usage: 13 MB, less than 94.70% of C++ online submissions for Rotting Oranges.
class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        if(grid.empty()){return 0;}
        queue<pair<int,int>> q;
        int freshCount = 0;
        size_t curLayerCount = 0;
        size_t row = grid.size(), col = grid.at(0).size();
        for(size_t i = 0; i < row; ++i){
            for(size_t j = 0; j < col; ++j){
                if(grid[i][j] == 1){freshCount++;}
                if(grid[i][j] == 2){
                    q.push({i,j});
                }
            }
        }
        if(freshCount == 0){return 0;}
        int times = 0;
        size_t n;
        while(q.size() && ++times){
            n = q.size();
            for(size_t k = 0; k < n; k++){
                int i = q.front().first;
                int j = q.front().second;
                q.pop();
                if(i > 0 && grid[i-1][j] == 1){
                    freshCount--;
                    grid[i-1][j] = 2;                
                    q.push({i-1,j});
                }
                if(j > 0 && grid[i][j-1] == 1){
                    freshCount--;
                    grid[i][j-1] = 2;
                    q.push({i,j-1});
                }
                if(i < row - 1 && grid[i+1][j] == 1){
                    freshCount--;
                    grid[i+1][j] = 2;
                    q.push({i+1,j});
                }
                if(j < col - 1 && grid[i][j+1] == 1){
                    freshCount--;
                    grid[i][j+1] = 2;
                    q.push({i,j+1});
                }
            }
        }
        return freshCount > 0  ? -1 : times-1;
    }
};
int main(void){
    Solution s;
    vector<vector<int>> vec{{2,1,1},{1,1,0},{0,1,1}};
    s.orangesRotting(vec);

    return 0;

}