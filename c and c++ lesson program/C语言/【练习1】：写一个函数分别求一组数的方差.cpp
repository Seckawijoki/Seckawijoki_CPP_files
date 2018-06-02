/*
【练习1】：写一个函数分别求一组数的方差。
提示：

方差公式（n表示这组数据个数，x1、x2、x3……xn表示这组数据具体数值）

平均数： 

方差公式： 
要求：
（1）编写函数variance，实现计算一组数的方差， 

（2）主函数中，定义数组并使用初始化方法给出数组初值。
测试数据为{16，5，8，12，1，17，3，6，10，2}。

（3）主函数中调用variance计算这组数的方差，输出这组数的方差。
输出结果：28.80
*/
# include <stdio.h>
double variance( double a[10] , int n )
{
	int j;
	double var = 0;
	double s = 0;
	for ( j = 0 ; j < 10 ; j++ )
		s += a[j];
	s = s / 10;

	for ( j = 0 ; j < 10 ; j++ )
		var += ( s - a[j] ) * ( s - a[j] );
	printf("%.2lf\n",var / 10 );

	return var;
}

int main()
{

	double variance( double a[10] , int n );
	double a[10]={16,5,8,12,1,17,3,6,10,2};
	variance( a , 10 );
	return 0;
}
