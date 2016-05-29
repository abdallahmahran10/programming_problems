#include "common.h" // my defined macros
// 44 ms answer
// Definitions
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

struct compare {
    bool operator ()(const ListNode *l1, const ListNode *l2) {
        return l1->val > l2->val;
    }
};
// Implmentation 
ListNode* mergeKLists(vector<ListNode*>& lists)
{
    int k =lists.size();
    if(k == 1)
        return lists[0];
	priority_queue<int, std::vector<ListNode*>, compare> queue;
	//
	F(lists.size())
		if(lists[i] != NULL)
			queue.push(lists[i]);
	//
	ListNode* head= new ListNode(0);
	ListNode* slider = head;
	while(!queue.empty())
	{
		slider->next = queue.top();
		queue.pop();
		slider = slider->next;
		
		if(slider->next != NULL)
			queue.push(slider->next);
	}
	return head->next;
}

// test cases

ListNode* testCase0()
{
    vector<ListNode*> lists;
    // list 1
    ListNode* head1=new ListNode(1);
    head1->next=new ListNode(3);
    // list 2
    ListNode* head2=new ListNode(2);
    head2->next=new ListNode(4);
    //
    lists.push_back(head1);
    lists.push_back(head2);
    return mergeKLists(lists);
}
ListNode* testCase1()
{
    vector<ListNode*> lists;
    // list 1
    ListNode* head1=new ListNode(0);
    head1->next=new ListNode(1);
    //
    lists.push_back(head1);
    return mergeKLists(lists);
}
ListNode* testCase2()
{
    vector<ListNode*> lists;
    // list 1
    ListNode* head1=new ListNode(1);
    // list 2
    ListNode* head2=new ListNode(0);
    //
    lists.push_back(head1);
    lists.push_back(head2);
    return mergeKLists(lists);
}
ListNode* testCase3()
{
    vector<ListNode*> lists;
    // list 1
    ListNode* head1=new ListNode(1);
    // list 2
    ListNode* head2=new ListNode(0);
    //
    lists.push_back(NULL);
    lists.push_back(head1);
    return mergeKLists(lists);
}
ListNode* testCase4()
{
    //Input: [[1,2,2],[1,1,2]]
    //Output: [1,1,1,2,2,2]
    vector<ListNode*> lists;
    // list 1
    ListNode* head1=new ListNode(1);
    head1->next=new ListNode(2);
    head1->next->next=new ListNode(2);
    // list 2
    ListNode* head2=new ListNode(1);
    head2->next=new ListNode(1);
    head2->next->next=new ListNode(2);
    //
    lists.push_back(head1);
    lists.push_back(head2);
    return mergeKLists(lists);
}
ListNode* testCase5()
{
    //Input: [[1,2,3],[4,5,6,7]]
    //Output: [1,2,3,4,5,6,7]
    vector<ListNode*> lists;
    // list 1
    ListNode* head1=new ListNode(1);
    head1->next=new ListNode(2);
    head1->next->next=new ListNode(3);
    // list 2
    ListNode* head2=new ListNode(4);
    head2->next=new ListNode(5);
    head2->next->next=new ListNode(6);
    head2->next->next->next=new ListNode(7);
    //
    lists.push_back(head1);
    lists.push_back(head2);
    return mergeKLists(lists);
}

//
//////////////////////////////////////////////////////////////////////
int _tmain(int argc, _TCHAR* argv[])
{
	testCase0();
	system("pause");
}

