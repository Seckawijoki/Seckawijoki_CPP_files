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
��Ŀ����
1����������
����һ�ð����ȸ��������洢��ʾ�Ķ�������
���и�������ö�������

2������������˵��
�š������ȸ��������洢��ʾ�Ķ������У�����ڱ��������У�
��������Ϊ�գ����0
�ơ����磺A��B������û�����������䡰�ȸ�������ΪA B 0 0 0
�ǡ����磺AΪ����BΪA���Һ��ӣ�CΪB�����ӣ�DΪB���Һ��ӣ��䡰�ȸ�������ΪA 0 B C 0 0 D 0 0

����
��һ�У��ȸ������Ķ����������Ŀ�������ս�㣩
�ڶ��У�n�����ȸ��������������ַ����У��ÿո������
���ַ�0��ʾ�ս�㣩

���
��һ�У����������и��������У�����ÿո������
�����һ�����֮��Ҳ���пո�

��������
9
A 0 B C 0 0 D 0 0

�������
A C B D 
*/
