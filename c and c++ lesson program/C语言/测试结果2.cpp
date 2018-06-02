/*
# include <stdio.h>
double fun( double y, int x )
{
	int i;
	double z = 1.0;
	for ( i = 1 ; i <= x ; i++ )
		z = z * y;
	return z;
}
void main()
{
	double a,b;
	int c;
	printf("");
	scanf("%lf%d",&a,&c);
	if ( c < 0 )
	{
		printf("");
		return ;
	}
	b = fun( a , c );
	printf("b = %lf\n",b);
}
*/
#include<stdio.h>
double fun(double y,int x)
{
		int i;
		double z=1.0;
		for(i=0;i<=x;i++)
			z=z*y;
		return z;
}
void main()
{
	double a,b;
	int c;
	printf("Please input a,c:");
	scanf("%lf%d",&a,&c);
	if(c<0)
	{
		printf("c<0!Error!\n");
		return;
	}
	b=fun(a,c);
	printf("b=%lf",b);







}
	