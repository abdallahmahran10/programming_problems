/*
	Author: Abdallah Mahran
	Ref: https://www.interviewbit.com/problems/maximum-absolute-difference/
	Date: 12/06/2016
*/

// Includes
#include "common.h"
// Types
// Functions
int getMaxVal(vector<int> &A, int i, int j)
{
	return abs(A[i] - A[j]) + abs(i - j);
}
int maxArr(vector<int> &A) {
	if(A.empty())
		return 0;
	set<int, int> s;
	int size = A.size();
	for(int i=0; i<size; i++)
	{
		s.insert(A[i], i);
	}
	// |A[i] - A[j]| + |i - j|
	int maxVal=-1;
	size = s[];
	for(int i=0; i<size; i++)
	{
		int currMaxVal = getMaxVal(A, i, size - i -1);
		maxVal = max(maxVal, currMaxVal);
	}
	return maxVal;
}

// Test cases
int testCase0()
{
	int a[] ={1, 3, -1};
	vector<int> nums(a, a + sizeof a / sizeof a[0]);
	return maxArr(nums);
}