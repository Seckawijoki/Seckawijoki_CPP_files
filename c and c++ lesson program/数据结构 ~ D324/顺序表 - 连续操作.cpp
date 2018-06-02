# include <iostream>
using namespace std;
class SqList
{
private:
	int length;
	int maxsize;
	int *array;
public:
	SqList()
	{
		length = 0;
		maxsize = 1000;
		array = new int [maxsize];
	}	
	SqList( int *list, int n )
	{
		length = n;
		maxsize = 1000;
		array = new int [maxsize];
		int i;
		for ( i = 0 ; i < length ; ++i )
			array[i] = list[i];
	}
	void Display()
	{
		int i;
		cout<<length<<' ';
		for ( i = 0 ; i < length ; ++i )
			cout<<array[i]<<' ';
		cout<<endl;
	}
	void MultiInsert( int start, int number, int item[] )
	{
		int i, j;
		for ( i = length - 1 ; i >= start - 1 ; --i )
			array[i+number] = array[i];
		for ( ++i, j = 0 ; j < number ; ++i, ++j )
			array[i] = item[j];
		length += number;
	}
	void MultiDelete( int start, int number )
	{
		int i;
		length -= number;
		for ( i = start - 1 ; i < length ; ++i )
			array[i] = array[i+number];
	}
};
int main()
{
	int i, n, begin;
	int list[1000];
	cin>>n;
	for ( i = 0 ; i < n ; ++i )
		cin>>list[i];
	SqList sq(list,n);
	sq.Display();
	cin>>begin>>n;
	for ( i = 0 ; i < n ; ++i )
		cin>>list[i];
	sq.MultiInsert(begin,n,list);
	sq.Display();
	cin>>begin>>n;
	sq.MultiDelete(begin,n);
	sq.Display();
	return 0;
}
/*
��Ŀ����
����˳�����࣬���԰��������顢ʵ�ʳ��ȡ���󳤶ȣ��趨Ϊ1000��
����������³�Ա������
���캯����ʵ��˳���ĳ�ʼ����
���������ݵ�multiinsert(int i, int n, int item[])������
ʵ���ڵ�i��λ�ã�����������������item��n�����ݣ�����λ��i��ʼ���������ݡ�
ɾ��������ݵ�multidel(int i, int n)������ʵ
�ִӵ�i��λ�ÿ�ʼ������ɾ��n�����ݣ�����λ��i��ʼɾ��������ݡ�
��дmain�������Ը�˳����ࡣ

����
��1��������n��ʾ��n�����ݣ���n��ʵ�ʳ��ȣ���������n������
��2��������i��ʾ���뿪ʼ��λ�ã�������k��ʾ��k���������ݣ���������k������
��3��������i��ʾɾ����ʼ��λ�ã�������k��ʾҪɾ��k������

���
˳������ݰ���˳����ʵ�ʳ��Ⱥ����ݣ�����֮���ÿո����
��1������������˳�������
��2�����ִ������������˳�������
��3�����ִ������ɾ�����˳�������

��������
6 11 22 33 44 55 66
2 3 99 88 77
4 5

�������
6 11 22 33 44 55 66 
9 11 99 88 77 22 33 44 55 66 
4 11 99 88 66 
*/
