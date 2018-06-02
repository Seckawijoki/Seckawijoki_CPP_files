# include <iostream>
# include <stack>
using namespace std;
# define OK     0
# define ERROR -1
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
	int BinarySortTree_Search( int item, int &times )
	{
		BiTreeNode *p = root;
		times = 0;
		while ( p != NULL )
		{
			++times;
			if ( item == p->datum )
				return OK;
			else if ( item < p->datum )
				p = p->leftchild;
			else if ( item > p->datum )
				p = p->rightchild;
		}
		return ERROR;
	}
	void InOrderUnrecursive()
	{
		InOrderUnrecursive(root);
		cout<<endl;
	}
};
int main()
{
	int t, n, item, result, times;
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
			result = bst.BinarySortTree_Search(item,times);
			if ( result == ERROR )cout<<-1<<endl;
			else	cout<<times<<endl;
		}
	}
	return 0;
}
/*
��Ŀ����
����һ���������У�������������������ʵ�ֲ��ҹ���
�Զ�������������������������Եõ��������������

����
��һ������t����ʾ��t����������
�ڶ�������n����ʾ�׸����а���n������
����������n�����ݣ�������Ȼ���һ�����ͬ������֮���ÿո����
����������m����ʾҪ����m������
�ӵ�����������m�У�ÿ��һ��Ҫ���ҵ����ݣ�������Ȼ��
�Դ�����������һ��ʾ��

���
��һ�����������������У��Զ�����������������������Եõ�
�ӵڶ�����������ҽ����������ҳɹ�������Ҵ������������ʧ�����-1
�Դ����������һ��ʾ���Ľ��

��������
1
6
22 33 55 66 11 44
7
11
22
33
44
55
66
77

�������
11 22 33 44 55 66 
2
1
2
4
3
4
-1
*/
