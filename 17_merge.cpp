#include <iostream>
#include "sList.h"
using namespace std;

ListNode* merge(ListNode* h1,ListNode*h2)
{
	if(h1==NULL)
		return NULL;
	else if (h2==NULL)
	{
		return h1;
	}

	ListNode* ret = NULL;

	if(h1->value<h2->value)
	{
		ret = h1;
		ret->next = merge(h1->next,h2); 
	}
	else
	{
		ret = h2;
		ret->next = merge(h1,h2->next);
	}
	return ret;
	
}

int main(int argc, char const *argv[])
{
	List s;
	s.head = merge(s.head,l.head);

	s.Print();
	return 0;
}