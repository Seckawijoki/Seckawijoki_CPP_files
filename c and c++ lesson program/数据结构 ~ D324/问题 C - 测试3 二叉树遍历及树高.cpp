# include <iostream>
using namespace std;
class BinaryTree
{
private:
	char TreeNode[128];
	int length;
	void PostOrder( int index )
	{
		if ( index <= length && TreeNode[index] != '0' )
		{
			PostOrder( 2 * index );
			PostOrder( 2 * index + 1 );
			cout<<TreeNode[index]<<' ';
		}
	}
public:
	BinaryTree( int size, char *array )
	{
		length = size;
		int i;
		for ( i = 0 ; i < length ; ++i )
			TreeNode[i+1] = array[i];
	}
	void PostOrder()
	{
		PostOrder(1);
	}
	int TreeHeight()
	{
		if ( length == 0 || TreeNode[1] == '0' )
			return 0;
		else
		{
			int l = length;
			int height = 0;
			while ( l )
			{
				l /= 2;	
				++height;
			}
			return height;
		}
	}
};
int main()
{
	int n, i;
	char *character;
	cin>>n;
	character = new char [n];
	for ( i = 0 ; i < n ; ++i )
		cin>>character[i];
	BinaryTree nishinponoki(n,character);
	cout<<nishinponoki.TreeHeight()<<endl;
	nishinponoki.PostOrder();
	cout<<endl;
	delete [] character;
	return 0;
}
/*
题目描述
1、问题描述
给定一棵按顺序存储方式存储的二叉树，请后根遍历这棵二叉树。

2、二叉树创建说明
⑴、按顺序存储方式存储二叉树的每个结点，其中0表示空结点
⑵、结点从1开始编号，按完全二叉树方式排列，
即如果编号为i的结点有左孩子，则左孩子的编号为2i；
如果编号为i的结点有右孩子，则右孩子的编号为2i+1
⑶、例如：A 0 B 0 0 C D，其中，A为根（编号为1），B（编号为3）为A的右孩子；
C（编号为6）为B的左孩子，D（编号为7）为B的右孩子
⑷、判断当前结点是否为空的方法：
假设以顺序方式存储的二叉树的结点数为n，如果当前结点编号为i，则：
当i>n时，i结点为空结点；当结点i的数据部分（i结点对应的字符）为‘0’时，i结点为空结点

输入
第一行：二叉树结点数目（包括空结点）
第二行：n个二叉树结点字符（用空格隔开）（字符0表示空结点）

输出
第1行：树高
第2行：二叉树的后根遍历序列（结点用空格隔开）（最后一个结点之后也留有空格）

样例输入
7 A 0 B 0 0 C D
5 A B D 0 C
3 A B C
8 A B E C 0 F 0 D

样例输出
3
C D B A 

*/
