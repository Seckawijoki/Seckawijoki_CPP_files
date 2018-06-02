/*
题目描述
以上是数组类Array的数据成员，请为它补充以下方法：
1、缺省构造函数，建立一个默认大小为10的数组；
2、有参数构造函数，参数为所要建立的数组的大小；
3、拷贝构造函数；
4、析构函数；
5、input方法，为数组元素赋值；
6、output方法，输出数组元素；
7、sort方法，给数组排序；
8、insert(int value)，插入方法，
将参数value的值插入到数组中；
9、mdelete(int index)，删除方法，
删除序号为index的元素。

输入
测试数据的组数 t
第一个数组的大小
数组元素的值
需要插入的值
需要删除的序号
........

输出
排序后的数组元素列表
插入后的数组元素列表
删除后的数组元素列表

样例输入
2
6
5 3 0 6 8 -1
-1
1
4
5 0 3 2
4
4

样例输出
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
		//原来的代码复杂。而且出i++的错。
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
