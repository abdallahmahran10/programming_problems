// playground.cpp : Defines the entry point for the console application.
//
#include "stdafx.h"
#include "common.h" // my defined macros
/*
Source: Interviewbit
Category: Programming/Arrays/Array Wave
https://www.interviewbit.com/problems/wave-array/
*/

vector<int> wave(vector<int> &A) {
	if(A.size()<2)
		return A;
	// using default comparison (operator <):
	std::sort (A.begin(), A.end());
	for(int i=0; i<A.size()-1; i+=2)
	{
		iter_swap(next(A.begin(),i), next(A.begin(),i+1));
	}
	return A;
}

vector<int> testCase0()
{
	int a[] = {1, 2, 3, 4};
	vector<int> A(a, a + sizeof a / sizeof a[0]);
	return wave(A);
}