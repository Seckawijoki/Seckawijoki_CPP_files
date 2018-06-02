# include <iostream>
using namespace std;
# define TRUE   1
# define FALSE  0
class BinaryTreeNode
{
public:
	int value;
	BinaryTreeNode *leftchild;
	BinaryTreeNode *rightchild;
};
class BinaryTree
{
private:
	int position;
	int *array;
	BinaryTreeNode *root;
	void InsertBinarySortTree( BinaryTreeNode *t )
	{
		if ( t == NULL )
		{
			BinaryTreeNode *p = new BinaryTreeNode ();
			p->value = array[position];
			t = p;
			InsertBinarySortTree(t->leftchild);
			InsertBinarySortTree(t->rightchild);
			++position;
		}
		else
		{
			if ( array[position] < t->value )
			{
				t->leftchild = p;
			}
		}
	}
	int SearchBinarySortTree( BinaryTreeNode *t, int item, int *times, int *depth )
	{
		if ( t == NULL )return FALSE;
		++ *depth;
		if ( t->value == item )
		{
			++ *times;
			return TRUE;
		}
		else
		{
			if ( item < t->value )SearchBinarySortTree(t->leftchild,item,times);
			if ( item > t->value )SearchBinarySortTree(t->rightchild,item,times);
		}
	}
public:
	void InsertBinarySortTree( int *list )
	{
		int i;
		array = new int [strlen(list)];
		for ( i = 0  ; i < strlen(list) ; ++i )
			array[i] = list[i];
		position = 0;
		InsertBinarySortTree(root);
	}
};
int main()
{
	
	return 0;
}
/*
题目描述
1、问题描述
给定一个关键字序列，生成一个二叉排序树；
并对给定的关键字进行查找；返回查找是否成功，关键字所在的位置以及查找次数。

2、算法
给定值与根结点比较：
⑴、若相等，查找成功
⑵、若小于，查找左子树；如果左子树为空，作插入操作；
⑶、若大于，查找右子树；如果右子树为空，作插入操作。

输入
⑴、第一行：测试次数。
⑵、每个样本分2行：
第一行：第一个数字n表示样本数目，其后跟n个样本；
第二行：查找的关键字的值。

输出
查找是否成功（1—表示成功，0表示不成功），
所在位置（以完全二叉树为准，根结点为1结点），查找次数（相当于树的层数）。

样例输入
2
5 2 4 3 5 7
4
6 2 6 8 4 3 1
7

样例输出
1 3 2
0 14 4
*/
