/*
Description
��n����Χ��һ��Ȧ���ӵ�һ���˿�ʼ˳�򱨺�1��2��3�����Ǳ���
3�˳�Ȧ���е���ԭ������š�Ҫ���ӡ���˳��˵���š�
�Լ��ҳ��������Ȧ���е���ԭ������š�

Input
����n

Output
�˳��˵���ţ����ҳ��������Ȧ�������ԭ�������

Sample Input
13

Sample Output
3 6 9 12 2 7 11 4 10 5 1 8 
13
*/
# include <iostream>
using namespace std;
const int z = 3;

int main()
{
	int a[30],i,k = 0,tg = 0,n;
	cin>>n;
	for ( i = 0 ; i < n ; i++ )
		a[i] = i + 1;
	i = 0;
	while ( 1 )
	{
		if ( a[i] )
		{
			k++;
			if ( k == z )
			{
				tg++;
				if ( tg < n )
					cout<<a[i]<<' ';
				a[i] = 0;
				k = 0;
			}
		}
		else
		{	
			i++;
			continue;
		}
		i++;
		if ( tg > n - 1 )
			break;
		if ( i >= n )
			i = 0;
	}
	cout<<endl<<i<<endl;
	return 0;
}