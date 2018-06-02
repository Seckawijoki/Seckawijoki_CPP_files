/*
Description
����m��n��ֵ�������¹�ʽ���������ֵ��
����m��n��������������m>n��

Input
�������ݵ����� t
��һ��m��n
�ڶ���m��n
..........

Output
��һ���������ֵ
�ڶ����������ֵ
..........

Sample Input
3
8 5
6 3
10 8

Sample Output
56
20
45
*/
# include <iostream>
using namespace std;
double mul( int x )
{
	if ( x <= 1 )
		return 1;
	return mul(x-1)*x;
}
long zuheshu( int m , int n )
{
	long double c;
	c = mul(m) / mul(n) / mul(m-n);
	return long(c);
}
int main()
{
	int t,m,n;
	cin>>t;
	while ( t-- )
	{
		cin>>m>>n;
		cout<<zuheshu(m,n)<<endl;
	}
	return 0;
}