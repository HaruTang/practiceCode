// 判断一个树是否是另一个树的子树
// 注意严谨的逻辑.递归结束条件



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

int test()
{
	int arrPre[]= {1,2,4,7,3,5,6,8};
	int arrIn[] = {4,7,2,1,5,3,8,6};
	BinaryTreeNode*root = BuildTree(arrPre,arrIn,8);
	cout << "size = " <<TreeSize(root)<<endl;
	PrintTree(root);

	return 0;
}

bool isPartTree(BinaryTreeNode*head1,BinaryTreeNode*head2)
{
	if(head2==NULL)
		return true;

	if(head1==NULL)
		return false;

	// h2为叶子节点且等于h1值
	if(head2->m_pLeft == head2->m_pRight
			&&head2->m_pLeft == NULL
			&&head1->m_value == head2->m_value)
	{
		return true;
	}
	// if(head2->m_value!=head1->m_value)
	// 	return false;
	return (head1->m_value==head2->m_value&&
		isPartTree(head1->m_pLeft,head2->m_pLeft)&&
		isPartTree(head1->m_pRight,head2->m_pRight))
		||isPartTree(head1->m_pLeft,head2)
		||isPartTree(head1->m_pRight,head2);
	// return (isPartTree(head1->m_pLeft,head2->m_pLeft)&&isPartTree(head1->m_pRight,head2->m_pRight))
	// 	||isPartTree(head1->m_pLeft,head2)
	// 	||isPartTree(head1->m_pRight,head2);
}

int main()
{	
	int arrPre1[]= {1,2,4,7,3,5,6,8};
	int arrIn1[] = {4,7,2,1,5,3,8,6};
	BinaryTreeNode*root1 = BuildTree(arrPre1,arrIn1,8);
	PrintTree(root1);
	cout << endl;

	int arrPre2[]= {3,4,7};
	int arrIn2[] = {4,7,3};

	int arrPre3[]= {2,4,7};
	int arrIn3[] = {4,7,2};
	BinaryTreeNode*root2 = BuildTree(arrPre2,arrIn2,3);
	PrintTree(root2);
	BinaryTreeNode*root3 = BuildTree(arrPre3,arrIn3,3);
	PrintTree(root3);

	if(isPartTree(root1,root2))
		cout << "part"<<endl;
	else
		cout << "not"<<endl;

	if(isPartTree(root1,root3))
		cout << "part"<<endl;
	else
		cout << "not"<<endl;
}