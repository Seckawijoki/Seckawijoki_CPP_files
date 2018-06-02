# include <stdio.h>

int main(void)

{
	double r,h,v;
	double cylinder( double r , double h );

	printf("请依次输入圆柱体的半径和高：");
	scanf("%lf %lf",&r,&h);

	v = cylinder( r, h );
	printf("体积是：%.2lf\n",v);

	return 0;
}

double cylinder( double r , double h )	//在此调用。
{
	double x;
	x = 3.14 * r * r * h;
	return x;
}