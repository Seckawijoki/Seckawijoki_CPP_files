# include <iostream>
using namespace std;
# define OK      1
# define ERROR   0
# define UNKNOWN 99999
# define module  5
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
	void CreateHashTable_InsertHeader( int array[64], int number )
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
		++ *times;
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
	int t, n, i, strayer, result;
	int list[64] = {0};
	int *questing_site, *questing_times;
	questing_site  = new int ();
	questing_times = new int ();
	cin>>t;
	while ( t-- )
	{
		cin>>n;
		for ( i = 0 ; i < n ; ++i )
			cin>>list[i];
			
	//	for ( i = 0 ; i < n ; ++i )cout<<list[i]<<' ';cout<<endl;
		HashTable hasshuteiburu;
	//	for ( i = 0 ; i < n ; ++i )hasshuteiburu.HashSearch(list[i],questing_site,questing_times);
		hasshuteiburu.CreateHashTable_InsertHeader(list,n);
	//	hasshuteiburu.DisplayHashTable();
		cin>>strayer;
		*questing_site = 0;
		*questing_times = 0;
		result = hasshuteiburu.HashSearch(strayer,questing_site,questing_times);
		cout<<result<<' '<<*questing_site<<' '<<*questing_times<<endl;
	//	hasshuteiburu.DisplayHashTable();
	}
	delete questing_site;
	delete questing_times;
	return 0;
}
/*
��Ŀ����
1����������
����ɢ�б�ʽ���Թؼ��ֽ��в��ҡ�

2�������㷨
�š����ù�ϣ��������������������ϣ��Ϊ5������¼�Ĺؼ��ּ������¼�Ĵ洢��ַ
�ơ�ֱ�ӵ�ָ����ַ���в���
�ǡ�������Ҳ��ɹ�������ã���ͷ���룩����ַ��������¼���뵽ָ����ַ���������ͷ�ϡ�


����
�š���һ�У����Դ�����
�ơ�ÿ��������2�У�
��һ�У���һ������n��ʾ������Ŀ������n��������
�ڶ��У����ҵĹؼ��ֵ�ֵ��

���
�����Ƿ�ɹ���1����ʾ�ɹ���0��ʾ���ɹ���������λ�ã���0��ʼ�������Ҵ�����

��������
2
5 2 4 9 5 7
4
6 2 6 8 4 9 1
7

�������
1 4 2
0 2 2
*/
