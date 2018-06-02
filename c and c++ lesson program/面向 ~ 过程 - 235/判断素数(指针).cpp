/*
题目描述
写一个判断素数的函数，在主函数输入一个整数，
输出是否素数的信息。

输入
判断次数和每次输入的任意整数 　

输出
每次的输入是否为素数

样例输入
4
17
5
6
19

样例输出
prime
prime
not prime
prime
*/
# include <stdio.h>
int prime( int *px )
{
	if ( *px == 0 || *px == 1 || *px == 2 )
	{
		printf("prime\n");
		return 1;
	}
	else if ( *px %2 == 0 )
	{
		printf("not prime\n");
		return 1;
	}
	else 
	{
		*px += ( *px + 1 )%2;
		int i;
		for ( i = 3 ; i < *px / 2 ; i += 2 )
		{
			if ( *px %i == 0 )
			{
				printf("not prime\n");
				return 1;
			}
		}
		printf("prime\n");
		return 1;
	}
}
int main()
{
	int t,x,*px;
	scanf("%d",&t);
	while ( t-- )
	{
		scanf("%d",&x);
		px = &x;
		prime(px);
	}
	return 0;
}