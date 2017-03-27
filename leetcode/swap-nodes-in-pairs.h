/*
	Author: Abdallah Mahran
	Ref: https://leetcode.com/problems/swap-nodes-in-pairs
	Date: 3/27/2017
*/

// Includes
#include "../common.h"
// Functions
ListNode* swapPairs(ListNode* head) {   
      if (head == NULL || head->next == NULL)
        return head;
      ListNode* tmp1 = head;
      ListNode *tmp2= head->next, *prev;
      tmp1->next = tmp2->next;
      tmp2->next = head;
      head = tmp2;
      prev = tmp1;
      while (prev->next)
      {
        tmp1 = prev->next;
        tmp2= tmp1->next;
        if(tmp2)
        {
            tmp1->next = tmp2->next;
            tmp2->next = tmp1;
            prev->next = tmp2;
        }
        prev = tmp1;
      }
      return head;
}
