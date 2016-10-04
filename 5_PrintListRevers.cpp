#include <iostream>
#include <stack>
#include "sList.h"
using namespace std;

// struct List

void PrintListRevers(ListNode* head)
{
	if(!head)
		return;
	if(head->next)
		PrintListRevers(head->next);
	cout << head->value<<" ";
}


// void PrintListRevers(ListNode* head)
// {
// 	stack<ListNode*> s;
// 	while(head!=NULL)
// 	{
// 		s.push(head);
// 		head = head->next;
// 	}

// 	while(!s.empty())
// 	{
// 		ListNode* top = s.top();
// 		cout << top->value<<endl;
// 		s.pop();
// 	}
// }
int main(int argc, char const *argv[])
{
	PrintListRevers(l.head);
	return 0;
}