# include <iostream>
# include <cstring>
using namespace std;
class TreeNode
{
public:
	char datum;
	TreeNode *leftchild;
	TreeNode *rightchild;
	TreeNode()
	{
		leftchild = NULL;
		rightchild = NULL;
	}
	~TreeNode()
	{
		if ( leftchild != NULL )delete leftchild;
		if ( rightchild != NULL )delete rightchild;
	}
};
class BinaryTree
{
private:
	TreeNode *root;
	char *array;
	int position;
	TreeNode *CreateTree_PreOrder()
	{
		char ch = array[position++];
		if ( ch == '0' )return NULL;
		TreeNode *t = new TreeNode ();
		t->datum = ch;
		t->leftchild = CreateTree_PreOrder();
		t->rightchild = CreateTree_PreOrder();
		return t;
		/*
		TreeNode *T;
		char ch;
		ch = array[position++];
		if ( ch == '0' )
			T = NULL;
		else
		{
			T = new TreeNode();
			T->datum = ch;
			T->leftchild = CreateTree_PreOrder();
			T->rightchild = CreateTree_PreOrder();
		}
		return T;
		*/
	}
	void InOrder( TreeNode *ne )
	{
		if ( ne == NULL )return;
		InOrder(ne->leftchild);
		cout<<ne->datum<<' ';
		InOrder(ne->rightchild);
	}
public:
	BinaryTree()
	{
		position = 0;
		array = NULL;
		root = NULL;
	}
	~BinaryTree()
	{
		if ( root != NULL ) delete root;
		delete [] array;
	}
	void CreateTree_PreOrder( char *list )
	{
		array = new char [strlen(list)];
		strcpy(array,list);
		position = 0;
		root = CreateTree_PreOrder();
	}
	void InOrder()
	{
		InOrder(root);
	}
};
int main()
{
	int i, number;
	char *node;
	cin>>number;
	node = new char [number];
	for ( i = 0 ; i < number ; ++i )
		cin>>node[i];
	BinaryTree nishinponoki;
	nishinponoki.CreateTree_PreOrder(node);
	nishinponoki.InOrder();
	cout<<endl;
	delete [] node;
	return 0;
}
/*
题目描述
1、问题描述
给定一棵按“先根”遍历存储表示的二叉树，
请中根遍历这棵二叉树。

2、二叉树创建说明
⑴、按“先根”遍历存储表示的二叉树中，如果在遍历过程中，
发现子树为空，输出0
⑵、例如：A有B子树，没有右子树，其“先根”遍历为A B 0 0 0
⑶、例如：A为根，B为A的右孩子；C为B的左孩子，D为B的右孩子，其“先根”遍历为A 0 B C 0 0 D 0 0

输入
第一行：先根遍历的二叉树结点数目（包括空结点）
第二行：n个“先根”遍历二叉树字符序列（用空格隔开）
（字符0表示空结点）

输出
第一行：二叉树的中根遍历序列（结点用空格隔开）
（最后一个结点之后也留有空格）

样例输入
9
A 0 B C 0 0 D 0 0

样例输出
A C B D 
*/
