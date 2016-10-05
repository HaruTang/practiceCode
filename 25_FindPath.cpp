// 输入二叉树的前序遍历和中序结果.重建二叉树

#include <iostream>
#include <stdio.h>
using namespace  std;

struct BinaryTreeNode
{
	BinaryTreeNode(int value)
	:m_value(value)
	,m_pLeft(NULL)
	,m_pRight(NULL)
	{}
	int m_value;
	BinaryTreeNode* m_pLeft;
	BinaryTreeNode* m_pRight;
};

BinaryTreeNode* BuildTreeCore(int*arrPreBeg,int*arrPreEnd,
							  int*arrInBeg, int*arrInEnd)
{
	int rootValue = arrPreBeg[0];
	// cout << rootValue<<endl;
	BinaryTreeNode* root = new BinaryTreeNode(rootValue);
	root->m_pLeft = root->m_pRight = NULL;

	//找到中序中的root节点
	if(arrPreBeg==arrPreEnd)
	{
		if(arrInBeg==arrInEnd && *arrPreBeg==*arrInBeg)
		{
			return root;
		}
		else
			throw;
	}

	//在中序中找到root 
	int *rootIn = arrInBeg;
	while(rootIn<=arrInEnd&&*rootIn!=rootValue)
		++rootIn;

	int leftLen = rootIn- arrInBeg;
	int * leftPrEnd = arrPreBeg+leftLen;

	if(leftLen>0)
	{
		root->m_pLeft = BuildTreeCore(arrPreBeg+1,leftPrEnd,arrInBeg,rootIn-1);
	}
	if(leftLen<arrPreEnd- arrPreBeg)
	{
		root->m_pRight = BuildTreeCore(leftPrEnd+1,arrPreEnd,rootIn+1,arrInEnd);
	}
	return root;
}

BinaryTreeNode* BuildTree(int* arrPre,int *arrIn,int length)
{
	//pre {1,2,4,7,3,5,6,8};
	//in  {4,7,2,1,5,3,8,6};
	if(arrPre==NULL||arrIn == NULL||length<=0)
		return NULL;
	return BuildTreeCore(arrPre,arrPre+length-1,arrIn,arrIn+length-1);
}
int TreeSize(BinaryTreeNode*head)
{
	if(!head)
		return 0;
	return 1 + TreeSize(head->m_pRight)+TreeSize(head->m_pLeft);
}

void PrintTree(BinaryTreeNode*head,int count = 0)
{
	count++;
	if(head->m_pLeft)
	{
		PrintTree(head->m_pLeft,count);
	}
	if(head)
	{
		for (int i = 0; i < count-1;++i)
		{
			cout << "  ";
		}
		cout << head->m_value<<endl;
	}

	if(head->m_pRight)
	{
		PrintTree(head->m_pRight,count);
	}
	
}

// 输入一个二叉树和一个整数,打印二叉树中节点值和为输入整数的路径.
// 路径:从根到叶子节点经过的所有节点形成一个路径

#include <vector>
void FindPath(BinaryTreeNode* head,vector<BinaryTreeNode*>&v,const int&sum)
{
	int total = 0;
		for(int i = 0;i < v.size();++i)
			total+=v[i]->m_value;
	if(head==NULL)
	{
		if(total==sum)
		{
			for(int i = 0; i< v.size();++i)
				cout << (v[i]->m_value)<< " ";
			cout << endl<<endl;
		}
		return;
	}

	v.push_back(head);

	FindPath(head->m_pLeft,v,sum);
	if(head->m_pLeft)
		v.pop_back();
// fuck..这个条件真的是单疼
if(head->m_pRight)
	FindPath(head->m_pRight,v,sum);
	if(head->m_pRight)
		v.pop_back();
}


int main()
{
	std::vector<BinaryTreeNode*> v;
	int arrPre[]= {1,2,4,7,3,5,6,8};
	int arrIn[] = {4,7,2,1,5,3,8,6};
	BinaryTreeNode*root = BuildTree(arrPre,arrIn,8);
	cout << "size = " <<TreeSize(root)<<endl;
	PrintTree(root);
	FindPath(root,v,9);
	v.resize(0);
	FindPath(root,v,18);

	v.resize(0);
	FindPath(root,v,10);

	v.resize(0);
	FindPath(root,v,14);
	v.resize(0);
	FindPath(root,v,7);
	return 0;
}