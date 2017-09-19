/*
	Author: Abdallah Mahran
	Ref: https://leetcode.com/problems/linked-list-cycle
	Date: 9/19/2017
*/

// Includes
#include "../common.h"
// Types
// Functions

// Solution 1
bool hasCycle(ListNode *head) {
  if(head == NULL || head->next == NULL)
    return false;
  ListNode *slider = head, *fastSlider = head;

  while (slider!=NULL && fastSlider!=NULL && fastSlider->next !=NULL)
  {
     slider = slider->next;
     fastSlider = fastSlider->next->next;
     if(slider == fastSlider)
       return true;
  }
  return false;
}

// Solution 2
bool hasCycle2(ListNode *head) {
  if(head == NULL || head->next == NULL)
    return false;
  ListNode *slider = head;
  unordered_map<ListNode *, bool> hm;
  while (slider)
  {
    if(slider->next!=NULL && hm[slider->next])
      return true;
    hm[slider] = true;
    slider = slider->next;
  }
  return false;
}
