/*
	Author: Abdallah Mahran
	Ref: https://leetcode.com/problems/keyboard-row/description/
	Date: 9/3/2017
*/

// Includes
#include "../common.h"
// Types
// Functions
bool inOneKeybowardRow(string word) 
{
	int row1[256]={0}, row2[256]={0}, row3[256]={0};
	row1['q'] = row1['w'] = row1['e'] = row1['r'] = row1['t'] = row1['y'] = row1['u'] = row1['i'] = row1['o'] =row1['p']=
	row1['Q'] = row1['W'] = row1['E'] = row1['R'] = row1['T'] = row1['Y'] = row1['U'] = row1['I'] = row1['O'] =row1['P']=1;
	row2['a'] = row2['s'] = row2['d'] = row2['f'] = row2['g'] = row2['h'] = row2['j'] = row2['k'] = row2['l']=
	row2['A'] = row2['S'] = row2['D'] = row2['F'] = row2['G'] = row2['H'] = row2['J'] = row2['K'] = row2['L']=1;
	row3['z'] = row3['x'] = row3['c'] = row3['v'] = row3['b'] = row3['n'] = row3['m']=
	row3['Z'] = row3['X'] = row3['C'] = row3['V'] = row3['B'] = row3['N'] = row3['M']=1;
	bool inRow1=false, inRow2=false, inRow3=false;
	for(int i=0; i<word.size(); i++)
	{
		inRow1 |= row1[word[i]];
		inRow2 |= row2[word[i]];
		inRow3 |= row3[word[i]];
		if((inRow1&&inRow2) || (inRow1&&inRow3) ||(inRow3&&inRow2))
			return false;
	}
	return true;
}

vector<string> findWords(vector<string>& words) 
{
	vector<string> ret;
	for(int i=0; i<words.size(); i++)
	{
		if(inOneKeybowardRow(words[i]))
			ret.push_back(words[i]);
	}
	return ret;
}
// Test cases
