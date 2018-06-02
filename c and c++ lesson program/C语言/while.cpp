# include <stdio.h>

int main(void)

{
	/*
	int a,b,t,x = 0;
	scanf("%d ",&t);
	if ( t >= 0 && t <= 1000 )
	{
		while ( x <= t )
		{
			scanf("%d %d",&a,&b);
			printf("%d\n",a+b);
			x++;
		}
	}
*/
	int x = 3;
	do
	{
		printf("%3d",x -= 2);
	}while(!(--x));
	return 0;
}
