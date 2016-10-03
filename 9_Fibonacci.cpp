#include <iostream>
using namespace std;

int Fibonacci(unsigned int n)
{
	int a[2] = {0,1};
	if(n <=1)
		return a[n];
	
	for(int i = 2; i <= n;++i)
	{
		int tmp = a[0]+a[1];
		swap(a[0],a[1]);
		a[1] = tmp;
	}
	return a[1];
}
int Fibonacci1(unsigned int n)
{
	if(n<=1)
		return n;
	else
		return Fibonacci(n-1)+Fibonacci(n-2);
}
int main()
{
	for (int i = 0; i < 10; ++i)
	{
		cout << Fibonacci(i)<<"\t";
		cout << Fibonacci1(i)<<endl;
	}
}