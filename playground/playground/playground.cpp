// playground.cpp : Defines the entry point for the console application.
//
#include "stdafx.h"
#include "../common.h" // my defined macros
#include "BST.h"
#include "Graph.h"
#include "Trie.h"

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

    ListNode* addToFront( int val, ListNode* p ){
    	ListNode* digit = new ListNode(val);
    	digit->next = p;
    	return digit;
    }
    
ListNode* addTwoNumbers(ListNode* d1, ListNode* d2, unsigned char *carry) {
    if(d1->next == NULL || d2->next == NULL )
    {
    	*carry = 0;
    	unsigned char sum = d1->val + d2->val;
    	*carry = sum /10;
    	ListNode* digit = new ListNode(sum%10);
    	return digit;
    }
    ListNode* p = addTwoNumbers(d1->next, d2->next, carry);
    unsigned char sum = d1->val + d2->val + *carry;
    *carry = sum /10;
    return addToFront(sum%10, p);
}
ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
	ListNode* slider,*p;
	size_t n1=0,n2=0, i;
	unsigned char carry;
	for(slider = l1;slider!=NULL; slider= slider->next)
		n1++;
	slider = l2;
	for(slider = l2;slider!=NULL; slider= slider->next)
		n2++;
	if(n1>n2)
    	for(i=0;i<n1-n2; i++)
    		l2 = addToFront(0 , l2);
	else if(n2>n1)
    	for(i=0;i<n2-n1; i++)
    		l1 = addToFront(0 , l1);
	printLL(l1);
	printLL(l2);
    p = addTwoNumbers(l1, l2, &carry);
	if(!carry)
		return p;
	ListNode* digit = new ListNode(carry);
	digit->next = p;
	return digit;
}
//
void testCase()
{
	int a1[] = {9,9,9};
	int a2[] = {1,9,9,9};
	ListNode *head1 = toLL(a1, ARRAY_SIZE(a1));
	ListNode *head2 = toLL(a2, ARRAY_SIZE(a2));
	printLL(addTwoNumbers(head1, head2));
	cout<<"********************************"<<endl;
}
void testCase1()
{
	int a1[] = {9,0};
	int a2[] = {1};
	ListNode *head1 = toLL(a1, ARRAY_SIZE(a1));
	ListNode *head2 = toLL(a2, ARRAY_SIZE(a2));
	printLL(addTwoNumbers(head1, head2));
	cout<<"********************************"<<endl;
}
void testCase2()
{
	int a1[] = {9};
	int a2[] = {1};
	ListNode *head1 = toLL(a1, ARRAY_SIZE(a1));
	ListNode *head2 = toLL(a2, ARRAY_SIZE(a2));
	printLL(addTwoNumbers(head1, head2));
	cout<<"********************************"<<endl;
}
void testCase3()
{
	int a1[] = {0};
	int a2[] = {1};
	ListNode *head1 = toLL(a1, ARRAY_SIZE(a1));
	ListNode *head2 = toLL(a2, ARRAY_SIZE(a2));
	printLL(addTwoNumbers(head1, head2));
	cout<<"********************************"<<endl;
}
void testCase4()
{
	int a1[] = {9,9,9,9};
	int a2[] = {9,9,9,9,9,9,9,9};
	ListNode *head1 = toLL(a1, ARRAY_SIZE(a1));
	ListNode *head2 = toLL(a2, ARRAY_SIZE(a2));
	printLL(addTwoNumbers(head1, head2));
	cout<<"********************************"<<endl;
}
//////////////////////////////////////////////////////////////////////  0 1 1 2 3 5 8 13 21 34
int _tmain(int argc, _TCHAR* argv[])
{
	testCase4();
	testCase();
	testCase1();
	testCase2();
	testCase3();
	system("pause");
}
