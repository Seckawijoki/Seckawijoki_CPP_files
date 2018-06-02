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
��Ŀ����
����һ�����к�Ҫ���ҵ���ֵ���ҳ���ֵ�ڶ����е�λ�ã�����λ�ô�1��ʼ
Ҫ��ʹ��˳�����������㷨��������������ҺͿ��ڲ��Ҷ����ò����ڱ�����ͷ��ʼ��˳����ҷ�����

����
��һ������n����ʾ������n������
�ڶ�������n�����ݣ��������������ÿո����
����������k����ʾ������Ϊk���飬kҲ��������ĳ���
����������k�����ݣ���ʾ��������ÿ��������ֵ
����������t����ʾ��t��Ҫ���ҵ���ֵ
������������t����ֵ������t��

���
ÿ�����һ��Ҫ���ҵ���ֵ�ڶ��е�λ�úͲ��Ҵ���������֮���ö̻��߸�����������Ҳ��ɹ�������ַ���error

��������
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

�������
3-4
error
12-8
error
18-9
error

*/
