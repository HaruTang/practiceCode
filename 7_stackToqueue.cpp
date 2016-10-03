// 用两个栈实现一个队列

#include <iostream>
#include <stack>
using namespace std;

class Queue
{
public:
	Queue()
	{}
	~Queue()
	{}
public:
	void push(const int &vlaue)
	{
		sIn.push(vlaue);
	}
	int size()
	{
		return sIn.size()+sOut.size();
	}
	bool empty()
	{
		return sIn.empty()&&sOut.empty();
	}
	int pop()
	{
		if(size()==0)
		{
			cout << "Queue is empty!"<<endl;
			return -1;
		}
		if(sOut.empty())
		{
			cout << "QueuesOut is empty!"<<endl;
			while(!sIn.empty())
			{
				int x = sIn.top();
				sIn.pop();
				sOut.push(x);
			}
		}
		int x = sOut.top();
		sOut.pop();
		return x;
	}
private:
	stack<int> sIn;
	stack<int> sOut;
};
int main()
{
	Queue q;
	int count = 10;
	for (int i = 0; i < count; ++i)
	{
		q.push(i);
	}

	for (int i = 0; i < count/2; ++i)
	{
		int p = q.pop();
		cout << p << endl;
	}

	for (int i = 0; i < count/2; ++i)
	{
		q.push(3*i);
	}
	while(!q.empty())
	{
		int p = q.pop();
		cout << p << endl;
	}
	return 0;
}