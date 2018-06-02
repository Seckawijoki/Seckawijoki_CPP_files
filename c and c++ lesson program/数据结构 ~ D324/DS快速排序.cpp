# include <iostream>
using namespace std;
int Partition( int array[1024], int low, int high )
{
	int pivotkey = array[low];
	array[0] = array[low];
	while ( low < high )
	{
		while ( low < high && array[high] >= pivotkey )--high;
		array[low] = array[high];
		while ( low < high && array[low]  <= pivotkey )++low;
		array[high] = array[low];
	}
	array[low] = array[0];
	return low;
}
int QuickSort( int array[1024], int low, int high )
{
	int pivotlocation;
	if ( low < high )
	{
		pivotlocation = Partition(array,low,high);
		QuickSort(array,low,pivotlocation-1);
		QuickSort(array,pivotlocation+1,high);
	}
}
int main()
{
	int t, n, i;
	int array[1024];
	cin>>t;
	while ( t-- )
	{
		cin>>n;
		for ( i = 1 ; i <= n ; ++i )
			cin>>array[i];
		QuickSort(array,1,n);
		for ( i = 1 ; i <= n ; ++i )
			cout<<array[i]<<' ';
		cout<<endl;
	}
	return 0;
}
/*
��Ŀ����
����һ���������У�ʹ�ÿ��������㷨���д�С���������

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
10
40 7 12 34 50 91 75 65 25 25
�������
6 22 55 111 333 444 
1 33 77 77 444 555 666 2222 
*/
