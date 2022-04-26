/*
 * @Author: FrankTudor
 * @Date: 2022-04-25 15:37:26
 * @LastEditors: FrankTudor
 * @Description: This file is created, edited, contributed by FrankTudor
 * @LastEditTime: 2022-04-25 17:19:55
 */
/*
 * @lc app=leetcode.cn id=215 lang=cpp
 *
 * [215] 数组中的第K个最大元素
 */

// @lc code=start
#include<vector>
#include<algorithm>
#include<iostream>
using namespace std;
class Solution {
public:
    // #####################
    // ##### Heap sort #####
    // #####################
    // Your runtime beats 96.7 % of cpp submissions
    // Your memory usage beats 48.78 % of cpp submissions (9.8 MB)
    void maxHeapify(vector<int>& data, int i, int heapSize){
        int _left = (i << 1) + 1, _right = (i << 1) + 2, max = i;
        if(_left < heapSize && data[_left] > data[max]){
            max = _left;
        }
        if(_right < heapSize && data[_right] > data[max]){
            max = _right;
        }
        if(max != i){
            swap(data[i], data[max]);
            maxHeapify(data, max, heapSize);
        }
    }

    void makeMaxHeap(vector<int>&data, const int & heapSize){
        for(int i = heapSize/2; i >=0; i--){
            maxHeapify(data, i, heapSize);
        }
    }

    int findKthLargest(vector<int>& nums, int k) {
        if(k > nums.size()){throw std::out_of_range("k > nums.size()");}
        int heapSize = nums.size();
        makeMaxHeap(nums, heapSize);
        for(int i = heapSize-1; i >= nums.size() - k + 1; i--){
            swap(nums[0], nums[i]);
            heapSize--;
            maxHeapify(nums, 0, heapSize);
        }
        return nums[0];
    }
    // ##################
    // ##### sort #######
    // ##################
    // Your runtime beats 73.21 % of cpp submissions
    // Your memory usage beats 71.32 % of cpp submissions (9.7 MB)
    //     int findKthLargestSortedVersion(vector<int>& nums, int k) {
    //         if(k > nums.size()){throw std::out_of_range("k > nums.size()");}
    //         sort(nums.begin(), nums.end(),[](const int& lhs, const int& rhs){return lhs > rhs;});
    //         return *(nums.begin()+k-1);
    //     }

    // #####################
    // ##### map, slow######
    // #####################
    //Your runtime beats 32.86 % of cpp submissions
    // Your memory usage beats 5 % of cpp submissions (12 MB)
    // int findKthLargestMapVersion(vector<int>& nums, int k) {
    //     map<int,int> m;
    //     for(int& x:nums){
    //         if(!m.count(x)){
    //             m.insert(make_pair(x,1));
    //         }else{
    //             m[x]++;
    //         }
    //     }
    //     auto i = m.rbegin();
    //     for( ;k;k--){
    //         if((*i).second== 0){
    //             i++;
    //         }
    //         (*i).second--;
    //     }
    //     return (*i).first;

    // }
};
// @lc code=end

// int main(void){
//     Solution s;
//     vector<int> vec{3,2,1,5,6,4};
//     s.findKthLargest(vec,2);
//     return 0;
// }