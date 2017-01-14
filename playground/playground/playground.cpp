// playground.cpp : Defines the entry point for the console application.
//
#include "stdafx.h"
#include "common.h" // my defined macros
#include "BST.h"
#include "Graph.h"

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

int titleToNumber(string s) {
	if(s.empty())
		return 0;
	int number=0;
	for(int i=0; i<s.length(); i++)
	{
		number+= s[0] - 'A' + 1;
	}
	return number;
}

string convertToTitle(int n) {
    if(n < 1)
        return "";
    int tmp = n;
    string ret;
	int count=0;
	while(tmp/26 != 0)
	{
		if(tmp/26 > 26)
			count++;
		tmp/=26;
	}
	//
    while(count/26 !=0)
	{		
		ret.push_back('Z');
		count/=26;
	}//
	if(tmp != n)
        ret.push_back((char)(tmp%26 + 64));
    if(n%26)
        ret.push_back((char)(n%26 + 64));
    return ret;
}

void testCase()
{

	cout<<convertToTitle(485)<<endl;
	//Graph<int> graph;
	//graph.addNode(4);
	//graph.addNode(3);
	//graph.addEdgeByNodesData(4,3);
}
//////////////////////////////////////////////////////////////////////  0 1 1 2 3 5 8 13 21 34
int _tmain(int argc, _TCHAR* argv[])
{
	testCase();
	system("pause");
}
