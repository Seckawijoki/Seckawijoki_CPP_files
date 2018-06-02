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
��Ŀ����
����һ���������У�������ϣ���������෨��Ϊ��ϣ������ģ��Ϊ11����ϣ��ͻ������ַ���ͱ�ͷ����
����״β���ʧ�ܣ��Ͱ����ݲ��뵽��Ӧ��λ����
ʵ�ֹ�ϣ���ҹ���

����
��һ������n����ʾ��n������
�ڶ�������n�����ݣ�������Ȼ���һ�����ͬ������֮���ÿո����
����������t����ʾҪ����t������
�ӵ�������ÿ������һ��Ҫ���ҵ����ݣ�����������

���
ÿ�������Ӧ���ݵĲ��ҽ��

��������
6
11 23 39 48 75 62
6
39
52
52
63
63
52

�������
6 1
error
8 1
error
8 1
8 2

��ʾ
ע�⣬����������Ҫ��ͬ�Ĳ������ݣ������һ�β��Ҳ��ɹ��ͻ�ִ�в��룬
��ô�ڶ��β��ұ�Ȼ�ɹ����Ҳ��Ҵ���Ϊ1�Σ���Ϊ����ͷ���룩

����ʾ����������������52����һ�β���ʧ�ܾͰ�52���뵽λ��8����
���β��Ҿͳɹ��ˣ����Ե�һ�����error���ڶ��ξ����8 1

Ϊʲô����������52�����8 2
*/
