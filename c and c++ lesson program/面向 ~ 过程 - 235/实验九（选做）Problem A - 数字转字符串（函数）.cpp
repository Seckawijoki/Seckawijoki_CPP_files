/*
Description
写一函数，输入一个四位数字，要求输出这四个数字字符，
但每两个数字间空格。如输入1990，应输出"1 9 9 0"。

Input
一个四位数

Output
增加空格输出

Sample Input
1990
Sample Output
1 9 9 0 

*/
# include <iostream>
# include <ctype.h>
using namespace std;
int szzzfc( int x )
{
	int a,b,c,d;
	a = x /1000;
	x -= a * 1000;
	b = x /100;
	x -= b * 100;
	c = x /10;
	d = x %10;
	cout<<toascii(a)<<' '
		<<toascii(b)<<' '
		<<toascii(c)<<' '
		<<toascii(d)<<" \n";
	return 0;
}
int main()
{
	int x;
	cin>>x;
	szzzfc(x);
	return 0;
}