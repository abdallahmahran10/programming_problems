// playground.cpp : Defines the entry point for the console application.
//
#include "stdafx.h"
#include "../common.h" // my defined macros
#include "BST.h"
#include "Graph.h"
#include "Trie.h"
#include "Queue.h"
#include "Heap.h"
#include "sorters.h"

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
void permute(string s, int l, int r)
{
   cout<<"ip="<<s<<" L:"<<l<<" R:"<<r<<endl;
   int i;
   if (l == r)
     cout<<">>>>>>>>>>>>>>>>>>..."<<s<<endl;
   else
   {
       for (i = l; i <= r; i++)
       {
          swap(s[l], s[i]);
          permute(s, l+1, r);
          swap(s[l], s[i]); //backtrack
       }
   }
}

template<typename T1, typename T2>
void pr(T1 a, T2 b)
{
	cout<<a<<endl;
	cout<<b<<endl;
}

void best_hotels() {

}

void testCase()
{
	//int a[]={2,3,4,8};
	//ivector v = TO_VECTOR(a);
//	cout<<pathSum(&r, 8)<<endl;
	int a=1; pr(a,a+1);
	cout<<"done"<<endl; 
}
//////////////////////////////////////////////////////////////////////  0 1 1 2 3 5 8 13 21 34
int _tmain(int argc, _TCHAR* argv[])
{
	testCase();
	system("pause");
}
