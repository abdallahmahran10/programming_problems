// playground.cpp : Defines the entry point for the console application.
//
#include "stdafx.h"
#include "../common.h" // my defined macros
#include "BST.h"
#include "Graph.h"
#include "Trie.h"
#include "Queue.h"
#include "Heap.h"

//#include "MaximumAbsoluteDifference.h"
/////////////////////uva problems template /////////////////////
//12356 - Army Buddies
int uva12356()
{
#ifdef LOCAL
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);        
#endif
	// Your code is here //////////////////////////
	
	///////////////////////////////////////////////
#ifdef LOCAL
	fclose (stdout);
#endif
	return 0;
}
///////////////////////
void Main()
{
#ifdef LOCAL
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);        
#endif
	// Implmentation //////////////////////////////
	
	///////////////////////////////////////////////
#ifdef LOCAL
	fclose (stdout);
#endif
}
void printAN(vector<string> words)
{
	F(i)
	{
		sort(words[i].begin(), words[i].end());
	}
	sort(words.begin(), words.end());
	printStringVector(words);
}
int binarySubString(int x, int y, int i, int j)
{
	if(i> j)
		return x;
	while(i--)
	{
		y<<=1;
	}

	return x;
}

void testCase()
{
	MaxHeap<int> h(10);
	h.insert(1);
	h.extractTop();
	h.decreaseKey(1,3);
	auto func = [] () { cout << "Hello world"; };
    func(); // now call the function
	cout<<"done"<<endl;
}
//////////////////////////////////////////////////////////////////////  0 1 1 2 3 5 8 13 21 34
int _tmain(int argc, _TCHAR* argv[])
{
	testCase();
	system("pause");
}
