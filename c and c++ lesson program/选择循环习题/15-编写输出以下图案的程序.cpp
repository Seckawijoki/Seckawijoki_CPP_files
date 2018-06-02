/*
编写输出以下图案的程序，图案的行数由输入的值确定。
     A
	BBB
   CCCCC
  DDDDDDD
 EEEEEEEEE
*/
# include <stdio.h>
void pattern( int n );
void main()
{
	int n;
	while ( 1 )
	{
		printf("请输入图案的行数：");
		scanf("%d",&n);
		pattern( n );
	}
}

void pattern( int n )
{
	int i,j;
	char c;
	for ( i = 1 ; i <= n ; i++ )
	{
		c = i + 64;
		for ( j = n - i ; j >= 1 ; j-- )
			printf(" ");
		for ( j = 1 ; j <= 2 * i - 1  ; j ++ )
			printf("%c",c);
		printf("\n");
	}
}