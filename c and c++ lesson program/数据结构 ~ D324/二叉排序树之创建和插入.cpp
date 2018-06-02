# include <iostream>
# include <stack>
using namespace std;
class BiTreeNode
{
public:
	int datum;
	BiTreeNode *leftchild;
	BiTreeNode *rightchild;
	BiTreeNode()
	{
		leftchild = NULL;
		rightchild = NULL;
	}
	~BiTreeNode()
	{
		if ( leftchild != NULL )delete leftchild;
		if ( rightchild != NULL )delete rightchild;
	}
};
class BinarySortTree
{
private:
	BiTreeNode *root;
	void InOrderUnrecursive( BiTreeNode *t )
	{
		BiTreeNode *p = t;
		stack <BiTreeNode*> s;
		while ( p != NULL || s.empty() == false )
		{
			while ( p != NULL )
			{
				s.push(p);
				p = p->leftchild;
			}
			if ( s.empty() == false )
			{
				p = s.top();
				s.pop();
				cout<<p->datum<<' ';
				p = p->rightchild;
			}
		}
	}
public:
	BinarySortTree()
	{
		root = NULL;
	}
	void BinarySortTree_Insert( int item )
	{
		if ( root != NULL )
		{
			BiTreeNode *p, *q = root;
			while ( q != NULL )
			{
				p = q;
				if ( item < q->datum )
					q = q->leftchild;
				else
					q = q->rightchild;
			}
			q = new BiTreeNode ();
			q->datum = item;
			if ( item < p->datum )
				p->leftchild = q;
			else
				p->rightchild = q;
		}
		else
		{
			root = new BiTreeNode ();
			root->datum = item;
		}
	}
	void InOrderUnrecursive()
	{
		InOrderUnrecursive(root);
		cout<<endl;
	}
};
int main()
{
	int t, n, item;
	BinarySortTree bst;
	cin>>t;
	while ( t-- )
	{
		cin>>n;
		while ( n-- )
		{
			cin>>item;
			bst.BinarySortTree_Insert(item);
		}
		bst.InOrderUnrecursive();
		cin>>n;
		while ( n-- )
		{
			cin>>item;
			bst.BinarySortTree_Insert(item);
			bst.InOrderUnrecursive();
		}
	}
	return 0;
}
/*
��Ŀ����
����һ���������У�������������������ʵ�ֲ��빦��
�Զ�������������������������Եõ��������������

����
��һ������t����ʾ��t����������
�ڶ�������n����ʾ�׸����а���n������
����������n�����ݣ�������Ȼ���һ�����ͬ������֮���ÿո����
����������m����ʾҪ����m������
�ӵ�����������m�У�ÿ��һ��Ҫ��������ݣ�������Ȼ���Һ�ǰ������ݲ���
�Դ�����������һ��ʾ��

���
��һ�����������������У��Զ�����������������������Եõ�
�ӵڶ�������������m�����ݺ���������У����m��
�Դ����������һ��ʾ���Ľ��

��������
1
6
22 33 55 66 11 44
3
77
50
10

�������
11 22 33 44 55 66 
11 22 33 44 55 66 77 
11 22 33 44 50 55 66 77 
10 11 22 33 44 50 55 66 77 
*/
