/*
Description
编写一函数，由实参传来一个字符串，
统计此字符串中字母、数字、空格和其它字符的个数，
在主函数中输入字符串以及输出上述结果。 
只要结果，别输出什么提示信息。

Input
一行字符串

Output
统计数据，4个数字，空格分开。

Sample Input
!@#$%^QWERT    1234567
Sample Output
5 7 4 6 
*/
# include <iostream>
# include <cstring>
# include <cstdio>
using namespace std;
int letter = 0,number = 0,space = 0,others = 0;
int panduan( char a[33] )
{
	int n = strlen(a);
	for ( int i = 0 ; i < n ; i++ )
	{
		if ( a[i] == ' ' )
			space++;
		else if ( '0' <= a[i] && a[i] <= '9' )
			number++;
		else if ( ( 'a' <= a[i] && a[i] <= 'z' )||
				  ( 'A' <= a[i] && a[i] <= 'Z' ) )
			letter++;
		else
			others++;		
	}
	return 1;
}
int main()
{
	char a[33];
	gets(a);
	panduan(a);
	cout<<letter<<' '
		<<number<<' '
		<<space <<' '
		<<others<<" \n";
	return 0;
}