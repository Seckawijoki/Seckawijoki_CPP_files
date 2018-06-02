/*
题目描述
实现顺序表的用C++语言和类实现顺序表

属性包括：数组、实际长度、最大长度（设定为1000）

操作包括：创建、插入、删除、查找

类定义参考

输入
第1行先输入n表示有n个数据，即n是实际长度；接着输入n个数据
第2行输入要插入的位置和新数据
第3行输入要插入的位置和新数据
第4行输入要删除的位置
第5行输入要删除的位置
第6行输入要查找的位置
第7行输入要查找的位置

输出
数据之间用空格隔开

第1行输出创建后的顺序表内容，包括顺序表实际长度和数据

每成功执行一次操作（插入或删除），输出执行后的顺序表内容

每成功执行一次查找，输出查找到的数据

如果执行操作失败（包括插入、删除、查找等失败），输出字符串error，不必输出顺序表内容

样例输入
6 11 22 33 44 55 66
3 777
1 888
1
9
0
5

样例输出
6 11 22 33 44 55 66 
7 11 22 777 33 44 55 66 
8 888 11 22 777 33 44 55 66 
7 11 22 777 33 44 55 66 
error
error
44
提示

第i个位置是逻辑意义的位置，从1开始，在实际编程用数组，从0开始，对应数组i-1位置
*/
# include <iostream>
# include <string>
using namespace std;

# define ok     0
# define error -1

class SqList
{
private:
	int *list;
	int maxsize;
	int size;
public:
	SqList()
	{
		maxsize = 1000;
		size = 0;
		list = new int [maxsize];
	}
	SqList( int *array, int length )
	{
		size = length; 
		list = new int [maxsize];
		int j;
		for ( j = 0 ; j < size ; j++ )
			list[j] = array[j];
	}
	~SqList()
	{
		delete [] list;
	}
	int list_size()
	{
		return size;
	}
	int list_insert( int i , int item )
	{
		if ( i > size || i < 1 )
		{
			cout<<"error\n";
			return error;
		}
		else
		{
			i--;
			int j;
			for ( j = size ; j >= i ; j-- )
				list[j+1] = list[j];
			list[i] = item;
			size++;
			return ok;
		}
	}
	int list_delete( int i )
	{
		if ( i > size + 1 || i < 1 )
		{
			cout<<"error\n";
			return error;
		}
		else
		{
			size--;
			int j;
			for ( j = --i ; j <= size ; j++ )
				list[j] = list[j+1];
			return ok;
		}
	}
	int list_get( int i )
	{
		if ( i > size + 1 || i < 1 )
		{
			cout<<"error\n";
			return error;
		}
		else
			return list[--i];
	}
	void list_display()
	{
		int j;
		cout<<size<<' ';
		for ( j = 0 ; j < size ; j++ )
			cout<<list[j]<<' ';
		cout<<endl;
	}
};
int main()
{
	int length, *array, i,j, item, booleanvalue;
	cin>>length;
	array = new int [length];
	for ( j = 0 ; j < length ; j++ )
		cin>>array[j];

	SqList list123(array,length);
	list123.list_display();

	cin>>i>>item;
	booleanvalue = list123.list_insert(i,item);
	if ( booleanvalue == ok ) list123.list_display();
	cin>>i>>item;
	booleanvalue = list123.list_insert(i,item);
	if ( booleanvalue == ok ) list123.list_display();

	cin>>i;
	booleanvalue = list123.list_delete(i);
	if ( booleanvalue == ok ) list123.list_display();
	cin>>i;
	booleanvalue = list123.list_delete(i);
	if ( booleanvalue == ok ) list123.list_display();

	cin>>i;
	booleanvalue = list123.list_get(i);
	if ( booleanvalue != error ) cout<<booleanvalue<<endl;
	cin>>i;
	booleanvalue = list123.list_get(i);
	if ( booleanvalue != error ) cout<<booleanvalue<<endl;

	delete [] array;
	return 0;
}