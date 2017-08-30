/*
	Author: Abdallah Mahran
	Ref: https://leetcode.com/problems/hamming-distance/description/
	Date: 8/30/2017
*/

// Includes
#include "../common.h"
// Types
// Functions
// Test cases

int hammingDistance(int x ,int y)
{
	int xorxy=x^y;
	int hammingDistance = 0;
	while (xorxy)
	{
		hammingDistance+=xorxy & 1;
		xorxy>>=1;
	}
	return hammingDistance;
}
void testCase()
{

	cout<<hammingDistance(1,4)<<endl; 
	cout<<"done"<<endl; 
}
