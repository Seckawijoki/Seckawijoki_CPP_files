# include <stdio.h>
long zhs( int x )
{
	if ( x <= 1 )
		return 1;
	return x * zhs(x-1);
}
int main()
{
	int t,m,n;
	scanf("%d",&t);
	while ( t-- )
	{
		scanf("%d%d",&m,&n);
		printf("%d\n",zhs(m)/zhs(n)/zhs(m-n));
	}
}