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
	void BinarySortTree_Delete( BiTreeNode *t )
	{
		BiTreeNode *p, *s;
		if ( t->leftchild != NULL && t->rightchild == NULL )
		{
			p = t;
			t = t->leftchild;
			delete p;
		}
		else if ( t->leftchild == NULL && t->rightchild != NULL )
		{
			p = t;
			t = t->rightchild;
			delete p;
		}
		else if ( t->leftchild != NULL && t->rightchild != NULL )
		{
			p = t;
			s = t->leftchild;
			while ( s->rightchild != NULL )
			{
				p = s;
				s = s->rightchild;
			}
			t->datum = s->datum;
			if ( p != t )
				p->rightchild = s->leftchild;
			else
				p->leftchild  = s->leftchild;
			delete s;
		}
	}
	void BinarySortTree_Search( int item )
	{
		BiTreeNode *p = root, *q;
		while ( p != NULL )
		{
			if ( item == p->datum )
				break;
			else
			{
				q = p;
				if ( item < p->datum )
					p = p->leftchild;
				else if ( item > p->datum )
					p = p->rightchild;
			} 
		}
		if ( p == NULL );
		else if ( p != NULL )
		{
			if ( p->leftchild == NULL && p->rightchild == NULL )
			{
				if ( item < q->datum )
					q->leftchild = NULL;
				else if ( item > q->datum )
					q->rightchild = NULL;
				delete p;
			}
			else
				BinarySortTree_Delete(p);
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
			bst.BinarySortTree_Search(item);
			bst.InOrderUnrecursive();
		}
	}
	return 0;
}
/*
��Ŀ����
����һ���������У�������������������ʵ��ɾ������
�Զ�������������������������Եõ��������������

����
��һ������t����ʾ��t����������
�ڶ�������n����ʾ�׸����а���n������
����������n�����ݣ�������Ȼ���һ�����ͬ������֮���ÿո����
����������m����ʾҪɾ��m������
�ӵ�����������m�У�ÿ��һ��Ҫɾ�������ݣ�������Ȼ��
�Դ�����������һ��ʾ��

���
��һ�����������������У��Զ�����������������������Եõ�
�ӵڶ��������ɾ����m�����ݺ���������У����m��
�Դ����������һ��ʾ���Ľ��

��������
1
6
22 33 55 66 11 44
3
66
22
77

�������
11 22 33 44 55 66 
11 22 33 44 55 
11 33 44 55 
11 33 44 55 

��ʾ
��ɾ�����ݲ��������У���ôɾ���������ڲ�ִ�У�����������в��仯
*/
