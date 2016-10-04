// 打印1到n位数字
// 使用全排列方式处理
#include <iostream>
#include <vector>
using namespace std;

void printNumber(std::vector<char> &v)
{
	int len = v.size();
	int beg = 0;
	bool ok = false;
	while(v[beg]!='\0'&&beg<len)
	{
		if(v[beg]!='0')
			ok = true;
		if(ok)
			cout << v[beg];
		++beg;
	}
	cout << endl;
}
void Print(std::vector<char> &v,int length,int index)
{
	if( index == length-1)
	{
		printNumber(v);
		return;
	}
	for(int i = 0 ; i < 10; ++ i)
	{
		v[index+1] = i + '0';
		Print(v,length,index+1);
	}

}
void Print1ToN(int n)
{
	if (n<=0)
		return;

	std::vector<char> v;
	v.resize(n);
	for(int i = 0; i < n;++i)
		v[i] = '\0';

	for(int i = 0;i < 10; ++ i)
	{
		v[0] = i + '0';
		Print(v,n,0);
	}

}

int main(int argc, char const *argv[])
{
	Print1ToN(5);
	return 0;
}