// playground.cpp : Defines the entry point for the console application.
//
#include "stdafx.h"
#include "common.h" // my defined macros

//#include "MaximumAbsoluteDifference.h"
/////////////////////uva problems template /////////////////////
//12356 - Army Buddies
int uva12356()
{
#ifdef LOCAL
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);        
#endif
	// Your code is here //////////////////////////
	
	///////////////////////////////////////////////
#ifdef LOCAL
	fclose (stdout);
#endif
	return 0;
}
///////////////////////
void Main()
{
#ifdef LOCAL
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);        
#endif
	// Implmentation //////////////////////////////
	
	///////////////////////////////////////////////
#ifdef LOCAL
	fclose (stdout);
#endif
}

int partition(vector<int> &nums, int s, int e)
{
	int pivotIdx = e;
	for(int i=e-1; i>=s; i--)
	{
		if(nums[i]< nums[pivotIdx])
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
void mergeInPlace(vector<int> &nums, int s, int m, int e)
{
}

void merge(vector<int> &nums, int s, int m, int e)
{
	int size1 = m-s + 1;
	int size2 = e-m;
	int i,j;
	vector<int> L(size1);
	vector<int> R(size2);

	for(i=0; i<size1; i++)
		L[i] = nums[i + s];
	for(j=0; j<size2; j++)
		R[j] = nums[j+m+1];
	int idx=s;
	i=0,j=0;
	while(i<size1 && j<size2)
	{
		if(L[i]<R[j])
		{
			nums[idx++] = L[i];
			i++;
		} else 
		{
			nums[idx++] = R[j];
			j++;
		}
	}

	while(i<size1)
		nums[idx++] = L[i++];

	while(j<size2)
		nums[idx++] = R[j++];
}

void mergeSort(vector<int> &nums, int s, int e)
{
	if(s<e)
	{
		int mid = s+(e-s)/2;
		mergeSort(nums, s, mid);
		mergeSort(nums, mid+1, e);
		merge(nums, s, mid, e);
	}
}

vector<int>& sort(vector<int>& nums)
{
	quickSort(nums, 0, nums.size()-1);
    return nums;
}

void testCase()
{
	int a[] = {3,9,5,2,6,7,1,8};
	vector<int> nums(a, a + (sizeof a / sizeof a[0]));
	printVector( sort(nums));
	int a1[] = { 0,1,0,1,0,1,0,1};
	vector<int> nums1(a1, a1 + (sizeof a1 / sizeof a1[0]));
	printVector( sort(nums1));
	int a2[] = {-1,-2,1,13,0,0,-23};
	vector<int> nums2(a2, a2 + (sizeof a2 / sizeof a2[0]));
	printVector( sort(nums2));
	//cout<<solve("aaabccddd")<<endl;
	//cout<<solve("baab")<<endl;
	//cout<<solve("bb")<<endl;
}
//////////////////////////////////////////////////////////////////////  0 1 1 2 3 5 8 13 21 34
int _tmain(int argc, _TCHAR* argv[])
{
	testCase();
	system("pause");
}
