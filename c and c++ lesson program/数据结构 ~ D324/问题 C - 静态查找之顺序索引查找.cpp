# include <iostream>
using namespace std;
class SequenceList
{
private:
	int *array;
	int length;
public:
	SequenceList()
	{
		array = NULL;
		length = 0;
	}
	SequenceList( int *list, int size )
	{
		int i;
		length = size;
		array = new int [length+1];
		for ( i = 1 ; i <= length ; ++i )
			array[i] = list[i];
	}
	~SequenceList()
	{
		delete [] array;
	}
	int SqList_Bisearching( int item )
	{
		int low = 1;
		int high = length;
		int middle = length + 1;
		while ( low <= high )
		{
			middle = ( low + high ) /2;
			if ( item == array[middle] )
				return middle;
			else if ( item >  array[middle] )
				low = middle + 1;
			else if ( item <  array[middle] )
				high = middle - 1;
		}
		return 0;
	}
	int SqList_IndexSearching( int item, int head, int tail, int *times )
	{
		//cout<<head<<"==="<<tail<<"==="<<*times<<endl;
		int i;
		++ *times;
		for ( i = head ; i <= tail ; ++i, ++ *times )
		if ( array[i] == item )
			return i;
		return 0;
	}
};
int main()
{
	int n, t, k, i, strayer, result;
	int *list, *blockboss, *questing_time;
	questing_time = new int ();
	cin>>n;
	list = new int [n+1];
	for ( i = 1 ; i <= n ; ++i )
		cin>>list[i];
	SequenceList sequencial(list,n);
	cin>>k;
	blockboss = new int [k];
	for ( i = 0 ; i < k ; ++i )
		cin>>blockboss[i];
	cin>>t;
	while ( t-- )
	{
		cin>>strayer;
		/**/ if ( strayer <= blockboss[0] )
		{
			*questing_time = 1;
			result = sequencial.SqList_IndexSearching(strayer,1,n/k,questing_time);
		}
		else if ( strayer > blockboss[0]  && strayer <= blockboss[1] )
		{
			*questing_time = 2;
			result = sequencial.SqList_IndexSearching(strayer,1+n/k,2*n/k,questing_time);
		}
			
		else if ( strayer > blockboss[1]  && strayer <= blockboss[2] )
		{
			*questing_time = 3;
			result = sequencial.SqList_IndexSearching(strayer,1+2*n/k,n,questing_time);
		}
		else
			 result =  0;
		if ( result == 0 )
			cout<<"error\n";
		else
			cout<<result<<'-'<<*questing_time<<endl;
	}
	delete [] list;
	delete [] blockboss;
	delete questing_time;
	return 0;
}
/*
题目描述
给出一个队列和要查找的数值，找出数值在队列中的位置，队列位置从1开始
要求使用顺序索引查找算法，其中索引表查找和块内查找都采用不带哨兵、从头开始的顺序查找方法。

输入
第一行输入n，表示主表有n个数据
第二行输入n个数据，都是正整数，用空格隔开
第三行输入k，表示主表划分为k个块，k也是索引表的长度
第四行输入k个数据，表示索引表中每个块的最大值
第五行输入t，表示有t个要查找的数值
第六行起，输入t个数值，输入t行

输出
每行输出一个要查找的数值在队列的位置和查找次数，数据之间用短划线隔开，如果查找不成功，输出字符串error

样例输入
18
22 12 13 8 9 20 33 42 44 38 24 48 60 58 74 57 86 53
3
22 48 86
6
13
5
48
40
53
90

样例输出
3-4
error
12-8
error
18-9
error

*/
