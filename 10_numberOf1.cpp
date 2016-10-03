#include <iostream>
using namespace std;

int numOf1(int n)
{
	int ret = 0;
	while(n)
	{
		ret++;
		n&=(n-1);
	}
	return ret;
}

bool IfPowOf2(int n)
{
	return (n&(n-1))==0;
}

int numDiff(int a,int b)
{
	return numOf1(a^b);
}
int main()
{
	for (int i = -10; i < 10; ++i)
	{
		cout << numOf1(i)<<" ";
		cout << IfPowOf2(i)<<endl;
	}
	cout << numDiff(1,2);
	cout << numDiff(8,4);
	cout << numDiff(33,22);
	return 0;
}

