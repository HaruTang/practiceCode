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

#include <queue>
void PrintTreeLeve(BinaryTreeNode* head)
{
	if(head == NULL)
		return;
	queue<BinaryTreeNode*> q;
	q.push(head);
	while(!q.empty())
	{
		BinaryTreeNode* cur = q.front();
		if(cur->m_pLeft)
			q.push(cur->m_pLeft);
		if(cur->m_pRight)
			q.push(cur->m_pRight);
		cout << cur->m_value<<" ";
		q.pop();
	}
	cout << endl;
}

int main()
{
	int arrPre[]= {1,2,4,7,3,5,6,8};
	int arrIn[] = {4,7,2,1,5,3,8,6};
	BinaryTreeNode*root = BuildTree(arrPre,arrIn,8);
	cout << "size = " <<TreeSize(root)<<endl;
	PrintTree(root);
	// PrintTreeLeve(root);
	return 0;
}