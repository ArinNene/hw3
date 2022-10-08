#include "llrec.h"
#include <iostream>

//*********************************************
// Provide your implementation of llpivot below
//*********************************************

void llpivot(Node *&head, Node *&smaller, Node *&larger, int pivot) {
  if (head == nullptr) {
		smaller = nullptr;
		larger = nullptr;
		return;
	}
	if (head != nullptr) {
		llpivot(head->next,smaller,larger,pivot);
    if (head->val <= pivot) { 
			head->next = smaller; 
			smaller = head; 
			head = nullptr;
			return;
			} 
		else { 
			head->next = larger;
			larger = head;
			head = nullptr;
			return;
			}
	}
	
}