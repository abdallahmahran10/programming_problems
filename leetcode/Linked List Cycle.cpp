#include "common.h" // my defined macros

// https://leetcode.com/problems/linked-list-cycle/

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

bool hasCycle(ListNode *head) {
	if(head == NULL || head->next == NULL)
		return false;
	ListNode *slider = head;
	map<ListNode *, bool> Map;
	while (slider)
	{
		if(Map[slider])
			return true;
		Map[slider] = true;
		slider = slider->next;
	}
	return false;
}
bool testCase0()
{
    ListNode* head=new ListNode(1);
    head->next=new ListNode(3);
    head->next->next=new ListNode(4);
    //
    return hasCycle(head);
}

bool testCase1()
{
    ListNode* head=new ListNode(1);
    head->next=new ListNode(3);
    head->next->next=new ListNode(4);
	head->next->next->next = head;
    //
    return hasCycle(head);
}

bool testCase2()
{
    ListNode* head=new ListNode(1);
    head->next=new ListNode(3);
    head->next->next=new ListNode(4);
	head->next->next->next = head->next;
    //
    return hasCycle(head);
}
bool testCase3()
{
    ListNode* head=new ListNode(1);
    //
    return hasCycle(head);
}

bool testCase4()
{
    ListNode* head=new ListNode(1);
    head->next=new ListNode(3);
    //
    return hasCycle(head);
}