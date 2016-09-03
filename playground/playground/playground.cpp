// playground.cpp : Defines the entry point for the console application.
//
#include "stdafx.h"
#include "common.h" // my defined macros

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

#define RED 0
#define WHITE 1
#define BLUE 2

// Spiral Order Matrix I
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
//////////////////////////////////////////////////////////////////////
int _tmain(int argc, _TCHAR* argv[])
{
	PRINT_INT(testCase0());
	//PRINT_INT(testCase1());
	//PRINT_INT(testCase2());
	//PRINT_INT(testCase3());
	//PRINT_INT(testCase4());
	//printVector(testCase1()); 
	//printVector(testCase2()); 
	//printVector(testCase3()); 
	//printVector(testCase4()); 
	//printVector(testCase5()); 
	//printVector(testCase6()); 
	//printVector(testCase7()); 
	system("pause");
}
