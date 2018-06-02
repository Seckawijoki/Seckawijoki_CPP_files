/*
Description
输入三个字符后，按各字符的ASCII码从小到大的顺序输出这三个字符。
 
Input
输入数据有多组，每组占一行，有三个字符组成，之间无空格。
 
Output
对于每组输入数据，输出一行，字符中间用一个空格分开。
 
Sample Input

qwe asd zxc

Sample Output

e q w 
a d s 
c x z 
*/
# include <iostream>
# include <cstdio>
using namespace std;

int main()
{
	char a,b,c;//需要EOF这种格式才能通过，不可以1的死循环。
	while ( scanf("%c%c%c%*c",&a,&b,&c) != EOF )//%*c：过滤空格。
	{
		a > b ? a = a + b , b = a - b , a = a - b : 1 ;
		a > c ? a = a + c , c = a - c , a = a - c : 1 ;

		b > c ? b = b + c , c = b - c , b = b - c : 1 ;

		printf("%c %c %c\n",a,b,c);
	}
	return 0;
}