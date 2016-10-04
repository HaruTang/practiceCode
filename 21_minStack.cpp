#include <iostream>
#include <stack>
using namespace std;

struct Stack
{
public:
	bool empty()
	{
		return s.empty();
	}
	void push(const int& x)
	{
		s.push(x);
		int minV = x;
		if((!mins.empty())&&minV>mins.top())
		{
			minV = mins.top();
		}
		mins.push(minV);
	}

	int size()
	{
		return s.size();
	}

	void pop()
	{
		if(!s.empty())
		{
			s.pop();
			mins.pop();
		}
	}

	int min()
	{
		return mins.top();
	}
	stack<int> s;
	stack<int> mins;
};

int main()
{
	Stack s;
	s.push(4);
	cout << s.min()<<endl;
	s.push(8);
	cout << s.min()<<endl;
	s.push(3);
	cout << s.min()<<endl;
	s.push(9);
	cout << s.min()<<endl;
	s.push(422);
	cout << s.min()<<endl;
	s.push(42);
	cout << s.min()<<endl;
	s.push(66);
	cout << s.min()<<endl;
	s.push(1);
	cout << s.min()<<endl;

	while(!s.empty())
	{
		cout << s.min()<<endl;
		s.pop();
	}

	return 0;
}