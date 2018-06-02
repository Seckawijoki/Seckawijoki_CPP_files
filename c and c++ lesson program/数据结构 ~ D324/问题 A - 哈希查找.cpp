# include <iostream>
using namespace std;
# define OK      1
# define ERROR   0
# define UNKNOWN 99999
# define module  11
class ChainBlock
{
public:
	int datum;
	ChainBlock *nextblock;
	ChainBlock()
	{
		datum = UNKNOWN;
		nextblock = NULL;
	}
	~ChainBlock()
	{
		if ( nextblock != NULL )delete nextblock;
	}
};
class HashTable
{
private:
	ChainBlock *listblock;
public:
	HashTable()
	{
		listblock = new ChainBlock [module];
	}
	~HashTable()
	{
		if ( listblock != NULL )delete [] listblock;
	}
	void CreateHashTable_InsertHeader( int array[module], int number )
	{
		int i, site;
		ChainBlock *temporary;
		for ( i = 0 ; i < number ; ++i )
		{
			temporary = new ChainBlock ();
			site = array[i] %module;
			temporary->datum = array[i];
			temporary->nextblock = listblock[site].nextblock;
			listblock[site].nextblock = temporary;
		}
	}
	int HashSearch( int item, int *position, int *times )
	{
		int site;
		ChainBlock *provisional;
		site = item %module;
		
		*position = site;
		provisional = listblock[site].nextblock;
		while ( provisional != NULL )
		{
			++ *times;
			if ( provisional->datum == item )
				return OK;
			provisional = provisional->nextblock;
		}
			
		provisional = new ChainBlock ();
		provisional->datum = item;
		provisional->nextblock = listblock[site].nextblock;
		listblock[site].nextblock = provisional;
		return ERROR;
	}
	void DisplayHashTable()
	{
		int i;
		ChainBlock *employee;
		for ( i = 0 ; i < module ; ++i )
		{
			cout<<" [ "<<i<<" ] : ";
			if ( listblock[i].nextblock == NULL )
				cout<<" -> null\n";
			else
			{
				employee = listblock[i].nextblock;
				while ( employee != NULL )
				{
					cout<<" -> "<<employee->datum;
					employee = employee->nextblock;
				}
				cout<<endl;
			}
		}
	}
};
int main()
{
	int n, i, strayer, result;
	int list[module] = {0};
	int *questing_site, *questing_times;
	questing_site  = new int ();
	questing_times = new int ();
	cin>>n;
	for ( i = 0 ; i < n ; ++i )
		cin>>list[i];
		
//	for ( i = 0 ; i < n ; ++i )cout<<list[i]<<' ';cout<<endl;
	HashTable hasshuteiburu;
//	for ( i = 0 ; i < n ; ++i )hasshuteiburu.HashSearch(list[i],questing_site,questing_times);
	hasshuteiburu.CreateHashTable_InsertHeader(list,n);
//	hasshuteiburu.DisplayHashTable();
	cin>>n;
	while ( n-- )
	{
		cin>>strayer;
		*questing_times = 0;
		result = hasshuteiburu.HashSearch(strayer,questing_site,questing_times);
		if ( result == ERROR )
			cout<<"error\n";
		else
			cout<<*questing_site<<' '<<*questing_times<<endl;
	}
//	hasshuteiburu.DisplayHashTable();
	delete questing_site;
	delete questing_times;
	return 0;
}
/*
题目描述
给出一个数据序列，建立哈希表，采用求余法作为哈希函数，模数为11，哈希冲突用链地址法和表头插入
如果首次查找失败，就把数据插入到相应的位置中
实现哈希查找功能

输入
第一行输入n，表示有n个数据
第二行输入n个数据，都是自然数且互不相同，数据之间用空格隔开
第三行输入t，表示要查找t个数据
从第四行起，每行输入一个要查找的数据，都是正整数

输出
每行输出对应数据的查找结果

样例输入
6
11 23 39 48 75 62
6
39
52
52
63
63
52

样例输出
6 1
error
8 1
error
8 1
8 2

提示
注意，当两次输入要相同的查找数据，如果第一次查找不成功就会执行插入，
那么第二次查找必然成功，且查找次数为1次（因为做表头插入）

例如示例数据中输入两次52，第一次查找失败就把52插入到位置8，第
二次查找就成功了，所以第一次输出error，第二次就输出8 1

为什么第三次输入52会输出8 2
*/
