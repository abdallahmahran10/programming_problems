// playground.cpp : Defines the entry point for the console application.
//
#include "stdafx.h"
#include "common.h" // my defined macros
/*
Source: Interviewbit
Category: Programming/Arrays/Array Bug
https://www.interviewbit.com/problems/array_bug/
*/

vector<int> rotateArray(vector<int> &A, int B) {
	vector<int> ret; 
	if(B>A.size())
		B=B%A.size();
	FT(B,A.size()) 
	{
		ret.push_back(A[k]);
	}
	F(B)
	{
		ret.push_back(A[i]);
	}
	return ret; 
}
//
vector<int> testCase0()
{
	int x[] = {14, 5, 14, 34, 42, 63, 17, 25, 39, 61, 97, 55, 33, 96, 62, 32, 98, 77, 35};
	vector<int> a(x, x + sizeof x / sizeof x[0]);
	return rotateArray(a, 56);
}