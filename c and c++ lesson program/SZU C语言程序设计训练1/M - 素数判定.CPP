/*
Description
对于表达式n^2+n+41，当n在（x,y）范围内取整数值时（包括x,y）(-39<=x<y<=50)，判定该表达式的值是否都为素数。

Input
输入数据有多组，每组占一行，由两个整数x，y组成，当x=0,y=0时，表示输入结束，该行不做处理。

Output
对于每个给定范围内的取值，如果表达式的值都为素数，则输出"OK",否则请输出“Sorry”,每组输出占一行。

Sample Input
0 1 0 0
 
Sample Output
OK 

*/
# include <stdio.h>
int main()
{
	int x,y,z,leap = 0;
	int prime( int z );
	while ( scanf("%d%d",&x,&y) != EOF )
	{
		if ( x != 0 || y != 0 )
		{
			for ( ; x <= y ; x++ )
			{
				z = x * x + x + 41;
				leap = prime( z );
				if ( leap == 11 )
				{
					printf("Sorry\n");
					break;
				}
			}
			if ( leap == 22 )
			{
				printf("OK\n");
			}
		}
	}
	return 0;
}

int prime( int z )
{
	for ( int i = 3 ; i < z ; i += 2 )//一个等号的问题-.-
	{
		if ( z %i == 0 )
		{
			return 11;//合数了。
		}
	}
	return 22;//则素数。
}