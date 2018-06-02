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
题目描述
给出一个数据序列，建立二叉排序树，并实现删除功能
对二叉排序树进行中序遍历，可以得到有序的数据序列

输入
第一行输入t，表示有t个数据序列
第二行输入n，表示首个序列包含n个数据
第三行输入n个数据，都是自然数且互不相同，数据之间用空格隔开
第四行输入m，表示要删除m个数据
从第五行起，输入m行，每行一个要删除的数据，都是自然数
以此类推输入下一个示例

输出
第一行输出有序的数据序列，对二叉排序树进行中序遍历可以得到
从第二行起，输出删除第m个数据后的有序序列，输出m行
以此类推输出下一个示例的结果

样例输入
1
6
22 33 55 66 11 44
3
66
22
77

样例输出
11 22 33 44 55 66 
11 22 33 44 55 
11 33 44 55 
11 33 44 55 

提示
当删除数据不在序列中，那么删除操作等于不执行，所以输出序列不变化
*/
