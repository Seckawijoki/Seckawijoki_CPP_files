# include <stdio.h>

int main()

{
	int n,
	int mul( int n );
	while ( 1 )
	{
		printf("������׳���n!��n = ");
		scanf("%d",&n);
		printf("%d! = %d\n",n,mul( n ));
	}
	return 1;
}

int mul( int n )//�Ե�����
{
	if ( n == 1)
		return 1;
	return mul( n - 1 ) * n;
}