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
	int SqList_Bisearching( int item, int *times, int *position )
	{
		int i;
		int low = 1;
		int high = length;
		int middle = length + 1;
		*times = 0;
		*position = 0;
		while ( low <= high )
		{
			++ *times;
			middle = ( low + high )/2;
			/**/ if ( item == array[middle] )
			{
				*position = middle;
				return OK;
			}
			else if ( item <  array[middle] )
				high = middle - 1;
			else if ( item >  array[middle] )
				low = middle + 1;
		}
		*position = 0;
		return ERROR;
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
		result = sequencial.SqList_Bisearching(strayer,questing_time,locating_site);
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
��һ�����������У��۰����һ���ؼ��֣����ز����Ƿ�ɹ�������ɹ�������ؼ������ڵ�λ�úͲ��Ҵ�����
 
2�������㷨
�š�n�������С������������˳���BinList�У�KeyΪ����ֵ
�ơ���low��highָ�����Ԫ������������½硢�Ͻ磬��low=1, high=BinListLen
�ǡ���midָ�����������е㣬��mid=(low+high)/2?
�ȡ���Key��midָ��ļ�¼�ؼ��ֱȽ�
��Key=BinList[mid]�����ҳɹ�������
��Key<BinList[mid]����high=mid-1       [�ϰ�����]
��Key>BinList[mid]����low=mid+1        [�°�����]
�ɡ��ظ��ǡ��Ȳ�����ֱ��low>highʱ������ʧ�ܡ�
 
����
�š���һ�У����Դ�����
�ơ�ÿ��������2�У�
��һ�У���һ������n��ʾ������Ŀ������n��������
�ڶ��У����ҵĹؼ��ֵ�ֵ��

���
�����Ƿ�ɹ���1����ʾ�ɹ���0��ʾ���ɹ���������λ�ã�0����ʾ���ɹ��������Ҵ�����

��������
2
5 2 3 4 5 7
4
6 1 2 3 4 6 8
7

�������
1 3 1
0 0 3
*/
