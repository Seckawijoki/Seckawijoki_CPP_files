# include <iostream>
using namespace std;
int Function( int array[1000], int n )
{
	int i, j, number, index, maxtimes, minimum;
	int copy[10000] = {0};
	int *types = new int [n];
	int *times = new int [n];
	for ( i = 0 ; i < n ; ++i )
		++copy[array[i]];
	for ( i = 0, j = 0 ; i < 10000 ; ++i )if ( copy[i] )
	{
		types[j] = i;
		times[j] = copy[i];
		++j;
	}
	maxtimes = times[0];
	for ( i = 0 ; i < j ; ++i )
		if ( maxtimes < times[i] )
		{
			maxtimes = times[i];
			index = i;
		}
	number = 0;
	for ( i = 0 ; i < j ; ++i )if ( maxtimes == times[i] )
		copy[number++] = types[i];
	minimum = copy[0];
	for ( i = 0 ; i < number ; ++i )if ( minimum > copy[i] )
		minimum = copy[i];
	return minimum;
}
int main()
{
		int i, n;
		int array[1000];
		cin>>n;
		for ( i = 0 ; i < n ; ++i )
			cin>>array[i];
		cout<<Function(array,n)<<endl;
	return 0;
} 
/*
�����ţ� 1 
�������ƣ� ���ִ��������� 
ʱ�����ƣ� 1.0s 
�ڴ����ƣ� 256.0MB 
���������� ��������
����n�����������ҳ������г��ִ�������������������������ж���������������С��һ������ 

�����ʽ
����ĵ�һ��ֻ��һ��������n(1 �� n �� 1000)����ʾ���ֵĸ�����
����ĵڶ�����n������s1, s2, ��, sn (1 �� si �� 10000, 1 �� i �� n)�����ڵ����ÿո�ָ���

�����ʽ
�����n�������г��ִ�����������������������ж�������������С��һ����

��������
6
10 1 10 20 30 20

�������
10
*/
