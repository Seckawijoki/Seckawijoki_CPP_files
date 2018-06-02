# include <iostream.h>
# include <iomanip.h>
# include <cstdio>
# include <math.h>
int main()
{
	int x;
	printf("请输入一些三位数，以判断它们是否为对称三位数素数：");
	int prime( int x );
	while ( 1 )
	{
		scanf("%d",&x);
		if ( x / 100 != 0 && x / 100 == x %10 )
			prime(x);
		else
			printf("NO（不标准的对称三位数。）\n");
	}
	return 0;
}
//	犯了很多2。
int prime( int x )
{
	int i,y;
	if ( x %2 == 0 )
		printf("NO（合数，不是素数。）\n");
	else
	{
		y = sqrt(x);//。。。。。。不解释
		for ( i = 3 ; i <= y ; i = i + 2 )//不必试偶数。
		{
			if ( x %i == 0 )
			{
				printf("No（不是素数。）\n");
				break;
			}
		}
		if ( x %i != 0 )
			printf("Yes（是对称三位数素数。）\n");
	}
	return 1;
}
