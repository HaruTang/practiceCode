// 判断数组是否是二叉搜索树的后续遍历
// fuck:二叉搜索树,而不是平衡二叉搜索树
#include <iostream>
using namespace std;

bool IsVerifySquenceOfBST(int sequence[],int length)
{
	if(sequence==NULL||length<=0)
		return false;

	int root = sequence[length-1];

	int left = 0;	//获取左子树
	for(;left < length-1;++left)
	{
		if(sequence[left] > root)
			break;
	}

	// 验证右
	for(int i = left;i< length-1;++i)
		if(sequence[i]<root)
			return false;

	// 判断左子树
	bool l = true;
	if(left>0)
		l = IsVerifySquenceOfBST(sequence,left);

	// 判断右
	bool r = true;
	if(left<length-1)
		r = IsVerifySquenceOfBST(sequence+left,length-left-1);

	return l&&r;
}

int main()
{
	int arr[] = {55,7,6,9,11,10,100};
	cout << IsVerifySquenceOfBST(arr,7)<<endl;
	return 0;
}