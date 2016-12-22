/*
Author: Abdallah Mahran
Ref: https://leetcode.com/problems/search-insert-position/
Date: 12/22/2016
*/

// Includes
#include "common.h"
// Types
// Functions

int searchInsert(vector<int>& nums, int target) {
	if (nums.empty())
		return 0;
	int targetIdx = 0;
	vector<int>::iterator it = lower_bound(nums.begin(), nums.end(), target);
	if (it == nums.end()) { return nums.size(); }
	return it - nums.begin();
	for (size_t i = 1; i < nums.size(); ++i)
	{
		if (nums[i] == target)
			return i;
		if (nums[i] < target)
		{
			targetIdx++;
			continue;
		}
		return i;

	}
	return ++targetIdx;
}
// Test cases
void testCase0()
{
	int a[] = { 1, 3, 5, 6 };
	vector<int> n(a, a + (sizeof a / sizeof a[0]));
	PRINT_INT(searchInsert(n, 5));
}

void testCase1()
{
	int a[] = { 1, 3, 5, 6 };
	vector<int> n(a, a + (sizeof a / sizeof a[0]));
	PRINT_INT(searchInsert(n, 2));
}

void testCase2()
{
	int a[] = { 1, 3, 5, 6 };
	vector<int> n(a, a + (sizeof a / sizeof a[0]));
	PRINT_INT(searchInsert(n, 7));
}

void testCase3()
{
	int a[] = { 1, 3, 5, 6 };
	vector<int> n(a, a + (sizeof a / sizeof a[0]));
	PRINT_INT(searchInsert(n, 0));
}
