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
	void InOrderRecursive( BinaryTreeNode *t )
	{
		if ( t != NULL )
		{
			InOrderRecursive(t->leftchild);
			cout<<t->value<<' ';
			InOrderRecursive(t->rightchild);
		}
	}
	void InOrderUnrecursive( BinaryTreeNode *t )
	{
		BinaryTreeNode *p = t;
		stack <BinaryTreeNode*> st;
		while ( p != NULL || !st.empty() )
		{
		//	cout<<"[[[[[[[[]]]]]]]]\n";
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
			//	cout<<array[i]<<"==============\n";
				root = new BinaryTreeNode ();
				root->value = array[i];
			}
			else
			{//22 33 55 66 11 44
				q = root;
				while ( q != NULL  )
				{
					p = q;
					if ( array[i] <  q->value )
					{
					//	cout<<q->value<<"++++++++++++++\n";
						q = q->leftchild;
					}
					else if ( array[i] >  q->value )
					{
					//	cout<<q->value<<"--------------\n";
						q = q->rightchild;
					}
				}
				q = new BinaryTreeNode ();
				q->value = array[i];
				if ( array[i] < p->value )p->leftchild = q;
				else if ( array[i] > p->value )p->rightchild = q;
			}
		}
	}
public:
	~BinarySortTree()
	{
		if ( array != NULL )delete []array;
		if ( root  != NULL )delete root;
	}
	void InOrderRecursive()
	{
		InOrderRecursive(root);
		cout<<endl;
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
		//for ( i = 0  ; i < length ; ++i )cout<<array[i]<<' ';cout<<endl;
		position = 0;
		root = NULL;
		CreatingBinarySortTree();
	}
	void InsertBinarySortTree( int inlet )
	{
		BinaryTreeNode *p = root, *q;
		while ( p != NULL )
		{
			q = p;
			if ( inlet < p->value )
				p = p->leftchild;
			else if ( inlet > p->value )
				p = p->rightchild;
		}
		p = new BinaryTreeNode ();
		p->value = inlet;
		if ( inlet < q->value )
			q->leftchild = p;
		else if ( inlet > q->value )
			q->rightchild = p;
	}
};
int main()
{
	int t, n, m, i, thrust;
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
			cin>>thrust;
			nishinponoki.InsertBinarySortTree(thrust);
			nishinponoki.InOrderUnrecursive();
		}
	}
	delete [] list;
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
