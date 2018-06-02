# include <stdio.h>

int main()

{
	int n,
	int mul( int n );
	while ( 1 )
	{
		printf("请输入阶乘数n!的n = ");
		scanf("%d",&n);
		printf("%d! = %d\n",n,mul( n ));
	}
	return 1;
}

int mul( int n )//自调函数
{
	if ( n == 1)
		return 1;
	return mul( n - 1 ) * n;
}