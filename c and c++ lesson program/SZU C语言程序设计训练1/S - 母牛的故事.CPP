/*
Description
有一头母牛，它每年年初生一头小母牛。
每头小母牛从第四个年头开始，每年年初也生一头小母牛。
请编程实现在第n年的时候，共有多少头母牛？

Input
输入数据由多个测试实例组成，每个测试实例占一行，
包括一个整数n(0<n<55)，n的含义如题目中描述。
n=0表示输入数据的结束，不做处理。

Output
对于每个测试实例，输出在第n年的时候母牛的数量。
每个输出占一行。

Sample Input
2 4 5 0

Sample Output
2 4 6 
*/
# include <stdio.h>
void cows( int n )
{
	int one,two,three,four;
	one = 0;
	two = 0;
	three = 1;
	four = 0;
    for ( int i = 1 ; i <= n ; i++ )
	{
		four = three + four;
		three = two;
		two = one;
		one = four;
     }
	printf("%d\n",two + three + four);//输出问题：n是该年。
}

int main()
{
	int n;
	while( scanf("%d",&n) != EOF )
		if ( n )
			cows( n );
		else
			break ;
	return 0;
}