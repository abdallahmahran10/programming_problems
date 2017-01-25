/*
	Author: Abdallah Mahran
	Ref: https://leetcode.com/problems/valid-anagram/
	Date: 1/24/2017
*/

// Includes
#include "common.h"
// Functions
bool isAnagram(string s, string t) {
	char chs[256] = {};
	for (int i = 0; i < s.size(); i++)
		chs[(int)(s[i] - 'a')]++;
	for (int i = 0; i < t.size(); i++)
		chs[(int)(t[i] - 'a')]--;
	for (int i = 0; i < 256; i++)
	{
		if (chs[i] != 0)
			return false;
	}
	return true;
}
