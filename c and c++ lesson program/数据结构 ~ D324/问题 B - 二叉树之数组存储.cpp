# include <iostream>
using namespace std;
class BinaryTree
{
private:
	int *TreeNode;
	int length;
	void PreOrder( int index )
	{
		if ( index <= length && TreeNode[index] != 0 )
		{
			cout<<TreeNode[index]<<' ';
			PreOrder( 2 * index );
			PreOrder( 2 * index + 1 );		
		}
	}
public:
	BinaryTree()
	{
		TreeNode = NULL;
	}
	~BinaryTree()
	{
		delete [] TreeNode;
	}
	BinaryTree( int size, int *array )
	{
		int i;
		length = size;
		TreeNode = new int [length+1];
		for ( i = 0 ; i < length ; ++i )
			TreeNode[i+1] = array[i];
	}
	void PreOrder()
	{
		PreOrder(1);
	}
};
int main()
{
	int t;
	cin>>t;
	while ( t-- )
	{
		int *digit, n, i;
		cin>>n;
		digit = new int [n];
		for ( i = 0 ; i < n ; ++i )
			cin>>digit[i];
		BinaryTree nishinponoki(n,digit);
		nishinponoki.PreOrder();
		cout<<endl;
	}
	return 0;
}
/*
��Ŀ����
���������Բ�������ķ������д洢���������е������������϶��£� 
�������Ҵ洢������������У�һ�����������ȫ�������Աȣ�
����ȫ������ȱ�ٵĽ�������������0����ʾ������ͼ��ʾ

����ͼ���Կ������ұߵ���һ����ͨ�Ķ���������������ߵ���ȫ�������Աȣ�
����������ȫ���������˵�5�Ž�㣬��������������0��ʾ��
ͬ������������ȫ�������еĵ�10��11�Ž�㣬������������Ҳ��0��ʾ��

���洢�����ݾ�Ϊ�Ǹ�����

����
��һ������һ������t����ʾ��t��������
�ڶ�����ÿ������һ�����飬���������鳤�ȣ����������������ݣ�
ÿ������֮���ÿո��������������ݶ��ǷǸ�����
��������t��

���
ÿ�����һ��ʾ����������������ÿ�����֮���ÿո����

��������
3
3 1 2 3
5 1 2 3 0 4
13 1 2 3 4 0 5 6 7 8 0 0 9 10

�������
1 2 3 
1 2 4 3 
1 2 4 7 8 3 5 9 10 6 

��ʾ
ע�������λ�úͶ�������ȡ����λ�ý��й�����
���߸��ӽ���������е�λ�ô���ĳ�ֹ���
����i, i+1, i/2,  i+1/2........����2i, 2i+1.......��ϸ�۲�Ŷ

*/
