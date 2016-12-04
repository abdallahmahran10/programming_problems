#include "common.h" // my defined macros

// https://leetcode.com/problems/reverse-string/
string reverseString(string s) {
	int len =s.length();
	if(len < 2) 
		return s;
	string retStr(len, '\0');
	for(int i=1;i<=len;i++)
		retStr[len-i] = s[i-1];
	return retStr;
}

string testCase0()
{
	return reverseString("Mugestu");
}