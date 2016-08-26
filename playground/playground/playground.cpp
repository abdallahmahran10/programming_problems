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


int maxSubArray(const vector<int> &A) {
	int max_sum = numeric_limits<int>::min(), tmpMax = 0;
	F(A.size())
	{
		tmpMax += A[i];
		max_sum = max(max_sum, tmpMax);
		tmpMax = max(0, tmpMax);
	}
	return max_sum;
}

int testCase0()
{
	int a[] = {-2,1,-3,4,-1,2,1,-5,4};
	vector<int> A(a, a + sizeof a / sizeof a[0]);
	return maxSubArray(A);
}
int testCase1()
{
	int a[] = {-163, -20};
	vector<int> A(a, a + sizeof a / sizeof a[0]);
	return maxSubArray(A);
}
int testCase2()
{
	int a[] = {56, -451, -222, 80, -57, -85, -304, -108, 95, -377, -282, -260, -497, 
		-471, -97, -350, -147, 62, -447, -229, 78, -165, -333, -427, -59, -338, 60, -207, -247, 
		-431, -54, -240, -426, -123, -209, 57, -74, -287, -70, -292, 45, -278, -408, -129, -35, 65, 
		-77, -230, -426, 20, -402, -375, -449, -280, -125, -15, -21, -327, -366, 64, -211, -414, -307};
	vector<int> A(a, a + sizeof a / sizeof a[0]);
	return maxSubArray(A);
}

//////////////////////////////////////////////////////////////////////
int _tmain(int argc, _TCHAR* argv[])
{
	PRINT_INT( testCase1());
	system("pause");
}
