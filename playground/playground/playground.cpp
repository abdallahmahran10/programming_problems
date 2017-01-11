// playground.cpp : Defines the entry point for the console application.
//
#include "stdafx.h"
#include "common.h" // my defined macros
#include "BST.h"
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


void testCase()
{
	int a[] = {3,9,5,2,6,7,1,8};
	vector<int> nums(a, a + (sizeof a / sizeof a[0]));
	int apre[] ={ 5,2, 1, 3, 7, 6, 8, 9 };
	int ain[] ={  1, 2, 3, 5, 6, 7, 8, 9 };
	vector<int> pre(apre, apre + (sizeof apre / sizeof apre[0]));
	vector<int> in(ain, ain + (sizeof ain / sizeof ain[0])); 


	BST<int> bst1 = BST<int>::CreateBSTFromPreorderAndInorder(pre, in);
	//BST<int> bst = BST<int>::CreateBST(nums, false);
	printVector(nums);
	bst1.preOrderPrint();
	bst1.inOrderPrint();
	//cout<<solve("aaabccddd")<<endl;
	//cout<<solve("baab")<<endl;
	//cout<<solve("bb")<<endl;
}
//////////////////////////////////////////////////////////////////////  0 1 1 2 3 5 8 13 21 34
int _tmain(int argc, _TCHAR* argv[])
{
	testCase();
	system("pause");
}
