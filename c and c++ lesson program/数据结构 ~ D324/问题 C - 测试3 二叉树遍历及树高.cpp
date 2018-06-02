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
��Ŀ����
1����������
����һ�ð�˳��洢��ʽ�洢�Ķ�����������������ö�������

2������������˵��
�š���˳��洢��ʽ�洢��������ÿ����㣬����0��ʾ�ս��
�ơ�����1��ʼ��ţ�����ȫ��������ʽ���У�
��������Ϊi�Ľ�������ӣ������ӵı��Ϊ2i��
������Ϊi�Ľ�����Һ��ӣ����Һ��ӵı��Ϊ2i+1
�ǡ����磺A 0 B 0 0 C D�����У�AΪ�������Ϊ1����B�����Ϊ3��ΪA���Һ��ӣ�
C�����Ϊ6��ΪB�����ӣ�D�����Ϊ7��ΪB���Һ���
�ȡ��жϵ�ǰ����Ƿ�Ϊ�յķ�����
������˳��ʽ�洢�Ķ������Ľ����Ϊn�������ǰ�����Ϊi����
��i>nʱ��i���Ϊ�ս�㣻�����i�����ݲ��֣�i����Ӧ���ַ���Ϊ��0��ʱ��i���Ϊ�ս��

����
��һ�У������������Ŀ�������ս�㣩
�ڶ��У�n������������ַ����ÿո���������ַ�0��ʾ�ս�㣩

���
��1�У�����
��2�У��������ĺ���������У�����ÿո�����������һ�����֮��Ҳ���пո�

��������
7 A 0 B 0 0 C D
5 A B D 0 C
3 A B C
8 A B E C 0 F 0 D

�������
3
C D B A 

*/
