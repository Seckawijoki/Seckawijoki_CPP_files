# include <stdio.h>

int main(void)
{
	int n;
	int sum( int n );
	printf("现对数列1 + 2 + 3 + …… + ( n - 1 )+ n求和。\n");
	printf("请输入n的值：");
	while ( 1 )
	{
		scanf("%d",&n);
		printf("数列1 + 2 + 3 + …… + %d + %d = %d\n", n - 1 , n , sum(n));
		printf("\n可以重复求和：n = ");
	}
	return 0;
}
int sum( int n )//自调函数试用。
{
	if ( n == 1 )
		return 1;
	return sum( n - 1 ) + n;
}