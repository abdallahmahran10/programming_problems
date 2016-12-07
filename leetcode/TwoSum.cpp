/*
   Author: Abdallah Mahran
   Ref: https://leetcode.com/problems/two-sum/
*/

#include "common.h"

vector<int> twoSum(vector<int>& nums, int target) {
	vector<int> result;
	if (nums.empty())
		return result;
	for (int i = 0; i < nums.size(); i++)
		for (int j = i+1; j < nums.size(); j++)
		{
			if (nums[i] + nums[j] == target)
			{
				result.push_back(i);
				result.push_back(j);
				return result;
			}
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
