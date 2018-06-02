/*
Description
从键盘输入任意正整数，判断该数是否是回文数。
所谓回文数就是从左到右读这个数与从右到左读这个数是一样的。例如12321、1221都是回文数。

Input
测试案例的个数n
第一个测试值
第二个测试值
.......
第n个测试值

Output
各个测试值是否是回文数，是，就输出Yes，不是，就输出No

Sample Input
3
4554
123
121

Sample Output
Yes
No
Yes
*/
#include<iostream>
using namespace std;
int main()
{
	int i,n,a,m,sum; 
	cin>>n;
	for ( i = 1 ; i <= n ; i++ )
	{
		sum = 0;
		cin>>a;
//		cout<<"a = "<<a<<endl;continue;
		m = a;
		while ( m )
		{
			sum = sum*10 + m%10;
			m /= 10;
		}
		if( sum == a )
			cout<<"Yes\n";
		else
			cout<<"No\n";
	}
	return 0;
}


