# include <iostream>
# include <string>
using namespace std;
int runningtimes = 0;
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
	BiTreeNode *CreateBiTree()
	{
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
	int CalculatingTreeLeaves( BiTreeNode *t )
	{
		++runningtimes;
		int leaves = 0;
		/**/ if ( t->LeftChild != NULL && t->RightChild != NULL )
		{
			leaves += CalculatingTreeLeaves(t->LeftChild);
			leaves += CalculatingTreeLeaves(t->RightChild);
		}
		else if ( t->LeftChild == NULL && t->RightChild != NULL )
			leaves += CalculatingTreeLeaves(t->RightChild);
		else if ( t->LeftChild != NULL && t->RightChild == NULL )
			leaves += CalculatingTreeLeaves(t->LeftChild);
		else if ( t->LeftChild == NULL && t->RightChild == NULL )
			return 1;
		return leaves;
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
	int CalculatingTreeLeaves()
	{
		return CalculatingTreeLeaves(Root);
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
		cout<<nishinponoki.CalculatingTreeLeaves()<<endl;
		cout<<"Running times = "<<runningtimes<<endl;
		runningtimes = 0;
	}
	return 0;
}
/*
��Ŀ����
����һ�Ŷ�����������Ҷ�ӽ��������

��ʾ��Ҷ����ָ�������Һ���Ϊ�ա�

�����������á��������+������0��ʾ���ķ�����
������һ�Ŷ���������������Ľ��ΪAB0C00D00�����пսڵ����ַ���0����ʾ����������߼��ṹ����ͼ��

����
��һ������һ������t����ʾ��t����������
�ڶ����������������������Ľ����
�������ַ���0����ʾ������t��

���
�������ÿ���������İ�����Ҷ������

��������
3
AB0C00D00
AB00C00
ABC00D00E00

�������
2
2
3
*/
