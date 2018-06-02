/*
题目描述
输入一个N*M的矩阵，要求将这个矩阵向左旋转90度后输出
比如现在有矩阵 ： 
1 2 3
4 5 6 
向左旋转90度后的矩阵变为： 
3 6
2 5
1 4

输入
第一行输入T表示有T个测试实例
第二行输入矩阵维度N和M，表示N行和M列
第三行起输入矩阵数据，矩阵数据用自然数表示
下面依次类推

输出
输出左转90度的矩阵
注意每行最后一个数据不带空格，直接换行

样例输入
3
2 3
1 2 3
4 5 6
3 3
1 2 3
4 5 6
7 8 9

样例输出
3 6
2 5
1 4
3 6 9
2 5 8
1 4 7
*/
# include <stdio.h>
int rotate( int n1[55][55] , int m , int n )
{
	int n2[55][55],i,j;
	for ( i = 0 ; i < m ; i ++ )
		for ( j = 0 ; j < n ; j ++ )
			n2[n-1-j][i] = n1[i][j];
	for ( i = 0 ; i < n  ; i ++ )
	{
		for ( j = 0 ; j < m - 1 ; j ++ )
			printf("%d ",n2[i][j]);
		printf("%d\n",n2[i][j]);
	}
	return 1;
}
int main()
{
	int t,m,n,n1[55][55],i,j;
	scanf("%d",&t);
	while ( t-- )
	{
		scanf("%d %d",&m,&n);
		for ( i = 0 ; i < m ; i ++ )
			for ( j = 0 ; j < n ; j ++ )
				scanf("%d",&n1[i][j]);
		rotate(n1,m,n);
	}
	return 0;
}