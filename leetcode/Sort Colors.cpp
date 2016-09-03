#include "common.h" // my defined macros

// https://leetcode.com/problems/sort-colors/

void sortColors(vector<int>& nums) 
{
	int n = nums.size();
	if(n < 2) return;
	//
	for(int i=1; i<n; i++)
	{
		for(int j=i; j>0 && nums[j]<nums[j-1]; j--)		
			swap(nums[j],nums[j-1]);		
	}	
}
int testCase0()
{
	int a[] = {1,0,2,1,0,2};
	vector<int> nums(a, a + sizeof a / sizeof a[0]);
	sortColors(nums );
	return 0;
}