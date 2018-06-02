/*
Description
����m���ˣ�m������30��Χ��һȦ����˳ʱ�뷽���1��m��ţ�
�ӵ�1���˿�ʼ����1��n�ı�������������n���ˣ�
���˳�Ȧ���ٴ�������һ�������¿�ʼ��1��n�ı�����
��˽�����ȥֱ�����е��˶���ȦΪֹ��
��Ҫ�������m���˵ĳ�Ȧ����˳���
��д����Josegh()ʵ�ִ˹��ܡ�
��������������m��n��ֵ������Josegh()������

Input
�������ݵ����� t
��һ�� m  n
�ڶ��� m  n
.......

Output
��һ�����˳��
�ڶ������˳��
.........


Sample Input
2
13 3
20 5

Sample Output
3 6 9 12 2 7 11 4 10 5 1 8 13
5 10 15 20 6 12 18 4 13 1 9 19 11 3 17 16 2 8 14 7
*/
# include <iostream>
using namespace std;
int joseph( int m , int n )
{
	int i,j,k,a[55] = {0};
	for ( i = 0 ; i < m ; i++ )
		a[i] = i + 1;
	i = -1;
	k = 1;
	while ( 1 )
	{
		for ( j = 0 ; j < n ; )
		{
			i = ( i + 1 )%m;
			if ( a[i] != 0 )
				j++;
		}
		if ( k == m )
			break;
		cout<<a[i]<<' ';
		a[i] = 0;
		k++;
	}
	cout<<a[i]<<endl;
	return 1;
}
int main()
{
	int t,m,n;
	cin>>t;
	while ( t-- )
	{
		cin>>m>>n;
		joseph(m,n);
	}
	return 0;
}