# include <stdio.h>
int fbnq( int n )
{
	int i,a[50] = {1,1};
	for ( i = 2 ; i < n ; i++ )
		a[i] = a[i-1] + a[i-2];
	printf("%d",a[i-1]);
	return 1;
}
int main()
{
	int n;
	scanf("%d",&n);
	fbnq(n);
	return 0;
}