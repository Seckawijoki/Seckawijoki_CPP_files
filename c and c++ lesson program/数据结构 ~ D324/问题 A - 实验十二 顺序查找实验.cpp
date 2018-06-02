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
��Ŀ����
1����������
��һ���ؼ������У�δ�����У�˳�����һ���ؼ��֣����ز����Ƿ�ɹ�������ɹ�������ؼ������ڵ�λ���Լ����Ҵ�����
 
2��˳������㷨
�š��ڱ�ĵ�0λ�ã�������ֵKey
�ơ��ӱ������һ����¼��ʼ
�ǡ�������м�¼�Ĺؼ��ֺ͸���ֵKey�ıȽ�
�ȡ���ĳ����¼�Ƚ���ȣ�����ҳɹ�
�ɡ���ֱ����1����¼���Ƚϲ��ȣ�����Ҳ��ɹ�
����
�š���һ�У����Դ�����
�ơ�ÿ��������2�У�
��һ�У���һ������n��ʾ������Ŀ������n��������
�ڶ��У����ҵĹؼ��ֵ�ֵ��

���
�����Ƿ�ɹ���1��ʾ�ɹ���0��ʾ���ɹ���������λ�ã�0����ʾ���ɹ��������Ҵ�����

��������
2
5 2 4 3 5 7
4
6 2 6 8 4 3 1
7

�������
1 2 4
0 0 7

*/
