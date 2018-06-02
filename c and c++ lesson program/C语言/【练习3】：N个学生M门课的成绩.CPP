/*
【练习3】：N个学生M门课的成绩，存放在二维数组中，分别用函数求：
a) 输入每个学生M门课的成绩。
b) 计算每个学生的平均分。
c) 计算每门课的平均分。
要求：（1）编写一个函数student_ave实现计算并输出每个学生的平均分；
（2）编写一个函数course_ave实现计算并输出每门课的平均分；                                                                         
（3）主函数定义二维数组，并输入每个学生M门课的成绩,
分别调用函数student_ave、course_ave输出每个学生的平均分和每门课的平均分。
*/
# include <stdio.h>
double student_ave( int a[10][10] , int i )
{
	double s1 = 0;
	for ( int k = 0 ; k < 10 ; k++ )
		s1 += a[i][k];
	printf("学生%d的平均分是：%.2lf\n",i+1, s1/9 );
	return 1;
}
double course_ave( int a[10][10] , int j )
{
	double s2 = 0;
	for ( int k = 0 ; k < 10 ; k++ )
		s2 += a[k][j];
	printf("科目%d的平均分是：%.2lf\n",j+1, s2/9 );
	return 1;
}

int main()
{
	double student_ave( int a[10][10] , int i );
	double course_ave( int a[10][10] , int j );
	int i,j,a[10][10];
	for ( i = 0 ; i < 10 ; i++ )
		for ( j = 0 ; j < 10 ; j++ )
			scanf("%d",&a[i][j]);//i行j列
	for ( i = 0 ; i < 10 ; i++ )
		student_ave(a,i);
	for ( j = 0 ; j < 10 ; j++ )
		course_ave(a,j);

	return 0;
}