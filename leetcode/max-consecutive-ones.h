/*
	Author: Abdallah Mahran
	Ref: https://leetcode.com/problems/max-consecutive-ones/
	Date: 1/17/2017
*/
// Includes
#include "common.h"
// Types
// Functions
int findMaxConsecutiveOnes(vector<int>& nums) {
	int count = 0;
	int maxCount = 0;
	int tmp = 1;
	for (int i = 0; i < nums.size(); i++)
	{
		if (nums[i])
			count++;
		else
		{
			maxCount = max(maxCount, count);
			count = 0;
		}
	}
	return max(maxCount, count);
}
// Test cases
void testCase0()
{
	int a[] = { 1, 0, 1, 1, 0, 1 };
	cout << findMaxConsecutiveOnes(vector<int>(a, END(a))) << endl;
	int a1[] = { 1, 0, 1, 1, 1, 1 };
	cout << findMaxConsecutiveOnes(vector<int>(a1, END(a1))) << endl;
	int a2[] = { 1, 0 };
	cout << findMaxConsecutiveOnes(vector<int>(a2, END(a2))) << endl;
	int a22[] = { 0, 1 };
	cout << findMaxConsecutiveOnes(vector<int>(a22, END(a22))) << endl;
	int a3[] = { 0, 0 };
	cout << findMaxConsecutiveOnes(vector<int>(a3, END(a3))) << endl; 
	int a4[] = { 0};
	cout << findMaxConsecutiveOnes(vector<int>(a4, END(a4))) << endl;
	int a5[] = { 1 };
	cout << findMaxConsecutiveOnes(vector<int>(a5, END(a5))) << endl;
}
