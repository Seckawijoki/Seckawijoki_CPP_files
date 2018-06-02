/*
Description
编程计算a+aa+aaa+…+aa..a(n个a)的值，
a的取值范围为0—9，n的取值范围为0—5。
n和a的值都由键盘输入，均为整数。

Input
键盘输入a和n

Output
求和

Sample Input
2
4
Sample Output
2468

*/
# include <iostream>
using namespace std;
int main()
{
	int a,n,i,s = 0,t = 0;
	cin>>a>>n;
	for ( i = 1 ; i <= n ; i++ )
	{
		t += a;
		s += t;
		t *= 10;
	}
	cout<<s<<endl;
	return 0;
}