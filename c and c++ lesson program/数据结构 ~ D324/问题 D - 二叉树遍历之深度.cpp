# include <iostream>
# include <string>
using namespace std;
class BiTreeNode
{
public:
	char datum;
	BiTreeNode *LeftChild;
	BiTreeNode *RightChild;
	BiTreeNode()
	{
		LeftChild = NULL;
		RightChild = NULL;
	}
	~BiTreeNode()
	{
		if ( LeftChild != NULL )delete LeftChild;
		if ( RightChild != NULL )delete RightChild;
	}
};
class BiTree
{
private:
	BiTreeNode *Root;
	int position;
	string strTree;
	//AB0C00D00 
	BiTreeNode *CreateBiTree()
	{
		//Root = CreateBiTree();
		BiTreeNode *T;
		char ch;
		ch = strTree[position++];
		if ( ch == '0' )
			T = NULL;
		else
		{
			T = new BiTreeNode();
			T->datum = ch;
			T->LeftChild = CreateBiTree();
			T->RightChild = CreateBiTree();
		}
		return T;
	}
	void PreOrder( BiTreeNode *t )
	{
		if ( t != NULL )
		{
			cout<<t->datum;
			PreOrder(t->LeftChild);
			PreOrder(t->RightChild);
		}
	}	
	void InOrder( BiTreeNode *t )
	{
		if ( t != NULL )
		{
			InOrder(t->LeftChild);
			cout<<t->datum;
			InOrder(t->RightChild);
		}
	}
	void PostOrder( BiTreeNode *t )
	{
		if ( t != NULL )
		{
			PostOrder(t->LeftChild);
			PostOrder(t->RightChild);
			cout<<t->datum;
		}
	}
	int BiTreeDepth( BiTreeNode *t )
	{
		if ( t == NULL )
			return 0;
		else
		{
			int leftDepth = 1;
			int rightDepth = 1;
			/**/ if ( t->LeftChild != NULL && t->RightChild != NULL )
			{
				leftDepth += BiTreeDepth(t->LeftChild);
				rightDepth += BiTreeDepth(t->RightChild);
				return leftDepth >= rightDepth ? leftDepth : rightDepth;
			}
			else if ( t->LeftChild != NULL && t->RightChild == NULL )
			{
				leftDepth += BiTreeDepth(t->LeftChild);
				return leftDepth >= rightDepth ? leftDepth : rightDepth;
			}
			else if ( t->LeftChild == NULL && t->RightChild != NULL )
			{
				rightDepth += BiTreeDepth(t->RightChild);
				return leftDepth >= rightDepth ? leftDepth : rightDepth;
			}
			else if ( t->LeftChild == NULL && t->RightChild == NULL )
				return leftDepth >= rightDepth ? leftDepth : rightDepth;
		}
	}
public:
	BiTree()
	{
		position = 0;
		Root = NULL;
	}
	~BiTree()
	{
		if ( Root != NULL ) delete Root;
	}
	void CreateTree( string TreeArray )
	{
		position = 0;
		strTree.assign(TreeArray);
		Root = CreateBiTree();
	}
	void PreOrder()
	{
		PreOrder(Root);
	}
	void InOrder()
	{
		InOrder(Root);
	}
	void PostOrder()
	{
		PostOrder(Root);
	}
	int BiTreeDepth()
	{
		return BiTreeDepth(Root);
	}
};
int main()
{
	int t;
	cin>>t;
	while ( t-- )
	{
		string binarytree;
		cin>>binarytree;
		BiTree nishinponoki;
		nishinponoki.CreateTree(binarytree);
		cout<<nishinponoki.BiTreeDepth()<<endl;
	}
	return 0;
}
/*
题目描述
给定一颗二叉树的逻辑结构（先序遍历的结果，空树用字符‘0’表示，如下图的二叉树，可表示为AB0C00D00），
建立该二叉树的二叉链式存储结构二叉树节点的层次是指从根结点到树中某结点所经路径上的边数加1称为该结点的层次。
二叉树的深度就是二叉树中所有结点的层次的最大值称为该树的深度。
比如图中，A的层次为1，B的层次为2，D的层次为2，C的层次为3。所以二叉树的深度为3。
编程求二叉树深度

输入
第一行输入一个整数t，表示有t个测试数据
第二行起输入二叉树先序遍历的结果，空树用字符‘0’表示，无需考虑空树
以此类推

输出
逐行输出每个二叉树的深度

样例输入
3
AB0C00D00 
AB00C00
ABCD0000EF000

样例输出
3
2
4
*/
