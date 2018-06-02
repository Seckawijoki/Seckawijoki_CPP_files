/*
Description
假设一个班有n(n<=50)个学生，每人考m(m<=5)门课，求每个学生的平均成绩和每门课的平均成绩，
并输出各科成绩均大于等于平均成绩的学生数量。

Input
输入数据有多个测试实例，每个测试实例的第一行包括两个整数n和m，
分别表示学生数和课程数。然后是n行数据，每行包括m个整数（即：考试分数）。

Output
对于每个测试实例，输出3行数据，
第一行包含n个数据，表示n个学生的平均成绩，结果保留两位小数；
第二行包含m个数据，表示m门课的平均成绩，结果保留两位小数；
第三行是一个整数，表示该班级中各科成绩均大于等于平均成绩的学生数量。
每个测试实例后面跟一个空行。

Sample Input

2 2 
5 10 
10 20

Sample Output

7.50 15.00 
7.50 15.00 
1 
*/
# include <stdio.h>
int main()
{
	int i,j,n,m,num;
	double a[50][50],x,y[50];//n行m列。数组小也会报wrong answer.- -!
	while ( scanf("%d %d%*c",&n,&m) != EOF )
	{
		for ( i = 0 ; i < n ; i++ )
			for ( j = 0 ; j < m ; j++ )
				scanf("%lf%*c",&a[i][j]);

		for ( i = 0 ; i < n ; i++ )
		{
			x = 0;
			for ( j = 0 ; j < m ; j++ )
				x += a[i][j];
			x = x / m;
			i ? printf(" %.2lf",x) : printf("%.2lf",x);		
		}

		for ( j = 0 ; j < m ; j++ )
		{
			y[j] = 0;
			for ( i = 0 ; i < n ; i++ )
				y[j] += a[i][j];
			y[j] = y[j] / n;
			j ? printf(" %.2lf",y[j]) : printf("\n%.2lf",y[j]);
		}

		num = 0;
		for ( i = 0 ; i < n ; i++ )
		{
			for ( j = 0 ; j < m ; j++ )
			{
				if ( a[i][j] < y[j] )//科平均成绩
				{
					num--;
					break;
				}
			}
			num++;
		}
		printf("\n%d\n\n",num);
	}
	return 0;
}