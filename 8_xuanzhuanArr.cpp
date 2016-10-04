//寻找旋转数组的最小值,单调递增1222344445

#include <iostream>
#include <vector>
using namespace std;

int BinarySearch(vector<int>&v,int start,int end)
{
	while(start<=end)
	{
		//边界相等
		if(v[start]==v[end]||end - start==1)
		{
			int ret = v[start];
			while(start<=end)
			{
				if(v[start]<ret)
				{
					ret = v[start];
				}
				++start;
			}
			return ret;
		}

		int mid = start+ (end - start)/2;
		if(v[mid]>v[start]&&v[mid]<v[end])
		{
			end	= mid;
		}
		else if(v[mid]>v[start]&&v[start]>v[end])
		{
			start = mid;
		}
		else
			end = mid;
	}

}
int SearchInCirArr(vector<int> & v)
{
	// 222222211112222
	// 4561234
	// 89013
	// 012345
	//二分.如果左右值相等,下标不等,那么迭代.否则二分
	int len = v.size();

	// []
	return BinarySearch(v,0,len-1);
}
int main()
{
	std::vector<int> v;
	for (int i = 4; i < 10; ++i)
	{
		v.push_back(i);
	}
	v.push_back(0);
	for (int i = 0; i < 4; ++i)
	{
		v.push_back(i);
	}

	cout << SearchInCirArr(v)<<endl;
	// v.resize(1);
	// cout << SearchInCirArr(v)<<endl;

	return 0;
}