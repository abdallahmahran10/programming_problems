// playground.cpp : Defines the entry point for the console application.
//
#include "stdafx.h"
#include "common.h" // my defined macros

// Add One To Number
// https://www.interviewbit.com/problems/add-one-to-number/

vector<int> plusOne(vector<int> &A) {
	vector<int> result= A;
	int carry = 1;
	int i= result.size();
	while(carry && i)
	{
		int sum = result[i-1] + carry; 
		if( sum< 10)
		{
			result[i-1] += carry;
			carry = 0;
		} else 
		{
			result[i-1] = 10 - sum;
			carry = 1 ;
		}
		i--;
	}
	if(carry>0)
		result.insert(result.begin(),carry);
	while (!result[0])
	{
		result.erase(result.begin());
	}

	return result;
}

vector<int > testCase0()
{
	int a[] = {9, 9, 9};
	vector<int> A(a, a + sizeof a / sizeof a[0]);
    //
    return plusOne(A);
}

vector<int > testCase1()
{
	int a[] = {1, 9, 9};
	vector<int> A(a, a + sizeof a / sizeof a[0]);
    //
    return plusOne(A);
}
vector<int > testCase2()
{
	int a[] = {1, 3, 1};
	vector<int> A(a, a + sizeof a / sizeof a[0]);
    //
    return plusOne(A);
}
vector<int > testCase3()
{
	int a[] = {0, 1, 0};
	vector<int> A(a, a + sizeof a / sizeof a[0]);
    //
    return plusOne(A);
}
vector<int > testCase4()
{
	int a[] = {0, 9, 9};
	vector<int> A(a, a + sizeof a / sizeof a[0]);
    //
    return plusOne(A);
}
vector<int > testCase5()
{
	int a[] = {0};
	vector<int> A(a, a + sizeof a / sizeof a[0]);
    //
    return plusOne(A);
}
vector<int > testCase6()
{
	int a[] = {1};
	vector<int> A(a, a + sizeof a / sizeof a[0]);
    //
    return plusOne(A);
}
vector<int > testCase7()
{
	int a[] = {9};
	vector<int> A(a, a + sizeof a / sizeof a[0]);
    //
    return plusOne(A);
}