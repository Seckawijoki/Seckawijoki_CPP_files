/*
5. 编写程序，求a+aa+aaa+…+aa…a,其中a是一个数字。例如： 
3+33+333+3333+33333（此时n为5）。要求a和n从键盘输入，
输出格式为3+33+333+3333+33333=37035。
*/
# include <stdio.h>
# include <math.h>
void sum( int a , int n );
void main()
{
	int a,n;
	printf("现求a+aa+aaa+...+aa...a共n项之和。\n");
	printf("请分别输入a和n的值：");
	while ( 1 )
	{
		scanf("%d %d",&a,&n);
		if ( a > 0 && a < 10 )
			sum( a , n );
		else
			printf("输入有误，请重新输入：");	
	}
}
void sum( int a , int n )
{
	int i,b = 0;
	long s = 0;
	for ( i = 0 ; i < n ; i++ )
	{
		b += a * pow( 10 , i );
		s += b;
		i ? printf("+%d",b) : printf("%d",b);
	}
	printf("=%ld\n",s);
}