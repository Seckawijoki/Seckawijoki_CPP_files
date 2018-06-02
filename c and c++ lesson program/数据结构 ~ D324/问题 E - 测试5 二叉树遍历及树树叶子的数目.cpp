# include <iostream>
# include <stack>
# include <cstring>
using namespace std;
class BinaryTree
{
private:
	char *treenode;	
	int nodes;
	int CalculatingLeaves( int m )
	{
		if ( treenode[m] != '0' && m <= nodes )
		{
			if ( ( treenode[2*m] == '0' && treenode[2*m+1] == '0' )
			|| ( 2*m > nodes ) )
				return 1;
			else
			{
				int l = 0;
				l += CalculatingLeaves(2*m);
				l += CalculatingLeaves(2*m+1);
				return l;
			}
		}
		else 
			return 0;
	}
	void InOrder( int m )
	{
		int j;
		char root = treenode[1];
		char *visited = new char [nodes+1];
		for ( j = 1 ; j <= nodes ; ++j )
			visited[j] = treenode[j];
		cout<<"+++++++++++++++++++++++++++++++++++\n";
		stack <char> st;
		cout<<"***********************************\n";
		j = m;
		while ( j >= 1 && ( treenode[j] != '0' || !st.empty() ) ) 
		{
			while ( j <= nodes && treenode[j] != '0' && visited[j] != '0' )
			{
				st.push(treenode[j]);
				visited[j] = '0';
				j *= 2;
			}
			j /= 2;
			if ( !st.empty() )
			{
				cout<<st.top()<<' ';
				if ( st.top() == root )
					j = 2 * m + 1;
				else
					j = 2 * j + 1;
				st.pop();
			}
		}
		cout<<"j = "<<j<<endl;
		delete [] visited;
	}
public:
	int leaves;
	BinaryTree()
	{
		treenode = NULL;
		nodes = 0;
	}
	BinaryTree( int n , char *array )
	{
		nodes = n;
		treenode = new char [nodes];
		for ( int i = 1 ; i <= nodes ; ++i )
			treenode[i] = array[i];
	}
	~BinaryTree()
	{
		if ( treenode != NULL )delete [] treenode;
	}
	void CalculatingLeaves()
	{
		leaves = CalculatingLeaves(1);
	}
	void InOrder()
	{
		InOrder(1);
	}
};
int main ()
{
	int i, n;
	char *list;
	cin>>n;
	list = new char [n+1];
	for ( i = 1 ; i <= n ; ++i )
		cin>>list[i];
	BinaryTree nishinponoki(n,list);
	nishinponoki.CalculatingLeaves();
	cout<<nishinponoki.leaves<<endl;
	nishinponoki.InOrder();
	cout<<endl;
	return 0;
}
/*
题目描述
1、问题描述
给定一棵按顺序存储方式存储的二叉树，请中根遍历这棵二叉树，并求树叶子的数目。

2、二叉树创建说明
⑴、按顺序存储方式存储二叉树的每个结点，其中0表示空结点
⑵、结点从1开始编号，按完全二叉树方式排列，即
如果编号为i的结点有左孩子，则左孩子的编号为2i；
如果编号为i的结点有右孩子，则右孩子的编号为2i+1
⑶、例如：A 0 B 0 0 C D，其中，
A为根（编号为1），B（编号为3）为A的右孩子；
C（编号为6）为B的左孩子，D（编号为7）为B的右孩子
⑷、判断当前结点是否为空的方法：假设以顺序方式存储的二叉树的结点数为n，
如果当前结点编号为i，则：当i>n时，i结点为空结点；
当结点i的数据部分（i结点对应的字符）为‘0’时，i结点为空结点

3、要求
不能用递归，只能用自己创建的栈。

输入
第一行：二叉树结点数目（包括空结点）
第二行：n个二叉树结点字符（用空格隔开）（字符0表示空结点）

输出
第1行：叶子数目
第2行：二叉树的中根遍历序列（结点用空格隔开）（最后一个结点之后也留有空格）

样例输入
7
C D A 0 B E F

样例输出
3
D B C E A F 
*/
