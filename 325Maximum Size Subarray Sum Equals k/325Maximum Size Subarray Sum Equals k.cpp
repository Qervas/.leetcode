/*
 * @Author: FrankTudor
 * @Date: 2022-05-28 11:53:20
 * @LastEditors: FrankTudor
 * @Description: This file is created, edited, contributed by FrankTudor
 * @LastEditTime: 2022-05-29 00:11:37
 */
#include<iostream>
#include<vector>
#include<algorithm>
#include<unordered_map>
#include <initializer_list>
using std::unordered_map;
using std::vector;

class Solution {
public:
    double maxSubArrayLen(vector<int>& nums, int k) {
        double sum = 0;
		double maxLen = 0;
		unordered_map<double,size_t> m;
		m[0] = -1;//(sum-k value, index)
		for(size_t i = 0; i < nums.size(); i++){
			sum += nums.at(i); //calculate sum
			if(m.find(sum) == m.end()){ // assure that the index of the same sum value is the most left one
				m[sum] = i;// if it doesn't exist, create one
			}
			if(m.find(sum - k) != m.end()){//search for (sum - k)
				double len = i - m[sum-k]; 
				maxLen = maxLen < len ? len : maxLen;
			}
		}
		return maxLen;
    }
};


int main(void){
	Solution s;
	vector<int> nums{1,-1,5,-2,3};
	std::cout << s.maxSubArrayLen(nums, 3) << "\n";
	return EXIT_SUCCESS;
}