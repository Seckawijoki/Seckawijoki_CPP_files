/*
Description
如下图，可以用火柴棍来表示数字：

现在，你手里有一定数量的火柴棍，请给出你能用这些火柴棍所表示的数字的范围
（要求使用全部的火柴棍，并且数字不能用0开头）。

Input
输入的第一个整数T表示有多少组测试数据（1≤T≤100）。
每组测试数据为一行，只有一个整数，即代表了你手中的火柴棍的数量n（2≤n≤100）。

Output
为每组测试数据输出一行，由2个整数组成，
分别对应所表示的最小和最大的整数，中间使用一个空格隔开。

Sample Input
3
3
6
7
Sample Output
7 7
6 111
8 711
*/
# include <stdio.h>
int match( int x );
int match( int x )
{
	int a,b,j;
	//min:
	if ( ((x-1) / 7) %2 == 0 )//偶数，7的奇数倍之内
	{
		switch ( x %7 )
		{
			case 1:printf(""); 
				break;
			case 2:printf("1"); goto rear; break;
			case 3:printf("7"); goto rear; break;
			case 4:printf("4"); goto rear; break;
			case 5:printf("2"); goto rear; break;
			case 6: printf("6");
					for ( j = 1 ; j <= (x / 7) - 1 ; j++ )
					{
						printf("8");	
					}
					x > 7 ? printf("0") : 1 ;
					break;
		}
		rear:
		{
			for ( j = 1 ; j <= x / 2 ; j++ )
			{
				printf("8");	
			}
		}
		printf("<空格>"); 
	}
	else
	{
	
	}

	//max:
	b = x / 2;
	if ( b )
	{
		if ( x %2 && x >= 3 )
		{
			printf("7");
			b--;
		}
		for ( j = 1 ; j <= b ; j++ )
			printf("1");
		printf("\n");
	}
	return 1;
}

int main()
{
	int i,x,n;
	scanf("%d",&n);
	for ( i = 1 ; i <= n ; i++ )
	{
		scanf("%d",&x);
		match(x);
	}
	return 0;
}