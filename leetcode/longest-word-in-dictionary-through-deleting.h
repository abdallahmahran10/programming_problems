/*
	Author: Abdallah Mahran
	Ref: https://leetcode.com/problems/longest-word-in-dictionary-through-deleting
	Date: 3/20/2017
*/

// Includes
#include "../common.h"
// Types
class String
{
public:
	string str;
	int s;

	String(string& tmp)
	{
		str = tmp;
		s=str.size();
	}
	//
	bool operator <(const String& rhs) const
	{
		return s < rhs.s;
	}
	//
	bool operator >(const String& rhs) const
	{
		return s > rhs.s;
	}
	//
	bool canYou(string s)
	{
		int i=0, j=0;
		while(i<s.size() && j<str.size())
		{
			if(s[i] == str[j])
			{
				i++; j++;
			} else 
				i++;
		}
		return j == str.size();
	}
};
// Functions
string findLongestWord(string s, vector<string>& d) 
{
	string result; 
	vector<String> heap;
	//sort(s.begin(), s.end());
	for(int i=0; i<d.size(); i++)
	{
		heap.push_back(String(d[i]));
	}
	std::make_heap (heap.begin(),heap.end());
	//

	for(int i=0; i<d.size(); i++)
	{
		if(heap.front().canYou(s)) 
		{
			string e = heap.front().str;
			if(result.empty())
				result = e;
			else if(result.size() <= e.size() && result > e )
				result = e;
		}
		pop_heap (heap.begin(),heap.end()); heap.pop_back();
	}
	//
	return result;
}
// Test cases

void testCase()
{
	string s = "abpcplea";
	string a[] = {"ale","applea","monkey","plea"};
	svector d = TO_SVECTOR(a);

	cout<<findLongestWord(s, d)<<endl;
	cout<<"done"<<endl;
}
void testCase1()
{
	string s = "abpcplea";
	string a[] = {"a","b","c"};
	svector d = TO_SVECTOR(a);

	cout<<findLongestWord(s, d)<<endl;
	cout<<"done"<<endl;
}
