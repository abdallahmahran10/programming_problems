/*
	Author: Abdallah Mahran
	Ref: https://leetcode.com/problems/array-partition-i/description/ 
	Date:9/3/2017 
*/

// Includes
#include "../common.h"
// Types
// Functions
int arrayPairSum(vector<int>& nums) {
    sort(nums.begin(), nums.end());
    int pairsCount = sqrt(nums.size());	
    long sum =0; 
    for(int i=0; i<nums.size()-1; i+=2)
    {
        sum+=min(nums[i], nums[i+1]);
    }
    return sum;
 }
// Test cases
