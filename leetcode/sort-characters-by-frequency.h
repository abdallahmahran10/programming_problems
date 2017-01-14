/*
	Author: Abdallah Mahran
	Ref: https://leetcode.com/problems/sort-characters-by-frequency/
	Date: 1/14/2017
*/

// Includes
#include "common.h"
// Types

class Char
{
public:
	int idx;
	int count;
	Char(int i):idx(i), count(0){}
	bool operator > (const Char& rhs) const
	{
		return count > rhs.count;
	}
	bool operator < (const Char& rhs) const
	{
		return count < rhs.count;
	}
	void advanceCounter() {count++;}

};
// Functions

string frequencySort(string s) {
	if(s.size() < 3)
		return s;
	vector<Char> chs;
	string result;
	for(int i=0; i<256; i++)
		chs.push_back(Char(i));

	for(int i=0; i<s.length(); i++)
		chs[s[i]].advanceCounter();

	sort(chs.rbegin(), chs.rend());
	for(int i=0; chs.size(); i++)
		if(chs[i].count)
			result.append(string(chs[i].count,chs[i].idx));
		else 
			break;
	return result;
}
// Test cases

void testCase()
{
	cout<<frequencySort("Aabb")<<endl;
	cout<<frequencySort("tree")<<endl;
	cout<<frequencySort("cccaaa")<<endl;
}
