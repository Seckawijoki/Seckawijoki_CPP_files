# include <stdio.h>

int main(void)

{
	double r,h,v;
	double cylinder( double r , double h );

	printf("����������Բ����İ뾶�͸ߣ�");
	scanf("%lf %lf",&r,&h);

	v = cylinder( r, h );
	printf("����ǣ�%.2lf\n",v);

	return 0;
}

double cylinder( double r , double h )	//�ڴ˵��á�
{
	double x;
	x = 3.14 * r * r * h;
	return x;
}