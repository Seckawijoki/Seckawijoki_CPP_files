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
��Ŀ����
1����������
����һ���ؼ������У�����һ��������������
���Ը����Ĺؼ��ֽ��в��ң����ز����Ƿ�ɹ����ؼ������ڵ�λ���Լ����Ҵ�����

2���㷨
����ֵ������Ƚϣ�
�š�����ȣ����ҳɹ�
�ơ���С�ڣ����������������������Ϊ�գ������������
�ǡ������ڣ����������������������Ϊ�գ������������

����
�š���һ�У����Դ�����
�ơ�ÿ��������2�У�
��һ�У���һ������n��ʾ������Ŀ������n��������
�ڶ��У����ҵĹؼ��ֵ�ֵ��

���
�����Ƿ�ɹ���1����ʾ�ɹ���0��ʾ���ɹ�����
����λ�ã�����ȫ������Ϊ׼�������Ϊ1��㣩�����Ҵ������൱�����Ĳ�������

��������
2
5 2 4 3 5 7
4
6 2 6 8 4 3 1
7

�������
1 3 2
0 14 4
*/
