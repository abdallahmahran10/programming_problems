/*
   Author: Abdallah Mahran
   Ref: https://leetcode.com/problems/two-sum/
*/

#include "common.h"


typedef unordered_map<int, int>::const_iterator cit;
vector<int> twoSum(vector<int>& nums, int target) {
	vector<int> result; 
	unordered_map<int, int> hash;
	for (int i = 0; i < nums.size(); i++)
	{
		cit it = hash.find(target - nums[i]);
		if (it != hash.end())
		{
			result.push_back(it->second);
			result.push_back(i);
			break;
		}
		hash[nums[i]] = i;
	}
	return result;
}
void testCase0()
{
	int tmp[] = { 3, 4, 1, 4, 1 };
	std::vector<int> A(tmp, tmp + (sizeof(tmp) / sizeof(*tmp)));
	int target = 9;
	printVector(twoSum(A, target));
}

void testCase1()
{
	int tmp[] = { 2, 7, 11, 15 };
	std::vector<int> A(tmp, tmp + (sizeof(tmp) / sizeof(*tmp)));
	int target = 9;
	printVector(twoSum(A, target));
}

void testCase2()
{
	int tmp[] = { 3, 2, 4 };
	std::vector<int> A(tmp, tmp + 3);
	int target = 6;
	printVector(twoSum(A, target));
}
