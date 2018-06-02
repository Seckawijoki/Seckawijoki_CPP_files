# include <iostream>
using namespace std;
# define OK     1
# define ERROR  0
class SequenceList
{
private:
	int *data;
	int size;
	int MAXSIZE;
public:
	SequenceList()
	{
		size = 0;
		MAXSIZE = 1000;
		data = new int [MAXSIZE];
	}
	SequenceList( int length, int *intruder )
	{
		size = length;
		MAXSIZE = 1000;
		data = new int [MAXSIZE];
		int i;
		for ( i = 0 ; i < size ; ++i )
			data[i] = intruder[i];
	}
	void SqList_Insert( int index, int item )
	{
		int i;
		--index;
		for ( i = size - 1 ; i >= index ; --i )
			data[i+1] = data[i];
		data[index] = item;
		++size;
	}
	int SqList_Searching( int item, int *searching_time, int *resultant_site )
	{
		int i;
		int boolean_value = ERROR;
		for ( i = size - 1 ; i >= 0 ; --i )
		{
			++(*searching_time);
			if ( item == data[i] )
			{
				boolean_value = OK;
				*resultant_site = i + 1;
				break;
			}
		}
		!boolean_value ? ++(*searching_time) : 1;
		return boolean_value ? OK : ERROR;
	}
	void SqList_Display ()
	{
		int i;
		for ( i = 0 ; i < size - 1 ; ++i )
			cout<<data[i]<<' ';
		cout<<data[i]<<endl;
	}
};
int main()
{
	int t, n, i, digit, location, result;
	int *questing_time, *consequential_site;
	int *immigrant;
	cin>>t;
	while ( t-- )
	{
		cin>>n;
		questing_time = new int (0);
		consequential_site = new int (0);
		immigrant = new int [n];
		for ( i = 0 ; i < n ; ++i )
			cin>>immigrant[i];
		cin>>location>>digit;
		SequenceList sq(n,immigrant);
		sq.SqList_Insert(location,digit);
		sq.SqList_Display();
		cin>>digit;
		result = sq.SqList_Searching(digit,questing_time,consequential_site);
		cout<<result<<' '<<*consequential_site<<' '<<*questing_time<<endl;
	}
	delete questing_time;
	delete consequential_site;
	delete [] immigrant;
	return 0;
}
/*
题目描述
1、问题描述
给出初始数据
实现顺序表的定义、创建、插入、查找

2、算法
顺序表：一维数据数组、最大长度、实际长度
顺序表的插入：位置i和后面的数据全部后移一位,在指定位置i插入一个数据,长度加1
顺序表的查找：给出关键字的值Key，在顺序表中顺序查找值为Key的数据元素
（从最后一个元素开始，逐个元素向前找，如果找到第0个位置（空位置），则说明不成功），并返回位置i

输入
第1行：第一个数字n表示样本数目，其后跟n个样本
第2行：插入新数据位置、新数据
第3行：查找数据元素的值（关键字）

输出
每个测试2行
第1行：插入新数据后，数据数组按顺序排列的全部数据（元素之间用空格隔开，回车前无空格）
第2行：查找是否成功（1表示成功，0表示不成功），元素所在的位置（不成功时，位置是0），查找次数

样例输入
2
5 9 3 2 8 6
1 7
2
4 3 6 4 8
4 5
2

2 5 9 3 2 8 6 1 7 2 4 3 6 4 8 4 5 2

2
11 135 -356 586474 -23 64 3 -37 14 246 -262627 865
12 2333
3
8 246 357357 13515 363636 242424 121212 6676767 990909
1 1451151
171717

样例输出
7 9 3 2 8 6
1 4 3
3 6 4 5 8
0 0 6

*/
