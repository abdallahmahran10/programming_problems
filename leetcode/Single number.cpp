#include "common.h" // my defined macros

// https://leetcode.com/problems/single-number/
int singleNumber(vector<int>& nums) {
	int n = nums.size();
	assert(n>0);
	int answer=0;
	F(n)
		answer ^= nums[i];
	
	return answer;
}
int singleNumber2(vector<int>& nums) {
	int n = nums.size();
	assert(n>0);
	int answer=0;
	map<int, bool> searchMap;
	F(n)
		searchMap[nums[i]] = !searchMap[nums[i]];
	
	F(n)
		if(searchMap[nums[i]])
		{
			answer = nums[i];
			break;
		}

	return answer;
}
int testCase0()
{
	int a[] ={1,2,2,1,3,4,55,3,55};
	vector<int> nums(a, a + sizeof a / sizeof a[0]);
	return singleNumber(nums);
}

