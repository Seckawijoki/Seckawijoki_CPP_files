/*
Description
����������������������ǵ����Լ������ν���Լ����������ͬʱ���������������������е�����һ����

Input
�������ݵ�����n
��һ���������
�ڶ����������
.....
��n���������

Output
��һ��������ݵ����Լ��
�ڶ���������ݵ����Լ��
......
��n��������ݵ����Լ��

Sample Input
4
2 8
8 4
72 60
9 7

Sample Output
2
4
12
1
*/

# include <iostream>
using namespace std;
int main()
{
	int i,x,m,n,r;
	cin>>x;
	for ( i = 1 ; i <= x ; i++ )
	{
		cin>>m>>n;
		if ( m < n )
		{
			m = m + n;
			n = m - n;
			m = m - n;
		}
		while ( n )
		{
			r = m %n;
			m = n;
			n = r;
		}
		cout<<m<<endl;
	}
	return 0;
}
