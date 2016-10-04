// O(1)删除节点.如果只有一个节点,那么需要删除头节点,所以必须传递引用进来

#include <iostream>
#include "sList.h"
using namespace std;


void DeleteNode(ListNode*& head,ListNode*del)
{
	if(head==NULL||del==NULL)
		return;

	// 不是尾
	if(del->next!=NULL)
	{
		swap(del->value,del->next->value);
		ListNode*tmp = del->next;
		del->next = tmp->next;

		delete tmp;
		tmp = NULL;	
	}
	else if(head == del)	//是尾,但只有一个节点
	{
		delete del;
		head = NULL;
		del = NULL;
	}

	// 多个节点时,删除尾
	else	
	{
		ListNode* tail = head;
		while(tail->next!=del)
			tail = tail->next;
		
		tail->next = del->next;
		delete del;
		del = NULL;
	}
}

int main(int argc, char const *argv[])
{
	{
		ListNode * del = l.find(0);
		DeleteNode(l.head,del);	
		l.Print();
	}
	{
		ListNode * del = l.find(9);
		DeleteNode(l.head,del);	
		l.Print();
	}
	{
		ListNode * del = l.find(5);
		DeleteNode(l.head,del);	
		l.Print();
	}
	return 0;
}