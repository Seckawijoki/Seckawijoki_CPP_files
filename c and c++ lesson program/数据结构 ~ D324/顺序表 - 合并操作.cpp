# include <iostream>
using namespace std;
class SqList
{
private:
	int *member;
	int length;
	int maxsize;
public:
	SqList()
	{
		length = 0;
		maxsize = 1000;
		member = new int [maxsize];
	}
	SqList( int *array , int n )
	{
		length = n;
		maxsize = 1000;
		member = new int [maxsize];
		int i;
		for ( i = 0 ; i < length ; i++ )
			member[i] = array[i];
	}
	~SqList()
	{
		if ( member != NULL )delete [] member;
	}
	void Display ()
	{
		cout<<length<<' ';
		int i;
		for ( i = 0 ; i < length ; ++i )
			cout<<member[i]<<' ';cout<<endl;
	}
	void Merger ( SqList &sqa, SqList &sqb )
	{
		int i = 0, j = 0, k = 0;
		i = 0;
		while ( ( i <= sqa.length ) && ( j <= sqb.length ) )
		{
			if ( sqa.member[i] <= sqb.member[j] && i <= sqa.length )
				member[k++] = sqa.member[i++];
			else if ( sqa.member[i] > sqb.member[j] && j <= sqb.length )
				member[k++] = sqb.member[j++];
		}
		--k;
		while ( i <= sqa.length )
			member[k++] = sqa.member[i++];
		while ( j <= sqb.length )
			member[k++] = sqb.member[j++];
		length = sqa.length + sqb.length;
	}
};
int main()
{
	int i, m;
	int array[1000];
	cin>>m;
	for ( i = 0 ; i < m ; ++i )
		cin>>array[i];
	SqList sq1(array,m);
	cin>>m;
	for ( i = 0 ; i < m ; ++i )
		cin>>array[i];
	SqList sq2(array,m);
	SqList sq3;
	sq3.Merger(sq1,sq2);
	sq3.Display();
	return 0;
}
/*
题目描述

建立顺序表的类，属性包括：数组、实际长度、最大长度（设定为1000）
已知两个递增序列，把两个序列的数据合并到顺序表中，并使得顺序表的数据递增有序

输入
第1行先输入n表示有n个数据，接着输入n个数据，表示第1个序列，要求数据递增互不等
第2行先输入m表示有m个数据，接着输入m个数据，表示第2个序列，要求数据递增互不等

输出
顺序表内容包括顺序表的实际长度和数据，数据之间用空格隔开
第1行输出创建后的顺序表内容

样例输入
3 11 33 55
5 22 44 66 88 99


样例输出
8 11 22 33 44 55 66 88 99 
*/
