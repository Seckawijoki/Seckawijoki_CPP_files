# include <iostream>
using namespace std;
# define OK      0
# define ERROR  -1
# define MAXLENGTH 1000
class SequencialList
{
private:
	int *array;
public:
	SequencialList()
	{
		array = new int [MAXLENGTH];
	}
	SequencialList( int list[] )
	{
		array = new int [MAXLENGTH];
		for ( int i = 0 ; i <= list[0] ; ++i )
			array[i] = list[i];
	}
	~SequencialList()
	{
		if ( array != NULL )delete [] array;
	}
	void SqList_Display()
	{
		for ( int i = 0 ; i <= array[0] ; ++i )
			cout<<array[i]<<' ';cout<<endl;
	}
	int SqList_Insert( int position, int item )
	{
		int i;
		if ( position < 1 || position > array[0] + 1 )return ERROR;
		for ( i = array[0] ; i >= position ; --i )
			array[i+1] = array[i];
		array[i+1] = item;
		++array[0];
	}
	int SqList_Delete_Item( int item )
	{
		int i, position = SqList_Search_Item(item);
		if ( position == ERROR )return ERROR;
		for ( i = position ; i < array[0] ; ++i )
			array[i] = array[i+1];
		--array[0];
		return OK;
	}
	int SqList_Delete_Position( int position )
	{
		int i;
		if ( position < 1 || position > array[0] )return ERROR;
		for ( i = position ; i < array[0] ; ++i )
			array[i] = array[i+1];
		--array[0];
		return OK;
	}
	int SqList_Search_Item( int item )
	{
		int i;
		for ( i = 1 ; i <= array[0] ; ++i )
			if ( array[i] == item )return i;
		return ERROR;
	}
	int SqList_Search_Position( int position )
	{
		if ( position < 1 || position > array[0] )return ERROR;
		return array[position];
	}
};
int main()
{
	int n, i, item, site, result;
	int list[MAXLENGTH];
	cin>>n;
	for ( i = 1 ; i <= n ; ++i )
		cin>>list[i];
	list[0] = n;
	SequencialList sq(list);
	sq.SqList_Display();
	cin>>site>>item;
	result = sq.SqList_Insert(site,item);
	if ( result == ERROR )cout<<"error\n";
	else sq.SqList_Display();
	cin>>site>>item;
	result = sq.SqList_Insert(site,item);
	if ( result == ERROR )cout<<"error\n";
	else sq.SqList_Display();
	
	cin>>site;
	result = sq.SqList_Delete_Position(site);
	if ( result == ERROR )cout<<"error\n";
	else sq.SqList_Display();
	cin>>site;
	result = sq.SqList_Delete_Position(site);
	if ( result == ERROR )cout<<"error\n";
	else sq.SqList_Display();
		
	cin>>site;
	result = sq.SqList_Search_Position(site);
	if ( result == ERROR )cout<<"error\n";
	else cout<<result<<"\n";
	cin>>site;
	result = sq.SqList_Search_Position(site);
	if ( result == ERROR )cout<<"error\n";
	else cout<<result<<"\n";
	return 0;
}
/*
��Ŀ����
ʵ��˳������C++���Ժ���ʵ��˳���

���԰��������顢ʵ�ʳ��ȡ���󳤶ȣ��趨Ϊ1000��

�������������������롢ɾ��������

�ඨ��ο�



����
��1��������n��ʾ��n�����ݣ���n��ʵ�ʳ��ȣ���������n������
��2������Ҫ�����λ�ú�������
��3������Ҫ�����λ�ú�������
��4������Ҫɾ����λ��
��5������Ҫɾ����λ��
��6������Ҫ���ҵ�λ��
��7������Ҫ���ҵ�λ��

���
����֮���ÿո����

��1������������˳������ݣ�����˳���ʵ�ʳ��Ⱥ�����

ÿ�ɹ�ִ��һ�β����������ɾ���������ִ�к��˳�������

ÿ�ɹ�ִ��һ�β��ң�������ҵ�������

���ִ�в���ʧ�ܣ��������롢ɾ�������ҵ�ʧ�ܣ�������ַ���error���������˳�������

��������
6 11 22 33 44 55 66
3 777
1 888
1
9
0
5
6 11 22 33 44 55 66 3 777 1 888 1 9 0 5

�������
6 11 22 33 44 55 66 
7 11 22 777 33 44 55 66 
8 888 11 22 777 33 44 55 66 
7 11 22 777 33 44 55 66 
error
error
44
��ʾ

��i��λ�����߼������λ�ã���1��ʼ����ʵ�ʱ�������飬��0��ʼ����Ӧ����i-1λ��

*/
