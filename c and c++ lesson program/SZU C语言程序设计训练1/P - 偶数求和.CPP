/*
Description
有一个长度为n(n<=100)的数列，该数列定义为从2开始的递增有序偶数，
现在要求你按照顺序每m个数求出一个平均值，如果最后不足m个，则以实际数量求平均值。编程输出该平均值序列。

Input
输入数据有多组，每组占一行，包含两个正整数n和m，n和m的含义如上所述。

Output
对于每组输入数据，输出一个平均值序列，每组输出占一行。

Sample Input
3 2 
4 2

Sample Output
3 6 
3 7 
*/
# include <stdio.h>
int main()
{
	int i,j,n,m,sum = 0;;
	while ( scanf("%d%d",&n,&m) != EOF )
	{
		for ( i = 1 ; i <= ( n / m ) ; i++ )
		{
			for ( j = 1 ,sum = 0 ; j <= m ; j++ )
			{
				sum += 2 * ( j + m * ( i - 1 ) );
			}
			i == 1 ? printf("%d", sum / m ) : printf(" %d", sum / m );
		}
		if ( n %m != 0 )
		{
			for ( j = n - n %m + 1 , sum = 0 ; j <= n ; j++ )
			{
				sum += 2 * j ;
			}
			printf(" %d",sum / ( n %m ) );
		}
		printf("\n");
	}
	return 0;
}