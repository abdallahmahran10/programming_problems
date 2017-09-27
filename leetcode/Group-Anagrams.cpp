/*
	Author: Abdallah Mahran
	Ref: https://leetcode.com/problems/anagrams/
	Date: 1/25/2017
*/

// Includes
#include "../common.h"
class Solution {
    
void strSort(string& s) {
	if(s.empty())
		return;
	int chars[26]={0};
	for(int i=0; i < s.size(); i++)
		chars[(int)s[i]-(int)'a']++;
	int k=0;
	for(int i=0; i<26; i++)
	{
		for(int j=0; j<chars[i]; j++)
			s[k++] = i + (int)'a';
	}
}
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> res;
        if(strs.empty())
            return res;

        map<string, vector<string>> m;
        for(int i=0; i<strs.size(); i++)
        {
            string str(strs[i]);
            strSort(str);
            m[str].push_back(strs[i]);
        }
    	
    	map<string, vector<string>>::iterator it = m.begin();
        for(; it != m.end(); it++) 
			res.push_back(vector<string>(it->second.begin(), it->second.end()));

        return res;
    }
};
