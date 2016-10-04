#include <iostream>
#include <vector>
using namespace std;

void PrintCir(std::vector<std::vector<int> > &v,int l,int r,int u,int d)
{
	if(l>r||u>d)
		return;

	if(l == r||u==d)
	{
		for(int i = l;i<=r;++i)
		{
			for(int j = u;j<=d;++j)
				cout << v[j][i]<<" ";
		}
		cout <<endl;
		return;
	}

	for(int i = l;i<r;++i)
		cout << v[u][i]<<" ";
	for(int i = u;i<d;++i)
		cout << v[i][r]<<" ";
	for(int i = r;i>l;--i)
		cout << v[d][i]<<" ";
	for(int i = d;i>u;--i)
		cout << v[i][l]<<" ";
	cout << endl;

	PrintCir(v,++l,--r,++u,--d);
}
int main(int argc, char const *argv[])
{
	std::vector<std::vector<int> > v;
	int row =9;
	int col =3;
	v.resize(row);
	for(int i = 0 ; i < row;++i)
	{
		v[i].resize(col);
		for(int j = 0;j<col;++j)
		{
			v[i][j] = i+2*j;
		}
	}
	for(int i = 0 ; i < row;++i)
	{
		for(int j = 0;j<col;++j)
		{
			cout << v[i][j]<< " ";
		}
		cout << endl;
	}
	cout << endl;
	PrintCir(v,0,col-1,0,row-1);
	return 0;
}