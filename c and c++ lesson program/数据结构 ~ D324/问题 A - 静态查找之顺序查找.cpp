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
	int SqList_SequencialSearching( int item )
	{
		int i;
		array[0] = item;
		for ( i = length ; i >= 0 ; --i )
		if ( array[i] == item )
			return i;
	}
};
int main()
{
	int n, t, i, strayer, result;
	int *list;
	cin>>n;
	list = new int [n+1];
	for ( i = 1 ; i <= n ; ++i )
		cin>>list[i];
	SequenceList sequencial(list,n);
	cin>>t;
	while ( t-- )
	{
		cin>>strayer;
		result = sequencial.SqList_SequencialSearching(strayer);
		if ( result == 0 )
			cout<<"error\n";
		else
			cout<<result<<endl;
	}
	delete [] list;
	return 0;
}
/*
��Ŀ����
����һ�����к�Ҫ���ҵ���ֵ���ҳ���ֵ�ڶ����е�λ�ã�����λ�ô�1��ʼ

Ҫ��ʹ�ô��ڱ���˳������㷨

����
��һ������n����ʾ������n������
�ڶ�������n�����ݣ��������������ÿո����
����������t����ʾ��t��Ҫ���ҵ���ֵ
������������t����ֵ������t��

���
ÿ�����һ��Ҫ���ҵ���ֵ�ڶ��е�λ�ã�������Ҳ��ɹ�������ַ���error


��������
8
33 66 22 88 11 27 44 55
3
22
11
99

�������
3
5
error

*/
