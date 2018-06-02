/*
题目描述
编写有界数组模板BoundArray（即检查对数组元素下标引用并在下标越界时终止程序的执行），
能够存储各种类型的数据。要求实现对数组进行排序的方法sort，及对数组进行查找的方法search。

输入
第一行先输入t，表示有t个测试用例
从第二行开始输入每个测试用例的数据。
首先输入数据类型，I表示int，D表示double，C表示char，接着输入数组的元素个数
然后输入每个元素
最后输入要查找的元素

输出
首先输出从小到大排序的元素
然后输出查找元素的结果，找到则输出下标，没找到则输出-1

样例输入
2
I 2
1 2
2
D 3
3.5 6.2 2.9
2.1

样例输出
1 2 
1
2.9 3.5 6.2 
-1
*/
# include <iostream>
# include <stdlib.h>
const int SIZE = 55;
using namespace std;
template < class T >
class BoundedArray
{
private:
	T array[SIZE];
	int size;
public:
	BoundedArray()
	{
		size = 0;
	}
	BoundedArray( T *p , int n )
	{
		if ( n <= SIZE )
		{
			int i;
			size = n;
			for ( i = 0 ; i < n ; i++ )
				array[i] = p[i];
		}
		else
			exit(0);
	}
	void Sort()
	{
		int i,j;
		for ( i = 0 ; i < size ; i++ )
			for ( j = i + 1 ; j < size ; j++ )
				if ( array[i] > array[j] )
				{
					array[i] = array[i] + array[j];
					array[j] = array[i] - array[j];
					array[i] = array[i] - array[j];
				}
	}
	int Search( int index )
	{
		int i;
		for ( i = 0 ; i < size ; i++ )
			if ( array[i] == index )
				return i;
		return -1;
	}
	void Display()
	{
		int i;
		for ( i = 0 ; i < size ; i++ )
			cout<<array[i]<<' ';
	}
};
int main()
{
	int t,n,i,value;
	char type;
	cin>>t;
	while ( t-- )
	{
		cin>>type>>n;
		if ( type == 'I' )
		{
			int p[55];
			for ( i = 0 ; i < n ; i++ )
				cin>>p[i];
			cin>>value;
			BoundedArray<int> list(p,n);
			list.Sort();
			list.Display();
			cout<<endl<<list.Search(value)<<endl;
		}
		else if ( type == 'D' )
		{
			double p[55];
			for ( i = 0 ; i < n ; i++ )
				cin>>p[i];
			cin>>value;
			BoundedArray<double> list(p,n);
			list.Sort();
			list.Display();
			cout<<endl<<list.Search(value)<<endl;
		}
		else if ( type == 'C' )
		{
			char p[55];
			for ( i = 0 ; i < n ; i++ )
				cin>>p[i];
			cin>>value;
			BoundedArray<char> list(p,n);
			list.Sort();
			list.Display();
			cout<<endl<<list.Search(value)<<endl;
		}
	}
	return 0;
}