/*
��Ŀ����
������������Array�����ݳ�Ա����Ϊ���������·�����
1��ȱʡ���캯��������һ��Ĭ�ϴ�СΪ10�����飻
2���в������캯��������Ϊ��Ҫ����������Ĵ�С��
3���������캯����
4������������
5��input������Ϊ����Ԫ�ظ�ֵ��
6��output�������������Ԫ�أ�
7��sort����������������
8��insert(int value)�����뷽����
������value��ֵ���뵽�����У�
9��mdelete(int index)��ɾ��������
ɾ�����Ϊindex��Ԫ�ء�

����
�������ݵ����� t
��һ������Ĵ�С
����Ԫ�ص�ֵ
��Ҫ�����ֵ
��Ҫɾ�������
........

���
����������Ԫ���б�
����������Ԫ���б�
ɾ���������Ԫ���б�

��������
2
6
5 3 0 6 8 -1
-1
1
4
5 0 3 2
4
4

�������
Constructor.
after sort:-1 0 3 5 6 8
after insert:-1 -1 0 3 5 6 8
after delete:-1 0 3 5 6 8
Distructor.
Constructor.
after sort:0 2 3 5
after insert:0 2 3 4 5
after delete:0 2 3 4
Distructor.
*/
# include <iostream>
# include <cstring>
using namespace std;
class Array
{
private:
	int *a;
	int size;
public:
	Array()
	{
		cout<<"Constructor.\n";
		size = 10;
		a = new int [10];	
	};
	Array( int n )
	{
		cout<<"Constructor.\n";
		size = n;
		a = new int [n+9];
	};
	Array( Array &a0 )
	{
		int i;
		size = a0.size;
		a = new int [sizeof(a0.a)/sizeof(int)+1];
		for ( i = 0 ; i < size ; i ++ )
			a[i] = a0.a[i];
	}
	~Array()
	{
		delete []a;
		cout<<"Distructor.\n";
	}
	void what_the_input()
	{
		int i;
		for ( i = 0 ; i < size ; i ++ )
			cin>>a[i];
	}
	void what_the_output()
	{
		int i;
		for ( i = 0 ; i < size-1 ; i ++ )
			cout<<a[i]<<' ';
		cout<<a[i]<<'\n';
	}
	void what_the_sort()
	{
		int i,j,tttt;
		for ( i = 0 ; i < size ; i ++ )
		{
			for ( j = i+1 ; j < size ; j ++ )
			{
				if ( a[i] > a[j] )
				{
					tttt = a[i];
					a[i] = a[j];
					a[j] = tttt;
				}
			}
		}	
	}
	void what_the_insert( int value )
	{
		//ԭ���Ĵ��븴�ӡ����ҳ�i++�Ĵ�
		a[size++] = value;
	}
	void what_the_delete( int index )
	{
		int i;
		for ( i = index ; i < size ; i ++ )
			a[i] = a[i+1];
		size--;
	}
};
int main()
{
	int t,size,value,index;
	cin>>t;
	while ( t-- )
	{
		cin>>size;
		Array a2(size);

		a2.what_the_input();
		cin>>value>>index;

		a2.what_the_sort();
		cout<<"after sort:";
		a2.what_the_output();
		
		a2.what_the_insert(value);
		a2.what_the_sort();
		cout<<"after insert:";
		a2.what_the_output();

		a2.what_the_delete(index);
		cout<<"after delete:";
		a2.what_the_output();
	}
	return 0;
}
