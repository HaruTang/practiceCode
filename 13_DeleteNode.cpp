// O(1)删除节点.如果只有一个节点,那么需要删除头节点,所以必须传递引用进来

#include <iostream>
using namespace std;

struct ListNode
{
	int data;
	ListNode* next;
};

void DeleteNode(ListNode*& head,ListNode*del)
{
	if(head==NULL||del==NULL)
		return;

	// 不是尾
	if(del->next!=NULL)
	{
		swap(del->data,del->next->data);
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
		while(head->next!=del)
			head = head->next;
		
		head->next = del->next;
		delete del;
		del = NULL;
	}
}

int main(int argc, char const *argv[])
{
	
	return 0;
}