/*
Description
对于给定的一个字符串，统计其中数字字符出现的次数。

Input
输入数据有多行，第一行是一个整数n，表示测试实例的个数，
后面跟着n行，每行包括一个由字母和数字组成的字符串。

Output
对于每个测试实例，输出该串中数值的个数，每个输出占一行。

Sample Input

2 
asdfasdf123123asdfasdf 
asdf111111111asdfasdfasdf

Sample Output

6 
9 
*/

# include <stdio.h>
int main()
{
	int i,n,num[20];//- -!!数组多才能通过。
	char c;
	scanf("%d",&n);
	for ( i = 0 ; i <= n ; i++ )
	{
		num[i] = 0;
		while ( scanf("%c",&c) != EOF )
		{
			if ( c >= '0' && c <= '9' )
				num[i]++;
			if ( c == '\n' )//判断回车问题！！
				break;
		}
	}
	for ( i = 1 ; i <= n ; i++ )
		printf("%d\n",num[i]);
	return 0;
}