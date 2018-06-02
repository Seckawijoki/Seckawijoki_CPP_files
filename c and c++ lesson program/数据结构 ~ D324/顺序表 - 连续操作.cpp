# include <iostream>
using namespace std;
class SqList
{
private:
	int length;
	int maxsize;
	int *array;
public:
	SqList()
	{
		length = 0;
		maxsize = 1000;
		array = new int [maxsize];
	}	
	SqList( int *list, int n )
	{
		length = n;
		maxsize = 1000;
		array = new int [maxsize];
		int i;
		for ( i = 0 ; i < length ; ++i )
			array[i] = list[i];
	}
	void Display()
	{
		int i;
		cout<<length<<' ';
		for ( i = 0 ; i < length ; ++i )
			cout<<array[i]<<' ';
		cout<<endl;
	}
	void MultiInsert( int start, int number, int item[] )
	{
		int i, j;
		for ( i = length - 1 ; i >= start - 1 ; --i )
			array[i+number] = array[i];
		for ( ++i, j = 0 ; j < number ; ++i, ++j )
			array[i] = item[j];
		length += number;
	}
	void MultiDelete( int start, int number )
	{
		int i;
		length -= number;
		for ( i = start - 1 ; i < length ; ++i )
			array[i] = array[i+number];
	}
};
int main()
{
	int i, n, begin;
	int list[1000];
	cin>>n;
	for ( i = 0 ; i < n ; ++i )
		cin>>list[i];
	SqList sq(list,n);
	sq.Display();
	cin>>begin>>n;
	for ( i = 0 ; i < n ; ++i )
		cin>>list[i];
	sq.MultiInsert(begin,n,list);
	sq.Display();
	cin>>begin>>n;
	sq.MultiDelete(begin,n);
	sq.Display();
	return 0;
}
/*
题目描述
建立顺序表的类，属性包括：数组、实际长度、最大长度（设定为1000）
该类具有以下成员函数：
构造函数：实现顺序表的初始化。
插入多个数据的multiinsert(int i, int n, int item[])函数，
实现在第i个位置，连续插入来自数组item的n个数据，即从位置i开始插入多个数据。
删除多个数据的multidel(int i, int n)函数，实
现从第i个位置开始，连续删除n个数据，即从位置i开始删除多个数据。
编写main函数测试该顺序表类。

输入
第1行先输入n表示有n个数据，即n是实际长度；接着输入n个数据
第2行先输入i表示插入开始的位置，再输入k表示有k个插入数据，接着输入k个数据
第3行先输入i表示删除开始的位置，再输入k表示要删除k个数据

输出
顺序表内容包括顺序表的实际长度和数据，数据之间用空格隔开
第1行输出创建后的顺序表内容
第2行输出执行连续插入后的顺序表内容
第3行输出执行连续删除后的顺序表内容

样例输入
6 11 22 33 44 55 66
2 3 99 88 77
4 5

样例输出
6 11 22 33 44 55 66 
9 11 99 88 77 22 33 44 55 66 
4 11 99 88 66 
*/
