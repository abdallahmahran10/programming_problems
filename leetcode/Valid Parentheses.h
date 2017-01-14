/*
	Author: Abdallah Mahran
	Ref: https://leetcode.com/problems/valid-parentheses/
	Date: 1/13/2017
*/

// Includes
#include "common.h"
// Types
// Functions
bool isValid(string s) {
	if(s.empty())
		return false;
	stack<char> brackets;
	for(int i=0; i<s.length(); i++)
	{
		char ch = s[i];
		if(ch == '}')
		{ 
			if(brackets.size() == 0 || brackets.top() != '{')
				return false;
			else 
				brackets.pop();
			continue;
		}
		else if(ch == ']' )
		{ 
			if(brackets.size() == 0 || brackets.top() != '[')
				return false;
			else 
				brackets.pop();
			continue;
		}
		else  if(ch == ')')
		{ 
			if(brackets.size() == 0 || brackets.top() != '(')
				return false;
			else 
				brackets.pop();
			continue;
		}
		brackets.push(ch);
	}
	return brackets.size() == 0;
}

// Test cases
void testCase()
{
	cout<<isValid("()[]{}")<<endl;
	cout<<isValid("(]")<<endl;
	cout<<isValid("([)]")<<endl;
	cout<<isValid("()")<<endl;
	cout<<isValid("]")<<endl;
}
