# include <iostream>
# include <string>
# include <queue>
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
	void LevelOrder( BiTreeNode *t )
	{
		queue <BiTreeNode*> tq;
		BiTreeNode *p = t;
		if ( p != NULL )
		{
			tq.push(p);
			while ( !tq.empty() )
			{
				p = tq.front();
				tq.pop();
				cout<<p->datum;
				if ( p->LeftChild != NULL )tq.push(p->LeftChild);
				if ( p->RightChild != NULL )tq.push(p->RightChild);
			}
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
	void LevelOrder()
	{
		LevelOrder(Root);
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
		nishinponoki.LevelOrder();
		cout<<endl;
	}
	return 0;
}
/*
��Ŀ����
��α������������ǴӸ���㿪ʼ������
����δ������϶��£��������ҡ��������еĸ���㡣
�����������á��������+������0��ʾ���ķ���

Ҫ�󣺲��ö��ж���ʵ�֣�����������£�

����
��һ������һ������t����ʾ��t����������
�ڶ����������������������Ľ�����������ַ���0����ʾ��
����t��

���
�������ÿ���������Ĳ�α������

��������
2
AB0C00D00
ABCD00E000FG00H0I00

�������
ABDC
ABFCGHDEI
*/
