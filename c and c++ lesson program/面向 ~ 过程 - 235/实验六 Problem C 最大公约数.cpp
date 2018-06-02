/*
Description
输入两个正整数，输出它们的最大公约数。所谓最大公约数，就是能同时被这两个整数整除的数中的最大的一个。

Input
测试数据的组数n
第一组测试数据
第二组测试数据
.....
第n组测试数据

Output
第一组测试数据的最大公约数
第二组测试数据的最大公约数
......
第n组测试数据的最大公约数

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
