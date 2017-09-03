/*
	Author: Abdallah Mahran
	Ref: https://leetcode.com/problems/reverse-words-in-a-string-iii/description/
	Date: 3/9/2017
*/

// Includes
#include "../common.h"
// Types
// Functions
string reverseWords(string s) {
        string reversed="";
        int i=0;
        while(i<s.size())
        {
            string word="";
            while (i<s.size() && s[i]!=' ')
                word.insert(word.begin(), s[i++]);
            word.push_back(' ');
            i++;
            reversed.append(word);
        }
        if(!reversed.empty())
            reversed.erase(reversed.size()-1);
        return reversed;
    }  
