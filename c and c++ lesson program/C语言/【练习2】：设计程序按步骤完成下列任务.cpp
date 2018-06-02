/*
【练习2】：设计程序按步骤完成下列任务：
（1）编写函数sort，用选择法对整数数组排序的功能， 
（2）主函数中，定义数组并使用初始化方法给出数组初值。测试数据为{16，5，8，12，1，17，3，6，10，2}。
（3）主函数中调用sort函数实现对测试数据排序的功能。要求分别输出排序前后数组元素的值。
*/
# include <stdio.h>
int sort( int a[10] );

int sort( int a[10] )
{
	int i,j,k;
	for ( k = 0 ; k < 10 ; k++ )
	{
		printf("%d，",a[k]);
	}
	printf("\n");

	for ( i = 0 ; i < 10 ; i++ )
	{
		for ( j = i + 1 ; j < 10 ; j++ )//j循环搞重复。
		{
			if ( a[i] > a[j] )
			{
				a[i] = a[i] + a[j];//a = a + b
				a[j] = a[i] - a[j];//b = a - b
				a[i] = a[i] - a[j];//a = a - b
			}
		}
		for ( k = 0 ; k < 10 ; k++ )
		{
			printf("%d，",a[k]);
		}
		printf("\n");
	}
	return 1;
}

int main()
{
	int a[10]={16,5,8,12,1,17,3,6,10,2};
	sort(a);	
	return 0;
}