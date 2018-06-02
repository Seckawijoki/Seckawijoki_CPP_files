# include <stdio.h>
void fbnq( int n )
{
	int i,a[30] = {0,1};
	for ( i = 2 ; i <= n ; i++ )
		a[i] = a[i-1] + a[i-2];
	printf("%d",a[i-1]);
}
void main()
{
	int n;
	scanf("%d",&n);
	fbnq(n);
}