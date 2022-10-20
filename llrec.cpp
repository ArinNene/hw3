#include "llrec.h"
#include <iostream>

//*********************************************
// Provide your implementation of llpivot below
//*********************************************

void llpivot(Node *&head, Node *&smaller, Node *&larger, int pivot) {
  if (head == nullptr) { //base case: current node is NULL. end of list
		smaller = nullptr;
		larger = nullptr;
		return;
	}
	if (head != nullptr) { 
		llpivot(head->next,smaller,larger,pivot); //head recursion
    if (head->val <= pivot) { //if smaller than pivot, add to smaller list
			head->next = smaller; 
			smaller = head; 
			head = nullptr;
			return;
			} 
		else { //otherwise add node to larger list
			head->next = larger;
			larger = head;
			head = nullptr;
			return;
			}
	}
	
}