/*
Description
输入m，n的值，按以下公式求组合数的值，
假设m，n都是正整数，且m>n。

Input
测试数据的组数 t
第一组m，n
第二组m，n
..........

Output
第一组组合数的值
第二组组合数的值
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