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
    int x=0,y=0;
	for(int i=0; i<moves.length(); i++)
	{		
		switch (moves[i])
		{
			case 'U': y++;break;
			case 'D': y--;break;
			case 'R': x++;break;
			case 'L': x--;break;
			default:
				break;
		}
	}
	return x==0 && y==0;
}

// Test cases

void testCase()
{

	cout<<judgeCircle("UDRDLU")<<endl; 
	cout<<"done"<<endl; 
}
