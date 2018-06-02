/*
Description
有n(n<=100)个整数，已经按照从小到大顺序排列好，
现在另外给一个整数x，请将该数插入到序列中，并使新的序列仍然有序。

Input
输入数据包含多个测试实例，每组数据由两行组成，
第一行是n和m，第二行是已经有序的n个数的数列。
n和m同时为0标示输入数据的结束，本行不做处理。

Output
对于每个测试实例，输出插入新的元素后的数列。

Sample Input

3 3
1 2 4
 0 0

Sample Output

1 2 3 4 
*/
# include <stdio.h>
int main()
{
	int i,j, k = 0 ,n,a[100];
	while ( scanf("%d%d",&n,&a[0]) != EOF )//没读清楚题目要求。
	{
		if ( !n && !a[0] )
			break;
		for ( i = 1 ; i <= n ; i++ )
			scanf("%d",&a[i]);
		for ( i = 0 ; i <= n ; i++ )
			for ( j = i + 1 ; j < n ; j++ )
				if ( a[i] > a[j] )
				{
					a[i] = a[i] + a[j];
					a[j] = a[i] - a[j];
					a[i] = a[i] - a[j];
				}
		for ( i = 0 ; i <= n ; i++ )
			i ? printf(" %d",a[i]) :  printf("%d",a[i]);
		printf("\n");
	}
	return 0;
}
