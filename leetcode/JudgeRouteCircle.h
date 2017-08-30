/*
	Author: Abdallah Mahran
	Ref: https://leetcode.com/problems/judge-route-circle/description/
	Date: 8/30/2017
*/

// Includes
#include "../common.h"
// Types
// Functions
bool judgeCircle(string moves) {
	char countMoves[256]={0};
	for(int i=0; i<moves.length(); i++)
		countMoves[moves[i]]++;
	return (countMoves['U'] == countMoves['D']) && (countMoves['R'] == countMoves['L']);
}

// Test cases

void testCase()
{

	cout<<judgeCircle("UDRDLU")<<endl; 
	cout<<"done"<<endl; 
}
