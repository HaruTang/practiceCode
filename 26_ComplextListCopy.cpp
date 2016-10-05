#include <iostream>
using namespace std;

struct complexListNode
{
	complexListNode(const int& n)
	:m_value(n)
	,m_pNext(NULL)
	,m_pSibling(NULL)
	{}



	int m_value;
	complexListNode* m_pNext;
	complexListNode* m_pSibling;
};

struct complexList
{
	complexList()
	:head(NULL)
	{}

	void push(const int& n)
	{
		if(head == NULL)
			head = new complexListNode(n);
		else
		{
			complexListNode*cur = head;
			while(cur->m_pNext)
				cur = cur->m_pNext;
			cur->m_pNext = new complexListNode(n);
		}
	}

	void print()
	{
		complexListNode*cur = head;
		while(cur)
		{
			cout << cur->m_value<<" ";
			if(cur->m_pSibling)
				cout<<cur->m_pSibling->m_value<<endl;
			else
				cout << "NULL"<<endl;
			cur = cur->m_pNext;
		}
	}

	void link(complexListNode*bef,complexListNode*nex)
	{
		bef->m_pSibling = nex;
	}

	complexListNode*head;
};

complexListNode*copy(complexListNode*head)
{
	if(head==NULL)
		return NULL;

	complexListNode*ret = NULL;
	// 插入节点
	complexListNode* cur = head;
	while(cur)
	{
		complexListNode* ins = new complexListNode(cur->m_value);
		ins->m_pNext = cur->m_pNext;
		cur->m_pNext = ins;
		cur = cur->m_pNext->m_pNext;
	}
	cur = head;
	while(cur)
	{
		if(cur->m_pSibling)
		{
			cur->m_pNext->m_pSibling = cur->m_pSibling->m_pNext;
		}
		cur = cur->m_pNext->m_pNext;
	}
	ret = head->m_pNext;
	complexListNode* curRet = ret;

	cur = head;
	while(cur)
	{
		complexListNode*tmp = cur->m_pNext;
		cur->m_pNext=tmp->m_pNext;
		cur = cur->m_pNext;

		curRet->m_pNext =tmp;
		curRet = curRet->m_pNext;
	}
	return ret;
}

int main()
{
	complexList l;
	int size = 10;
	for(int i = 0; i < size; ++i)
	{
		l.push(i);
	}

	complexListNode* cur = l.head;
	while(cur)
	{
		if(cur->m_pNext)
			l.link(cur,cur->m_pNext->m_pNext);
		cur = cur->m_pNext;
	}

	complexList c;
	c.head = copy(l.head);

	c.print();
	l.print();

	return 0;
}