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
��Ŀ����
����һ�Ŷ��������߼��ṹ����������Ľ�����������ַ���0����ʾ������ͼ�Ķ��������ɱ�ʾΪAB0C00D00����
�����ö������Ķ�����ʽ�洢�ṹ�������ڵ�Ĳ����ָ�Ӹ���㵽����ĳ�������·���ϵı�����1��Ϊ�ý��Ĳ�Ρ�
����������Ⱦ��Ƕ����������н��Ĳ�ε����ֵ��Ϊ��������ȡ�
����ͼ�У�A�Ĳ��Ϊ1��B�Ĳ��Ϊ2��D�Ĳ��Ϊ2��C�Ĳ��Ϊ3�����Զ����������Ϊ3��
�������������

����
��һ������һ������t����ʾ��t����������
�ڶ����������������������Ľ�����������ַ���0����ʾ�����迼�ǿ���
�Դ�����

���
�������ÿ�������������

��������
3
AB0C00D00 
AB00C00
ABCD0000EF000

�������
3
2
4
*/
