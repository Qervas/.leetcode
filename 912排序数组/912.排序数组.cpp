/*
 * @Author: FrankTudor
 * @Date: 2022-04-27 00:56:25
 * @LastEditors: FrankTudor
 * @Description: This file is created, edited, contributed by FrankTudor
 * @LastEditTime: 2022-04-30 00:40:25
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
    // vector<int> sortArray(vector<int>& nums) {

    // }
    //####Sort####
    // vector<int> sortArray(vector<int>& nums) {

    // }
    //####Sort####
    // vector<int> sortArray(vector<int>& nums) {

    // }

    //####Sort####
    // vector<int> sortArray(vector<int>& nums) {

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
    // vector<int> sortArray(vector<int>& nums) {
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
    // vector<int> sortArray(vector<int>& nums) {
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
    // vector<int> sortArray(vector<int>& nums) {
    //     for(int i = 1; i < nums.size(); i++){
    //         int j=i;
    //         while(j > 0){
    //             if(nums[j] < nums[j-1]){
    //                 swap(nums[j-1],nums[j]);
    //                  j--;
    //             }else break;
    //         }
    //     }
    //     return nums;
    // }

    //####Selection Sort####
    // Time Limit Exceeded
    // 10/13 cases passed (N/A)
    // vector<int> sortArray(vector<int>& nums) {
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
    // vector<int> sortArray(vector<int>& nums) {
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
    int partition(int lo, int hi, vector<int>& nums){//[lo,hi)
        if(lo >= hi - 1){return lo;}
        int base = nums[lo];//randomization is better
        int i = lo + 1;
        int j = hi - 1;
        while(i < j){
            while( i < j && nums[i] < base){i++;}
            while( i < j && nums[j] > base){j--;}
            //nums[i] >= base && nums[j] <= base;
            if(nums[i] >= base && base >= nums[j]){//nums[i] > x > nums[j]
                ysx::swap(nums[i], nums[j]);
            }
        }
        ysx::swap(nums[lo],nums[i]);
        return i;
        
        // int x = nums[lo];
        // int i = lo + 1, j = hi-1;
        // while(i < j){
        //     if(nums[i] < x){
        //         i++;
        //         continue;
        //     }
        //     if(x < nums[j]){
        //         j--;
        //         continue;
        //     }
        //     if(nums[i] > x && x >= nums[j]){//nums[i] > x > nums[j]
        //         ysx::swap(nums[i], nums[j]);
        //         continue;
        //     }

        // }
        // // if(i == hi - 1 || nums[lo] > nums[i]){
        //     ysx::swap(nums[lo], nums[i]);
        // // }
        // // if(j == lo + 1 && nums[lo] > nums[j]){
        // //     ysx::swap(nums[lo], nums[i]);
        // // }
        // return i;
    }
    void print(vector<int>& vec){
        for(int& x: vec){
            printf("%d, ",x);
        }
    }
    vector<int> sortArray(vector<int>& nums) {
        print(nums);printf("\n");
        if(nums.empty()){return {};}
        if(nums.size() == 1){return nums;}
        int stack[nums.size()];
        int top = -1, hi, lo;
        stack[++top] = 0;
        stack[++top] = nums.size();
        int pivot;
        while(top >= 0){
            hi = stack[top--];
            lo = stack[top--];
            if(nums[pivot]== -1){
                printf("");
            }
            pivot = partition(lo, hi, nums);
            print(nums);
            printf("pivot: %d|| ",nums[pivot]);
            printf("[%d, %d)",lo,hi);
            printf("\n");
            if(pivot - 1 >= lo){//[lo, pivot)
                stack[++top] = lo;
                stack[++top] = pivot;
                // printf("lo: [%d, %d)\n",lo, pivot);
            }
            if(pivot + 1 < hi){//[pivot + 1, hi)
                stack[++top] = pivot + 1;
                stack[++top] = hi;
                // printf("hi: [%d, %d)\n",pivot+1, hi);
            }
        }
        return nums;
    }


};
// @lc code=end

int main(){
    Solution s;
    vector<int> vec{-4,0,7,4,9,-5,-1,0,-7,-1};
    s.sortArray(vec);

    return 0;
}