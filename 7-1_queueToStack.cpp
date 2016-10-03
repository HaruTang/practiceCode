// 两个队列实现一个栈

#include <iostream>
#include <queue>
using namespace std;

class Stack
{
public:
	Stack()
	:least(true)
	{}

	void push(const int & value)
	{
		cout << value<<endl;
		if(least)
			qIn.push(value);
		else
			qOut.push(value);
	}
	int size()
	{
		return qIn.size()+qOut.size();
	}
	void pop()
	{
		if(least)
		{
			qIn.pop();
			least = false;
		}
		else
		{
			qOut.pop();
			least = true;
		}
	}
	bool empty()
	{
		return qIn.empty()&&qOut.empty();
	}
	int top()
	{
		if(least)
		{
			// 直到只剩一个
			while(qIn.size()!=1)
			{
				int x = qIn.front();
				qIn.pop();
				qOut.push(x);
			}
			return qIn.back();
		}
		else
		{
			while(qOut.size()!=1)
			{
				int x = qOut.front();
				qOut.pop();
				qIn.push(x);
			}
			return qOut.back();
		}
	}
private:
	bool least;
	queue<int> qIn;	
	queue<int> qOut;	
};
int main()
{
	Stack s;
	int count = 10;
	for (int i = 0; i < count; ++i)
	{
		s.push(i);
	}
	while(!s.empty())
	{
		int x = s.top();
		cout << x << " ";
		s.pop();
	}
}