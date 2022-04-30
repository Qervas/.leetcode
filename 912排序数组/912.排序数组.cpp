/*
 * @Author: FrankTudor
 * @Date: 2022-04-27 00:56:25
 * @LastEditors: FrankTudor
 * @Description: This file is created, edited, contributed by FrankTudor
 * @LastEditTime: 2022-04-30 16:21:44
 */
/*
 * @lc app=leetcode.cn id=912 lang=cpp
 *
 * [912] 排序数组
 */

// @lc code=start
#include<iostream>
#include<vector>
using namespace std;
namespace ysx{
    void swap(int& x, int& y){
        if(x==y){return;}
        x ^= y;
        y ^= x;
        x ^= y;
    }
    void Reverse(vector<int>& nums, int x, int y){
        while(x < y){
            ysx::swap(nums[x++], nums[y--]);
        }
    }
    void Convert(vector<int>& nums, int lo, int mi, int hi){
        Reverse(nums, lo, mi);
        Reverse(nums, mi + 1, hi);
        Reverse(nums, lo, hi);
    }
} // namespace ysx
class Solution {
public:


    //####Sort####
    // vector<int> sortnumsay(vector<int>& nums) {

    // }
    //####Sort####
    // vector<int> sortnumsay(vector<int>& nums) {

    // }
    //####Sort####
    // vector<int> sortnumsay(vector<int>& nums) {

    // }

    //####Sort####
    // vector<int> sortnumsay(vector<int>& nums) {

    // }

    //####Merge Sort####
    //in-place version time limit exceeded
    // void inPlaceMergeSort(const int& lo,const int& hi, vector<int>& nums){
    //     if(lo == hi || lo == hi - 1){return ;}
    //     inPlaceMergeSort(lo, (lo+hi)>>1, nums);//[a, b)
    //     inPlaceMergeSort((lo+hi)>>1, hi, nums);
    //     int mi = (lo + hi) >> 1,i = lo, j = mi;
    //     int index;
    //     while(i < j && j < hi){
    //         for(;i < j && nums[i] < nums[j];i++);
    //         index = j;
    //         for(;j < hi && nums[j] < nums[i]; j++);
    //         ysx::Convert(nums,i,index-1,j-1);
    //         i += j - index;
    //     }       
    // }
    //insertionMergeSort()
    //Your runtime beats 16.27 % of cpp submissions
    // Your memory usage beats 11.87 % of cpp submissions (28.7 MB)
    // void insertionMergeSort(const int& lo, const int& hi, vector<int>& nums, vector<int>& sorted){
    //     if(lo == hi || lo == hi - 1){return;}
    //     insertionMergeSort(lo, (lo+hi)>>1, nums, sorted);
    //     insertionMergeSort((lo+hi)>>1, hi, nums, sorted);
    //     int length = hi - lo, mi = (hi+lo)>>1;
    //     int i = lo, j = mi, k = 0;
    //     for(; i < mi && j < hi;k++){
    //         if(nums[i] <= nums[j]){
    //             sorted[k] = nums[i];
    //             i++;
    //         }else{
    //             //swap nums[i], nums[j] here would sabotage the ordering in right hand side part                 
    //             sorted[k] = nums[j];
    //             j++;
    //         }
    //     }
    //     if(i >= mi){//rhs remains
    //         while(j < hi){
    //             sorted[k++] = nums[j++];
    //         }
    //     }
    //     else if(j >= hi){//lhs remains
    //         while(i < mi){
    //             sorted[k++] = nums[i++];
    //         }
    //     }//i and j are impossible meet with i >= mi && j >= hi simultaneously
    //     for(int iter_nums = lo, iter_sorted = 0; iter_nums < hi && iter_sorted < k ; iter_nums++, iter_sorted++){//delta iter < k
    //         nums[iter_nums] = sorted[iter_sorted];
    //     }
    // }
    // vector<int> sortnumsay(vector<int>& nums) {
    //     vector<int> sorted(nums.size());
    //     insertionMergeSort(0,nums.size(), nums, sorted);
    //     // inPlaceMergeSort(0, nums.size(), nums);
    //     return nums;
    // }

    //####Shell Sort#### O(n3/2) by Knuth
    //Remember: it is best not to have a common factor other than 1 
    //          for every two elements in the incremental sequence! 
    //          (Obviously, it doesn't make much sense to sort a sequence sorted by 4 and then sort by 2).
    //Your runtime beats 52.38 % of cpp submissions
    //Your memory usage beats 76.72 % of cpp submissions (27.7 MB)
    // vector<int> sortnumsay(vector<int>& nums) {
    //     int h = 1;
    //     while(h < nums.size() /3){
    //         h = 3*h+1;
    //     }
    //     while(h>=1){
    //         for(int i = h,j; i < nums.size(); i++){
    //             for(j = i; j >= h && nums[j] < nums[j-h]; j-=h){
    //                 ysx::swap(nums[j],nums[j-h]);
    //             }
    //         }
    //         h /= 3;
    //     }
    //     return nums;
    // }

    //####Insertion Sort####
    // Time Limit Exceeded
    // 10/13 cases passed (N/A)
    vector<int> insertionSort(vector<int>& nums) {
        for(int i = 1; i < nums.size(); i++){
            int j=i;
            while(j > 0){
                if(nums[j] < nums[j-1]){
                    swap(nums[j-1],nums[j]);
                     j--;
                }else break;
            }
        }
        return nums;
    }

    //####Selection Sort####
    // Time Limit Exceeded
    // 10/13 cases passed (N/A)
    // vector<int> sortnumsay(vector<int>& nums) {
    //     int min;
    //     int length = nums.size();
    //     for(int i = 0,j; i < length-1; i++){
    //         for(j = i+1,min=i; j < length; j++){
    //             min = nums[min] <= nums[j] ? min : j;
    //         }
    //         if(i != min) swap(nums[i],nums[min]);
    //     }
    //     return nums;
    // }

    //####Bubble Sort####
    // Time Limit Exceeded
    // 10/13 cases passed (N/A)
    // vector<int> sortnumsay(vector<int>& nums) {
    //     int end = nums.size() -1;
    //     for(int i = 0, j;i <= end; i++){
    //         for(j = end; j > i; j--){
    //             if(nums[j]<nums[j-1]){
    //                   swap(nums[j],nums[j-1]);
    //             }
    //         }
    //     }
    //     return nums;
    // }

    //####Quick Sort####
int partition(vector<int>& nums, int l, int r) {
        int pivot = nums[r];
        int i = l - 1;
        for (int j = l; j <= r - 1; ++j) {
            if (nums[j] <= pivot) {
                i = i + 1;
                swap(nums[i], nums[j]);
            }
        }
        swap(nums[i + 1], nums[r]);
        return i + 1;
    }
    int randomized_partition(vector<int>& nums, int l, int r) {
        int i = rand() % (r - l + 1) + l; // 随机选一个作为我们的主元
        swap(nums[r], nums[i]);
        return partition(nums, l, r);
    }
    void randomized_quicksort(vector<int>& nums, int l, int r) {
        if (l < r) {
            int pos = randomized_partition(nums, l, r);
            randomized_quicksort(nums, l, pos - 1);
            randomized_quicksort(nums, pos + 1, r);
        }
    }
public:
    vector<int> sortArray(vector<int>& nums) {
        srand((unsigned)time(NULL));
        randomized_quicksort(nums, 0, (int)nums.size() - 1);
        return nums;
    }





};
// @lc code=end