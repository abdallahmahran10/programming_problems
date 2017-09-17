/*
	Author: Abdallah Mahran
	Ref: https://leetcode.com/problems/intersection-of-two-linked-lists/description/
	Date: 9/17/2017
*/

// Includes
#include "../common.h"
// Types
// Functions

ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
	ListNode *slider = headA;
	int a=0,b=0; 
	while(slider!=NULL)
	{
		slider=slider->next;
		a++;
	}
	slider = headB;
	while(slider!=NULL)
	{
		slider=slider->next;
		b++;
	}
	if(a>b)
	{
		int c = a-b;
		while(c--)
			headA = headA->next;
	}else if(a<b)
	{
		int c = b-a;
		while(c--)
			headB = headB->next;
	}
	while(headA != headB)
	{
		headA= headA->next;
		headB = headB->next;
	}
	return headA;
}
