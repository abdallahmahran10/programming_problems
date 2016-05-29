// playground.cpp : Defines the entry point for the console application.
//
#include "stdafx.h"
#include "common.h" // my defined macros

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
/////////////////////////////// LEETCODE ////////////////////////////////
// Definitions
struct RandomListNode {
	int label;
	RandomListNode *next, *random;
	RandomListNode(int x) : label(x), next(NULL), random(NULL) {}
};
//
RandomListNode *deepCopyNode(RandomListNode *node, map<int, RandomListNode *>& copiedValues )
{
	RandomListNode *retNode;
	if(copiedValues.count(node->label) != 0)
		return copiedValues[node->label];
	//
	retNode = new RandomListNode(node->label);
	copiedValues[node->label] = retNode;
	//
	if(node->next != NULL)
		retNode->next = deepCopyNode(node->next, copiedValues);
	if(node->random != NULL)
		retNode->random = deepCopyNode(node->random, copiedValues);
	return retNode;
}
// solution
RandomListNode *copyRandomList(RandomListNode *head) 
{
	if( head == NULL)
		return NULL;
	map<int , RandomListNode *> copiedValues;
	RandomListNode *retList;
	retList = deepCopyNode(head, copiedValues);
	return retList;
}
// test cases
void testCase0()
{
	RandomListNode *head = NULL;
	head = new RandomListNode(1);

	head->next = new RandomListNode(2);
	/*random of node 1*/ head->random = head->next/*node 2*/;
	/*random of node 2*/ head->next->random = head /*node 1*/;
	RandomListNode *result = copyRandomList(head);
}
//
void testCase1()
{
	RandomListNode *head = NULL;
	head = new RandomListNode(1);

	head->next = new RandomListNode(2);
	head->next->next = new RandomListNode(3);
	head->next->next->next  = new RandomListNode(4);
	head->next->next->next->next = new RandomListNode(5);
	/*random of node 1*/ head->random = head->next->next /*node 3*/;
	/*random of node 2*/ head->next->random = head /*node 1*/;
	/*random of node 3*/ head->next->next->random  = head->next->next->next->next /*node 5*/;
	/*random of node 4*/ head->next->next->next->random =  head->next->next /*node 3*/;
	/*random of node 5*/ head->next->next->next->next->random = head->next /*node 2*/;
	RandomListNode *result = copyRandomList(head);
}
//
void testCase2()
{
	RandomListNode *head = NULL;
	head = new RandomListNode(1);
	RandomListNode *result = copyRandomList(head);
}
//
//////////////////////////////////////////////////////////////////////
int _tmain(int argc, _TCHAR* argv[])
{
	testCase2();
	system("pause");
}

