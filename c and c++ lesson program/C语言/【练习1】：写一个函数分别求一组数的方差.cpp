/*
����ϰ1����дһ�������ֱ���һ�����ķ��
��ʾ��

���ʽ��n��ʾ�������ݸ�����x1��x2��x3����xn��ʾ�������ݾ�����ֵ��

ƽ������ 

���ʽ�� 
Ҫ��
��1����д����variance��ʵ�ּ���һ�����ķ�� 

��2���������У��������鲢ʹ�ó�ʼ���������������ֵ��
��������Ϊ{16��5��8��12��1��17��3��6��10��2}��

��3���������е���variance�����������ķ������������ķ��
��������28.80
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
