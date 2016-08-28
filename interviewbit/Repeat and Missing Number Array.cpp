// playground.cpp : Defines the entry point for the console application.
//
#include "stdafx.h"
#include "common.h" // my defined macros

// Repeat and Missing Number Array
// https://www.interviewbit.com/problems/repeat-and-missing-number-array/

unsigned long sumAll(unsigned long n)
{
  return n == 1 ? 1 : sumAll(n - 1) + n;
}

unsigned long fac(unsigned long n)
{
  return n <= 1 ? 1 : fac(n - 1) * n;
}

void solveEquations( int a, int b, unsigned long long e,
    int c,int d,unsigned long long f, int *x, int *y)
{
	/* ax+by=e
     * cx+dy=f
     */
	int determinant = a*d - b*c;
	*x = (e*d - b*f)/determinant;
    *y = (a*f - e*c)/determinant;
}

vector<int> repeatedNumber2(const vector<int> &A) {
	
	vector<int> result;
	unsigned long n = A.size();
	unsigned long largestNum=numeric_limits<unsigned long>::min();
	unsigned long currentSum =0;
	unsigned long currentMul =1;
	int repeatedNum;
	for(int i= 0; i<n; i++)
	{
		largestNum = max(largestNum, (unsigned long)A[i]);
		currentSum += A[i];
		currentMul *= A[i];
	}
	unsigned long sum = sumAll(largestNum);
	unsigned long facN = fac(largestNum);
	// need to check this equation
	int x = (facN + currentSum - sum) / (currentMul -1);
	result.push_back(x);
	// 
	return result;
}
// exceed time limit
vector<int> repeatedNumber1(const vector<int> &A) {
	vector<int> result;
	unsigned long n = A.size();
	unsigned long largestNum=numeric_limits<unsigned long>::min();
	unsigned long currentSum =0;
	int repeatedNum;
	bool _continue =false;
	for(int i= 0; i<n; i++)
	{
		largestNum = max(largestNum, (unsigned long)A[i]);
		currentSum +=A[i];
		if(_continue)
			continue;
		repeatedNum = A[i];
		for(int j= i+1; j<n; j++)
		{
		
			if(repeatedNum == A[j])
			{
				_continue = true;
				break;
			}
		}
	}
	unsigned long sum = sumAll(largestNum);
	//
	result.push_back(repeatedNum);
	currentSum -= (repeatedNum*2);
	sum-=repeatedNum;
	int missingNum = sum-currentSum;
	missingNum = missingNum?missingNum:2;
	result.push_back(missingNum);
	return result;
}

vector<int > testCase0()
{
	int a[] = {3, 1, 2, 5, 3};
	vector<int> A(a, a + sizeof a / sizeof a[0]);
    //
    return repeatedNumber2(A);
}

vector<int > testCase1()
{
	int a[] = {2, 2};
	vector<int> A(a, a + sizeof a / sizeof a[0]);
    //
    return repeatedNumber1(A);
}
vector<int > testCase2()
{
	int a[] = {1, 1};
	vector<int> A(a, a + sizeof a / sizeof a[0]);
    //
    return repeatedNumber1(A);
}
