/*
题目描述
设有m个人（m不超过30）围坐一圈并按顺时针方向从1到m编号，
从第1个人开始进行1到n的报数，报数到第n个人，此人出圈，
再从他的下一个人重新开始从1到n的报数，如此进行下去直到所有的人都出圈为止。
现要求给出这m个人的出圈次序顺序表。编写函数Josegh()实现此功能。
在主函数中输入m与n的值，调用Josegf()函数。
输入
测试数据的组数 t
第一组 m  n
第二组 m  n
.......
输出
第一组出列顺序
第二组出列顺序
.........

样例输入
2
13 3
20 5
样例输出
3 6 9 12 2 7 11 4 10 5 1 8 13
5 10 15 20 6 12 18 4 13 1 9 19 11 3 17 16 2 8 14 7
*/
# include <stdio.h>
int joseph( int m , int n )
{
	int i,j,k,a[33];
	for ( i = 0 ; i < m ; i ++ )
		a[i] = i + 1;
	i = -1;
	k = 1;
	while ( 1 )
	{
		for ( j = 0 ; j < n ; )
		{
			i = ( i + 1 )%m;
			if ( a[i] != 0 )
				j++;
		}
		if ( k == m )
			break;
		printf("%d ",a[i]);
		a[i] = 0;
		k++;
	}
	printf("%d\n",a[i]);
	return 1;
}
int main()
{
	int m,n,t;
	scanf("%d",&t);
	while ( t-- )
	{
		scanf("%d%d",&m,&n);
		joseph(m,n);
	}
	return 0;
}