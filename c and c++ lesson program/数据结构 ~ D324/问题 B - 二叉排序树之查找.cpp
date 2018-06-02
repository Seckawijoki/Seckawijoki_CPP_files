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
题目描述
给出一个数据序列，建立二叉排序树，并实现查找功能
对二叉排序树进行中序遍历，可以得到有序的数据序列

输入
第一行输入t，表示有t个数据序列
第二行输入n，表示首个序列包含n个数据
第三行输入n个数据，都是自然数且互不相同，数据之间用空格隔开
第四行输入m，表示要查找m个数据
从第五行起，输入m行，每行一个要查找的数据，都是自然数
以此类推输入下一个示例

输出
第一行输出有序的数据序列，对二叉排序树进行中序遍历可以得到
从第二行起，输出查找结果，如果查找成功输出查找次数，如果查找失败输出-1
以此类推输出下一个示例的结果

样例输入
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

样例输出
11 22 33 44 55 66 
2
1
2
4
3
4
-1
*/
