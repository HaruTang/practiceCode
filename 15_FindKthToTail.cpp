#include <iostream>
#include "sList.h"
using namespace std;

ListNode* FindKthToTail(ListNode*head,int n)
{
	if(head == NULL || n <= 0)
		return NULL;
	ListNode* fast = head;
	while(n&&fast)
	{
		fast = fast->next;
		n--;
	}
	if(n>0)
		return NULL;
	while(fast!=NULL)
	{
		fast = fast->next;
		head = head->next;
	}
	return head;
}

int main(int argc, char const *argv[])
{
	for (int i = 0; i < 11; ++i)
	{
		ListNode*f = FindKthToTail(l.head,i);
		if(f)
		{
			cout << f->value<<endl;
		}
		else
			cout << -1 <<endl;
	}
		
	return 0;
}