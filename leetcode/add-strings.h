
/*
	Author: Abdallah Mahran
	Ref: https://leetcode.com/problems/add-strings/
	Date: 1/14/2017
*/

// Includes
#include "common.h"
// Types
// Functions
char add (char digit1, char digit2, char *carry)
{
	int ret = (digit1-'0')+ (digit2-'0') + *carry;
	if(ret>9) 
	{
		ret-=10; 
		*carry = 1;
	} 
	else 
		carry=0;
	return  (char)(ret + '0') ;
}

string addStrings(string num1, string num2) {
	string result = "";
	char carry = 0;
	int i= num1.size()-1, j=num2.size()-1;
	for(; i>=0 && j>=0; i--,j--)
	{
		result = add(num1[i], num2[j], &carry) + result;
	}
	while(i>=0)
	{
		result = add(num1[i--], '0', &carry) + result;
	}
	while(j>=0)
	{
		result = add(num2[j--], '0', &carry) + result;
	}
	return result;
}

// Test cases
