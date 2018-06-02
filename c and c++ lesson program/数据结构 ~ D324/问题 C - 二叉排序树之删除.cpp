# include <iostream>
# include <stack>
using namespace std;
class BinaryTreeNode
{
public:
	int value;
	BinaryTreeNode *leftchild;
	BinaryTreeNode *rightchild;
	BinaryTreeNode()
	{
		leftchild = NULL;
		rightchild = NULL;
	}
	~BinaryTreeNode()
	{
		if ( leftchild  != NULL )delete leftchild;
		if ( rightchild != NULL )delete rightchild;
	}
};
class BinarySortTree
{
private:
	int length;
	int position;
	int *array;
	BinaryTreeNode *root;
	void InOrderUnrecursive( BinaryTreeNode *t )
	{
		BinaryTreeNode *p = t;
		stack <BinaryTreeNode*> st;
		while ( p != NULL || !st.empty() )
		{
			while ( p != NULL )
			{
				st.push(p);
				p = p->leftchild;
			}
			if ( !st.empty() )
			{
				p = st.top();
				st.pop();
				cout<<p->value<<' ';
				p = p->rightchild;
			}
		}
	}
	void CreatingBinarySortTree()
	{
		int i;
		for ( i = 0 ; i < length ; ++i )
		{
			BinaryTreeNode *p, *q;
			if ( root == NULL )
			{
				root = new BinaryTreeNode ();
				root->value = array[i];
			}
			else
			{
				q = root;
				while ( q != NULL  )
				{
					p = q;
					if ( array[i] <  q->value )
						q = q->leftchild;
					else if ( array[i] >  q->value )
						q = q->rightchild;
				}
				q = new BinaryTreeNode ();
				q->value = array[i];
				if ( array[i] < p->value )
					p->leftchild = q;
				else if ( array[i] > p->value )
					p->rightchild = q;
			}
		}
	}
	void AmputationOfBody( BinaryTreeNode *t )
	{
		BinaryTreeNode *p, *s;
		/* if ( t->leftchild == NULL && t->rightchild == NULL )
		{
			cout<<"�����Һ���\n";
			delete t;
		}	
		else */if ( t->leftchild != NULL && t->rightchild == NULL )
		{
		//	cout<<"������\n";
			p = t;
			t = t->leftchild;
			delete p;
		}
		else if ( t->leftchild == NULL && t->rightchild != NULL )
		{
		//	cout<<"���Һ���\n";
			p = t;
			t = t->rightchild;
			delete p;
		}
		else // if ( t->leftchild != NULL && t->rightchild != NULL )
		{
		//	cout<<"�����Һ���\n";
			p = t;
			s = t->leftchild;
			while ( s->rightchild != NULL )
			{
				p = s;
				s = s->rightchild;
			}
			t->value = s->value;
			if ( p != t )
				p->rightchild = s->leftchild;
			else
				p->leftchild  = s->leftchild;
			delete s;
		}
	}
public:
	~BinarySortTree()
	{
		if ( array != NULL )delete []array;
		if ( root  != NULL )delete root;
	}
	void InOrderUnrecursive()
	{
		InOrderUnrecursive(root);
		cout<<endl;
	}
	void CreatingBinarySortTree( int *list, int size )
	{
		int i;
		length = size;
		array = new int [length];
		for ( i = 0  ; i < length ; ++i )
			array[i] = list[i];
		position = 0;
		root = NULL;
		CreatingBinarySortTree();
	}
	void DeleteBinarySortTree( int body )
	{
		bool found = false;
		BinaryTreeNode *p = root, *q;
		while ( p != NULL )
		{
			if ( body == p->value )
			{
				found = true;
				break;
			}
			else
			{
				q = p;
				if ( body <  p->value )
					p = p->leftchild;
				else if ( body >  p->value )
					p = p->rightchild;
			} 
		}
		if ( p == NULL );
			//cout<<"�����Һ���\n";
		else if ( p != NULL )
		{
			if ( p->leftchild == NULL && p->rightchild == NULL )
			{		
				if ( q->value <  body )
					q->rightchild = NULL;
				else
					q->leftchild  = NULL;
				delete p;
			}
			else
				AmputationOfBody(p);
		}
	}
};
int main()
{
	int t, n, m, i, amputee;
	int *list;
	cin>>t;
	while ( t-- )
	{
		cin>>n;
		list = new int [n];
		for ( i = 0 ; i < n ; ++i )
			cin>>list[i];
		BinarySortTree nishinponoki;
		nishinponoki.CreatingBinarySortTree(list,n);
		nishinponoki.InOrderUnrecursive();
		cin>>m;
		while ( m-- )
		{
			cin>>amputee;
			nishinponoki.DeleteBinarySortTree(amputee);
			nishinponoki.InOrderUnrecursive();
		}
	}
	delete [] list;
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
��ɾ�����ݲ��������У���ôɾ���������ڲ�ִ�У�
����������в��仯
*/
