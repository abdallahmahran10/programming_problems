/*
	Author: Abdallah Mahran
*/

// Includes
#include "common.h"
// Types
// Functions
int partition(vector<int> &nums, int s, int e)
{
	int pivotIdx = e;
	for(int i=e-1; i>=s; i--)
	{
		if(nums[i]> nums[pivotIdx])
		{
			int j = i;
			if(abs(i-pivotIdx) > 1)
			{
				while(j<pivotIdx-1)
					swap(nums[j], nums[j++]);
				
			} 
			swap(nums[j], nums[pivotIdx]);
			pivotIdx = j;
		}
	}
	return pivotIdx;
}

void quickSort(vector<int> &nums, int s, int e)
{
	if(s<e)
	{
		int pivotIdx = partition(nums, s, e);
		quickSort(nums, s, pivotIdx-1);
		quickSort(nums, pivotIdx+1, e);
	}
}

vector<int>& sort(vector<int>& nums)
{
	quickSort(nums, 0, nums.size()-1);
    return nums;
}

// Test cases
void testCase()
{
	int a[] = { 1};
	vector<int> nums;//(a, a + (sizeof a / sizeof a[0]));
	printVector( sort(nums));
	int a1[] = { 0,1,0,1,0,1,0,1};
	vector<int> nums1(a1, a1 + (sizeof a1 / sizeof a1[0]));
	printVector( sort(nums1));
	int a2[] = {-1,-2};
	vector<int> nums2(a2, a2 + (sizeof a2 / sizeof a2[0]));
	printVector( sort(nums2));
}