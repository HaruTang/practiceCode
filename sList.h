#include <iostream> 
using namespace std;

struct ListNode
{
	ListNode(const int& x)
	:value(x)
	,next(NULL)
	{}

	int value;
	ListNode* next;
};

struct List
{
	List()
	:head(NULL)
	{
		for(int i = 0;i < 10;++i)
		{
			insert(i);
		}

		Print();
	}
	ListNode* find(const int& x)const
	{

		ListNode*cur = head;
		while(cur)
		{
			if(cur->value==x)
				return cur;
			cur	= cur->next;
		}
		return NULL;
	}
	void Print()
	{
		ListNode* cur = head;
		while(cur!=NULL)
		{
			cout << cur->value<<" ";
			cur = cur->next;
		}
		cout << endl;
	}
	void insert(const int& x)
	{
		if(head == NULL)
		{
			head = new ListNode(x);
		}
		else
		{
			ListNode*tail = head;
			while(tail->next!=NULL)
			{
				tail = tail->next;
			}
			tail->next = new ListNode(x);
		}
	}
	ListNode* head;
};

List l;


int test()
{
	return 0;
}