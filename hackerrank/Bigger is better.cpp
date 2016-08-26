// playground.cpp : Defines the entry point for the console application.
//
#include "stdafx.h"
#include "common.h" // my defined macros
/*
Source: hackerrank
https://www.hackerrank.com/challenges/bigger-is-greater
*/

int main() {
	#ifdef LOCAL
		freopen("input.txt", "r", stdin);
		freopen("output.txt", "w", stdout);        
	#endif
	IN(tc);
	string word;
	getline(cin, word);
	while(tc--)
	{
		getline(cin, word);
        if(next_permutation(word.begin(), word.end()))
			PRINT_STR(word);
		else 
			PRINT_STR("no answer");
    }
    return 0;
}
