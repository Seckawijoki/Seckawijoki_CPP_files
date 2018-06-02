# include <stdio.h>
int prime( int x )
//这次清晰些：先对0,1,2进行判断，再对奇数或偶数。
{
	if ( x >= 0 && x <= 2 )
	{
		printf("not prime\n");
		return 1;
	}
	else if ( x %2 == 0 )
	{
			printf("not prime\n");
			return 1;
	}
	else for ( int i = 3 ; i <= x / 2 ; i += 2 )
	{
		if ( x %i == 0 )
		{
			printf("not prime\n");
			return 1;
		}
	}
	printf("prime\n");
	return 1;	
}
int main()
{
	int n,x;
	scanf("%d",&n);
	while ( n-- )
	{
		scanf("%d",&x);
		prime(x);
	}
	return 0;
}
