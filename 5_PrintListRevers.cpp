#include <iostream>
#include <stack>
using namespace std;

struct ListNode
{
	int m_nKey;
	ListNode* m_pNext;
};

void PrintListRevers(ListNode* head)
{
	if(!head)
		return;
	if(head->m_pNext)
		PrintListRevers(head->m_pNext);
	cout << head->m_nKey<<endl;
}

void PrintListRevers(ListNode* head)
{
	stack<ListNode*> s;
	while(head!=NULL)
	{
		s.push(head);
		head = head->m_pNext;
	}

	while(!s.empty())
	{
		ListNode* top = s.top();
		cout << top->m_nKey<<endl;
		s.pop();
	}
}
int main(int argc, char const *argv[])
{
	
	return 0;
}