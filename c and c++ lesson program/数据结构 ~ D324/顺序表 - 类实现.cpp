# include <iostream>
using namespace std;
# define OK      0
# define ERROR  -1
# define MAXLENGTH 1000
class SequencialList
{
private:
	int *array;
public:
	SequencialList()
	{
		array = new int [MAXLENGTH];
	}
	SequencialList( int list[] )
	{
		array = new int [MAXLENGTH];
		for ( int i = 0 ; i <= list[0] ; ++i )
			array[i] = list[i];
	}
	~SequencialList()
	{
		if ( array != NULL )delete [] array;
	}
	void SqList_Display()
	{
		for ( int i = 0 ; i <= array[0] ; ++i )
			cout<<array[i]<<' ';cout<<endl;
	}
	int SqList_Insert( int position, int item )
	{
		int i;
		if ( position < 1 || position > array[0] + 1 )return ERROR;
		for ( i = array[0] ; i >= position ; --i )
			array[i+1] = array[i];
		array[i+1] = item;
		++array[0];
	}
	int SqList_Delete_Item( int item )
	{
		int i, position = SqList_Search_Item(item);
		if ( position == ERROR )return ERROR;
		for ( i = position ; i < array[0] ; ++i )
			array[i] = array[i+1];
		--array[0];
		return OK;
	}
	int SqList_Delete_Position( int position )
	{
		int i;
		if ( position < 1 || position > array[0] )return ERROR;
		for ( i = position ; i < array[0] ; ++i )
			array[i] = array[i+1];
		--array[0];
		return OK;
	}
	int SqList_Search_Item( int item )
	{
		int i;
		for ( i = 1 ; i <= array[0] ; ++i )
			if ( array[i] == item )return i;
		return ERROR;
	}
	int SqList_Search_Position( int position )
	{
		if ( position < 1 || position > array[0] )return ERROR;
		return array[position];
	}
};
int main()
{
	int n, i, item, site, result;
	int list[MAXLENGTH];
	cin>>n;
	for ( i = 1 ; i <= n ; ++i )
		cin>>list[i];
	list[0] = n;
	SequencialList sq(list);
	sq.SqList_Display();
	cin>>site>>item;
	result = sq.SqList_Insert(site,item);
	if ( result == ERROR )cout<<"error\n";
	else sq.SqList_Display();
	cin>>site>>item;
	result = sq.SqList_Insert(site,item);
	if ( result == ERROR )cout<<"error\n";
	else sq.SqList_Display();
	
	cin>>site;
	result = sq.SqList_Delete_Position(site);
	if ( result == ERROR )cout<<"error\n";
	else sq.SqList_Display();
	cin>>site;
	result = sq.SqList_Delete_Position(site);
	if ( result == ERROR )cout<<"error\n";
	else sq.SqList_Display();
		
	cin>>site;
	result = sq.SqList_Search_Position(site);
	if ( result == ERROR )cout<<"error\n";
	else cout<<result<<"\n";
	cin>>site;
	result = sq.SqList_Search_Position(site);
	if ( result == ERROR )cout<<"error\n";
	else cout<<result<<"\n";
	return 0;
}
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
6 11 22 33 44 55 66 3 777 1 888 1 9 0 5

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
