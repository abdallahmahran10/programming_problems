#include "common.h" // my defined macros

// https://leetcode.com/problems/find-the-duplicate-number/

int findDuplicate(vector<int>& nums) {
	if(nums.size() ==2)
		return nums[0];
	sort(nums.begin(), nums.end());
	int result = -1;
	for(int i=0; i<nums.size()-1; i++)
	{
		if(nums[i]==nums[i+1])
			result  = nums[i];
	}
	return result;
}

int testCase0()
{
	int a[] = {1,3,2,2};
	vector<int> nums(a, a + sizeof a / sizeof a[0]);
    //
    return findDuplicate(nums);
}
int testCase1()
{
	int a[] = {3,3};
	vector<int> nums(a, a + sizeof a / sizeof a[0]);
    //
    return findDuplicate(nums);
}
int testCase2()
{
	int a[] = {1,2,3,4,12,23,8,7,12};
	vector<int> nums(a, a + sizeof a / sizeof a[0]);
    //
    return findDuplicate(nums);
}