
#include "stdafx.h"
#pragma once
  
int toInt(char ch)
{
	return ch - '0';
}

void letterCombinationsRec(string &digits, int pos, string dict[], string &comb, vector<string> &lettComb) {
	if(pos == digits.length())
	{
		lettComb.push_back(comb); // calm ur tits its c++ not c#, appending a copy of the string here
		return;
	}
	// here u can use ur string tani yasta
	string curr = dict[toInt(digits[pos])];
	for(int i=0; i <curr.length(); i++)
	{
		comb[pos] = curr[i];
		letterCombinationsRec(digits, pos + 1, dict, comb,lettComb);
	}
}

vector<string> letterCombinations(string digits) {
    vector<string> lettComb;
	if(digits.length() == 0)
		return lettComb;
    string map[] = {" ", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
	string comb;
	for(int i=0; i<digits.length(); i++)
		comb+= ' ';
	letterCombinationsRec(digits, 0, map, comb, lettComb);
	return lettComb;
}
  
vector<string> letterCombinations()
{
	return letterCombinations("239");
}
