/*
Description
������������������10ֻ����ÿ���������Ų�ͬ�����ء�
����һ�����ܵ����أ��������泬��ƽ�����ص�����������

Input
��һ���������T����ʾ��T������ʵ��
�ڶ����������n����ʾ��һ�����ܵ�������
����������n�����ܵ�����
�Դ�����

Output
���ÿһ�������У�����ƽ�����ص�����������

Sample Input
2
3
1 2 3
4
10 20 30 40

Sample Output
1
2

*/
# include <iostream>
using namespace std;
int main()
{
	int t,n,a[10],i,num;
	double avrg;
	cin>>t;
	while ( t-- )
	{
		avrg = 0;
		num = 0;
		cin>>n;
		for ( i = 0 ; i < n ; i++ )
		{
			cin>>a[i];
			avrg += a[i];
		}
		avrg /= n;
		for ( i = 0 ; i < n ; i++ )
			if ( double(a[i]) > avrg )
				num++;
		cout<<num<<endl;
	}
	return 0;
}