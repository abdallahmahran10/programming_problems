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

//////////////////////////////////////////////////////////////////////
int _tmain(int argc, _TCHAR* argv[])
{
	//cout<<testCase0();
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
