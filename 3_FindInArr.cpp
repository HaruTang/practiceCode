#include <iostream>
#include <assert.h>
#include <vector>
using namespace std;

pair<bool,pair<int,int> > Find(vector<vector<int> >&v,int num)
{
	assert(v.size()!=0);
	int row = v.size();
	int col = v[0].size();

	bool found = false;

	int beginRow = row-1;
	int beginCol = 0;
	while(beginRow>=0&&beginCol<col)
	{
		if(num==v[beginRow][beginCol])
		{
			found = true;
			break;
		}
		if(num>v[beginRow][beginCol])
			beginCol++;
		else
			beginRow--;
	}

	pair<int,int> ret(beginRow,beginCol);
	return pair<bool,pair<int,int> >(found,ret);
}

int main()
{
	vector<vector<int> > v;
	v.resize(5);
	for(int i = 0 ; i < 5;++i)
	{
		v[i].resize(6);
		for(int j = 0 ; j < 6;++j)
		{
			v[i][j] = i+j*8;
		}
	}
	// v.resize(3);

	for(int i = 0 ; i < 5;++i)
	{
		for(int j = 0 ; j < 6;++j)
		{
			cout << v[i][j]<< " ";
		}
		cout << endl;
	}
	cout <<endl;

	pair<bool,pair<int,int> > ret;
	ret = Find(v,4);
	cout << "find = 4"<<endl;
	cout << ret.first<<endl;
	if(ret.first)
	{
		cout << ret.second.first<<" ";
		cout << ret.second.second<<endl<<endl;
	}

	ret = Find(v,26);
	cout << "find = 26"<<endl;
	cout << ret.first<<endl;
	if(ret.first)
	{
		cout << ret.second.first<<" ";
		cout << ret.second.second<<endl<<endl;
	}

	ret = Find(v,-3);
	cout << "find = -3"<<endl;
	cout << ret.first<<endl;
	if(ret.first)
	{
		cout << ret.second.first<<" ";
		cout << ret.second.second<<endl<<endl;
	}

	ret = Find(v,99);
	cout << "find = 99"<<endl;
	cout << ret.first<<endl;
	if(ret.first)
	{
		cout << ret.second.first<<" ";
		cout << ret.second.second<<endl<<endl;
	}


	return 0;
}