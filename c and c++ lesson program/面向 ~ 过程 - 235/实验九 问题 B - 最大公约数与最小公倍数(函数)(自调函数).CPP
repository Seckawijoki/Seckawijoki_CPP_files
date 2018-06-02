# include <stdio.h>
int zdgys( int x , int y )//自调函数。看看......
{
	if ( x %y == 0 )
		return y;
	return zdgys( y , x %y);
}
int main()
{
	int a,b,c,n;
	scanf("%d",&n);
	while ( n-- )
	{
		scanf("%d%d",&a,&b);
		c = zdgys(a,b);
		printf("%d %d\n",c,a*b/c);
	}
	return 0;
}