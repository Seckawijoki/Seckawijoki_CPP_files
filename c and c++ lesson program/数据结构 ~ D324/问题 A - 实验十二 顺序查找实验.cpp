# include <iostream>
using namespace std;
# define OK     1
# define ERROR  0
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
	int SqList_SequencialSearching( int item, int *times, int *position )
	{
		int i;
		*times = 1;
		array[0] = item;
		for ( i = length ; i >= 0 ; --i,  ++ *times )
		if ( array[i] == item )
		{
			*position =  i;
			break;
		}
		if ( *position == 0 )
			return ERROR;
		else
			return OK;
	}
};
int main()
{
	int n, t, i, strayer, result;
	int *list, *questing_time, *locating_site;
	questing_time = new int ();
	locating_site = new int ();
	cin>>t;
	while ( t-- )
	{
		cin>>n;
		list = new int [n+1];
		for ( i = 1 ; i <= n ; ++i )
			cin>>list[i];
		SequenceList sequencial(list,n);
		cin>>strayer;
		result = sequencial.SqList_SequencialSearching(strayer,questing_time,locating_site);
		cout<<result<<' '<<*locating_site<<' '<<*questing_time<<endl;
	}
	delete [] list;
	delete questing_time;
	delete locating_site;
	return 0;
}
/*
题目描述
1、问题描述
在一个关键字序列（未排序）中，顺序查找一个关键字；返回查找是否成功，如果成功，输出关键字所在的位置以及查找次数。
 
2、顺序查找算法
⑴、在表的第0位置，赋给定值Key
⑵、从表中最后一个记录开始
⑶、逐个进行记录的关键字和给定值Key的比较
⑷、若某个记录比较相等，则查找成功
⑸、若直到第1个记录都比较不等，则查找不成功
输入
⑴、第一行：测试次数。
⑵、每个样本分2行：
第一行：第一个数字n表示样本数目，其后跟n个样本；
第二行：查找的关键字的值。

输出
查找是否成功（1表示成功，0表示不成功），所在位置（0—表示不成功），查找次数。

样例输入
2
5 2 4 3 5 7
4
6 2 6 8 4 3 1
7

样例输出
1 2 4
0 0 7

*/
