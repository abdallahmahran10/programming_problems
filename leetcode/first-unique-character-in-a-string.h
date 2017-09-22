#include "common.h" // my defined macros

// https://leetcode.com/problems/first-unique-character-in-a-string/

int firstUniqChar(string s)
{
	int result = -1;
	int len = s.length();	
	bool isChartNotUniq;
	char ch;
	for(int i=0; i<len; i++)
	{ 
		bool isChartNotUniq = false;
		ch = s[i];
		if(ch == -1)
			continue;
		for(int j= i+1; j<len; j++)		
			if(ch==s[j])
			{
				s[j] = -1;	
				isChartNotUniq = true;
			}
		if(!isChartNotUniq)
		{
			result = i;
			break;
		}
	}
	return result;
}
// better slution
int firstUniqChar1(string s) 
{
	int count[256]={0};
	for(int i=0; i <s.length(); i++)
	    count[s[i]]++;
	for(int i=0; i <s.length(); i++)
	    if(count[s[i]]<2)
		return i;
	return -1;
}
//
int testCase0()
{
	string s = "leetcode";
	return firstUniqChar(s);
}
int testCase1()
{
	string s = "loveleetcode";
	return firstUniqChar(s);
}
int testCase2()
{
	string s = "l";
	return firstUniqChar(s);
}
int testCase3()
{
	string s = "ls";
	return firstUniqChar(s);
}
int testCase4()
{
	string s = "ll";
	return firstUniqChar(s);
}
int testCase5()
{
	string s = "aadadaad";
	return firstUniqChar(s);
}
