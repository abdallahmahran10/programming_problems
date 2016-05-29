#include <iostream>
#include <vector>
using namespace std;
// 550 ms answer
// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

ListNode* mergeTwoLists(ListNode** list1, ListNode* list2)
{
    ListNode* slider1 = *list1;
    ListNode* slider2 = list2;
    if(list2 == NULL)
        return *list1;
    if(*list1 == NULL)
        return list2;
    ListNode* prevSlider;
    ListNode* tmpSlider;
    prevSlider = NULL;
    while(slider2!= NULL)
    {
        while(slider1 != NULL && slider1->val <= slider2->val)
        {
            prevSlider = slider1;
            slider1 = slider1->next;
        }
        if(prevSlider == NULL)
            *list1 = slider2;
        else
            prevSlider->next = slider2;
        tmpSlider = prevSlider = slider2;
        slider2 = slider2->next;
        tmpSlider->next = slider1;
    }
    return *list1;
}
//
ListNode* mergeListsRec(vector<ListNode*>& lists, int pos)
{
    if(pos == lists.size())
        return NULL;
    ListNode* list1 = lists[pos];
    ListNode* list2 = mergeListsRec(lists, pos+1);
    return mergeTwoLists(&list1, list2);
}
//
ListNode* mergeKLists(vector<ListNode*>& lists)
{
    int k =lists.size();
    if(k == 1)
        return lists[0];
    return mergeListsRec(lists, 0);
}

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

int main()
{
    ListNode *result = testCase5();
    return 0;
}

