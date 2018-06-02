# include <iostream>
using namespace std;
void ShellInsert( int array[1024], int dk, int length )
{
	int i, j;
	for ( i = 1 + dk ; i <= length ; ++i )
	if ( array[i-dk] > array[i] )
	{
		array[0] = array[i];
		for ( j = i - dk ; j > 0 && array[j] > array[0] ; j -= dk )
			array[j+dk] = array[j];
		array[j+dk] = array[0];
	}
}
int main()
{
	int t, n, i, gap;
	int array[1024];
	cin>>t;
	while ( t-- )
	{
		cin>>n;
		for ( i = 1 ; i <= n ; ++i )
			cin>>array[i];
		gap = n/2 + n%2;
		while ( gap != 1 )
		{
			ShellInsert(array,gap,n);
			gap = gap/2 + gap%2;
		}
		ShellInsert(array,gap,n);
		for ( i = 1 ; i <= n ; ++i )
			cout<<array[i]<<' ';
		cout<<endl;
	}
	return 0;
}
/*
��Ŀ����
����һ���������У�ʹ��ϣ�������㷨���д�С���������

���gapʹ�����г���ѭ����2ֱ��1

����
��һ������t����ʾ��t������ʾ��
�ڶ�������n����ʾ��һ��ʾ����n������
����������n�����ݣ�����������������֮���ÿո����
�Դ�����

���
ÿ�����ÿ��ʾ������󣬴�С����Ľ��


��������
2
6
111 22 6 444 333 55
8
77 555 33 1 444 77 666 2222

�������
6 22 55 111 333 444 
1 33 77 77 444 555 666 2222 
*/
