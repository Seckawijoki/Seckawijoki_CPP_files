/*
Description
输入n(n<100)个数，找出其中最小的数，将它与最前面的数交换后输出这些数。
 
Input
输入数据有多组，每组占一行，每行的开始是一个整数n，
表示这个测试实例的数值的个数，跟着就是n个整数。n=0表示输入的结束，不做处理。
 
Output
对于每组输入数据，输出交换后的数列，每组输出占一行。

Sample Input
4 2 1 3 4 
5 5 4 3 2 1
0
 
Sample Output

1 2 3 4 
1 4 3 2 5 
*/
# include <stdio.h>
int main()
{
	int n,i,x[10],y[10],j;
	while ( scanf("%d",&n) != EOF )
	{
		if ( n )
		{
			for ( i = 0 ; i < n ; i++ )
			{
				scanf("%d",&x[i]);
				y[i] = x[i];
			}
			for ( i = 1 ; i < n ; i++ )
				x[0] > x[i] ? x[0] = x[0] + x[i] , x[i] = x[0] - x[i] , x[0] = x[0] - x[i] : 1 ;
			for ( i = 0 ; i < n ; i++ )
				if ( x[0] == y[i] )
				{
					j = i;
					break;
				}
			for ( i = 0 ; i < n ; i++ )
			{
				if ( i == 0 )
					printf("%d",x[0]);
				else if ( i == j )
					printf(" %d",y[0]);
				else
					printf(" %d",y[i]);
			}
			printf("\n");
		}
	}
	return 0;
}