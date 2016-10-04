#include <iostream>
#include "sList.h"
using namespace std;

ListNode* reversList(ListNode* head)
{
	ListNode* newHead = NULL;
	while(head)
	{
		ListNode* del = head;
		head = head->next;

		del->next = newHead;
		newHead = del;
	}
	return newHead;
}

int main()
{
	// l.head = NULL;
	l.head = reversList(l.head);
	l.Print();
	return 0;
}