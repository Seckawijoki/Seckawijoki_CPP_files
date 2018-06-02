# include <iostream>
# include <stack>
using namespace std;
# define OK     1
# define ERROR -1
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
	int SearchBinarySortTree( int aim )
	{
		int times = 0;
		BinaryTreeNode *p = root, *q;
		while ( p != NULL )
		{
			q = p;
			++times;
			/**/ if ( aim == p->value )
				return times;
			else if ( aim <  p->value )
				p = p->leftchild;
			else if ( aim >  p->value )
				p = p->rightchild;
		}
		if ( q ->leftchild == NULL && q->rightchild == NULL )
			return ERROR;
		else
			return times;
	}
};
int main()
{
	int t, n, m, i, mission;
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
			cin>>mission;
			cout<<nishinponoki.SearchBinarySortTree(mission)<<endl;
		}
	}
	delete [] list;
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
