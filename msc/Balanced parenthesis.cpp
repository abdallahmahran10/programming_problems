// playground.cpp : Defines the entry point for the console application.
//
#include "stdafx.h"
#include "common.h" // my defined macros
/*
Balanced parenthesis

Create function that will determine are the parenthesis balanced in a given string
boolean isBalanced(string)

a(bcd)d => true
(kjds(hfkj)sdhf => false
(sfdsf)(fsfsf => false

{[]}() => true
{[}] => false
*/

bool isOpenParenthesis(char ch)
{
	return ch == '(' || ch == '{' || ch == '[' ;
}

bool isCloseParenthesis(char ch)
{
	return ch == ')' || ch == '}' || ch == ']' ;
}

bool isPair(char ch1, char ch2)
{
	if(ch1 == '{' && ch2 == '}')
		return true;
	else if(ch1 == '(' && ch2 == ')')
		return true;
	else if(ch1 == '[' && ch2 == ']')
		return true;
	return false;
}

bool isBalancedParenthesis(string exp) 
{
	int len = exp.length();
	if(len<1)
		return true;
	stack<char> st; 
	F(len)
	{
		char ch= exp[i];
		if(isOpenParenthesis(ch))
			st.push(ch);
		else 
		{
			if(isCloseParenthesis(ch))
			{
				if(st.empty() || !isPair(st.top(), ch))
					return false;
				st.pop();
			}
		}
	}
	return st.empty();
}

bool testCase0()
{
	string exp= "a(bcd)d";
	return isBalancedParenthesis(exp);
}

bool testCase1()
{
	string exp= "(kjds(hfkj)sdhf";
	return isBalancedParenthesis(exp);
}

bool testCase2()
{
	string exp= "(sfdsf)(fsfsf";
	return isBalancedParenthesis(exp);
}

bool testCase3()
{
	string exp= "{[]}()";
	return isBalancedParenthesis(exp);
}

bool testCase4()
{
	string exp= "{[}]";
	return isBalancedParenthesis(exp);
}

bool testCase5()
{
	string exp= "[faef[)asdfljnsf(]asfmlkn]";
	return isBalancedParenthesis(exp);
}