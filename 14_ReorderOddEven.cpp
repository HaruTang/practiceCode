// 操作数组使得偶数在后,奇数在前

#include <iostream>
#include <vector>
using namespace std;

void reoderOddEven(std::vector<int>& v)
{
	int beg = 0; 
	int end = v.size()-1;

	while(beg!= end)
	{
		while((v[beg]&1)==1)
			++beg;
		swap(v[beg],v[end]);

		while((v[end]&1)==0)
			--end;
		swap(v[beg],v[end]);
	}
}
int main()
{
	std::vector<int> v;
	v.resize(10);
	for(int i = 0; i < 10; ++i)
		v[i] = i;

	reoderOddEven(v);

	for(int i = 0; i < 10; ++i)
		cout << v[i] << " " ;
	return 0;
}