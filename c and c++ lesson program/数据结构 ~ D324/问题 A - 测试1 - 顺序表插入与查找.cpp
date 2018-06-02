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
��Ŀ����
1����������
������ʼ����
ʵ��˳���Ķ��塢���������롢����

2���㷨
˳���һά�������顢��󳤶ȡ�ʵ�ʳ���
˳���Ĳ��룺λ��i�ͺ��������ȫ������һλ,��ָ��λ��i����һ������,���ȼ�1
˳���Ĳ��ң������ؼ��ֵ�ֵKey����˳�����˳�����ֵΪKey������Ԫ��
�������һ��Ԫ�ؿ�ʼ�����Ԫ����ǰ�ң�����ҵ���0��λ�ã���λ�ã�����˵�����ɹ�����������λ��i

����
��1�У���һ������n��ʾ������Ŀ������n������
��2�У�����������λ�á�������
��3�У���������Ԫ�ص�ֵ���ؼ��֣�

���
ÿ������2��
��1�У����������ݺ��������鰴˳�����е�ȫ�����ݣ�Ԫ��֮���ÿո�������س�ǰ�޿ո�
��2�У������Ƿ�ɹ���1��ʾ�ɹ���0��ʾ���ɹ�����Ԫ�����ڵ�λ�ã����ɹ�ʱ��λ����0�������Ҵ���

��������
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

�������
7 9 3 2 8 6
1 4 3
3 6 4 5 8
0 0 6

*/
