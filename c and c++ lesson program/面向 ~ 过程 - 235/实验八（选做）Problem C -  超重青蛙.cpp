/*
Description
在青蛙王国（不超过10只），每个青蛙有着不同的体重。
给出一组青蛙的体重，计算里面超出平均体重的青蛙数量。

Input
第一行输入参数T，表示有T个测试实例
第二行输入参数n，表示这一组青蛙的数量，
第三行输入n个青蛙的体重
以此类推

Output
输出每一组青蛙中，超出平均体重的青蛙数量。

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