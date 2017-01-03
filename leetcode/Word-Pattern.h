/*
	Author: Abdallah Mahran
	Ref: https://leetcode.com/problems/word-pattern/
	Date: 1/3/2017
*/

// Includes
#include "common.h"
// Types
// Functions
bool wordPattern(string pattern, string str) {
	map<string, char> patternMap;
	map<string, char>::iterator it;
	bool arr[256] = {false};
	int patternIdx = 0;
	size_t i = 0, j = 0;
	while (i < str.length() && patternIdx < pattern.length())
	{
		i = str.find(' ', i);
		if (i == std::string::npos)
			i = str.length();
		string tmp = str.substr(j, i-j);
		it = patternMap.find(tmp);
		if (it == patternMap.end())
		{
			if (!arr[pattern[patternIdx]])
			{
				patternMap[tmp] = pattern[patternIdx];
				arr[pattern[patternIdx]] = true;
			}
			else
				return false;
		}
		else if (pattern[patternIdx] != it->second)
		{
			return false;
		}
		patternIdx++;
		j = ++i;
	}
	return patternIdx == pattern.length() && i == str.length() + 1;
}

// Test cases
void testCase0()
{
	cout << wordPattern("abba", "dog cat cat dog") << endl;
	cout << wordPattern("abba", "dog cat cat fish") << endl;
	cout << wordPattern("aaaa", "dog cat cat dog") << endl;
	cout << wordPattern("aaaa", "dog dog dog dog") << endl;
	cout << wordPattern("abba", "dog dog dog dog") << endl;
}
