/*
 * @Author: FrankTudor
 * @Date: 2022-06-01 23:28:18
 * @LastEditors: FrankTudor
 * @Description: This file is created, edited, contributed by FrankTudor
 * Your runtime beats 72.63 % of cpp submissions
 * Your memory usage beats 94.87 % of cpp submissions (9.1 MB)
 * @LastEditTime: 2022-06-02 00:20:55
 */
/*
 * @lc app=leetcode.cn id=74 lang=cpp
 *
 * [74] 搜索二维矩阵
 */
#include<vector>
#include<iostream>
using std::vector;
// @lc code=start
int col, row;
struct Coordinate{
    int x;
    int y;
    int getIndex1D()const {
        return this->x*col + this->y;
    }
    void setAsMidPoint(const Coordinate& a, const Coordinate& b){
        int I_mid = (a.getIndex1D() + b.getIndex1D())>>1;
        this->x = I_mid/col, this->y = I_mid % col;
    }
    int getMatrixValue(vector<vector<int>>& matrix){
        return matrix[this->x][this->y];
    }
    Coordinate()=default;
    Coordinate(const int& _x, const int& _y):x(_x), y(_y){}
    Coordinate(const Coordinate& other)=default;
    Coordinate(Coordinate&& other)=default;

};
class Solution {
public:
    Coordinate matrixBinarySearch(vector<vector<int>>& matrix, Coordinate lo, Coordinate hi, int target){
        int i_lo = lo.getIndex1D(), i_hi = hi.getIndex1D();
        if(i_lo >= i_hi  - 1){return lo;}
        Coordinate mi;
        mi.setAsMidPoint(lo, hi);
        if(mi.getMatrixValue(matrix) <= target){
            return matrixBinarySearch(matrix, mi, hi, target);
        }else{
            return matrixBinarySearch(matrix, lo, mi, target);
        }
    }
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        row = matrix.size(), col = matrix.at(0).size();
        int size = row * col, ansIndex;
        ansIndex = matrixBinarySearch(matrix, {0,0}, {row-1, col}, target).getIndex1D();
        if(matrix[ansIndex/col][ansIndex%col] != target){return false;}
        return true;
        
    }
};
// @lc code=end
int main(void){
    Solution s;
    vector<vector<int>> v{{1,3,5,7},{10,11,16,20},{23,30,34,60}};
    std::cout << s.searchMatrix(v, 60) << "\n";    

    return 0;
}
