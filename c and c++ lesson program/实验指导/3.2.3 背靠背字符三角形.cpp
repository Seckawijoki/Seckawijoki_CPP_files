# include <iostream.h>
# include <cstdio>
int main()
{
	char c;
	int i,j,n;
	while ( 1 )
	{
		scanf("%c %d",&c,&n);
		for ( j = 1 ; j <= n ; j++ )
		{
			for ( i = n - j ; i >= 1 ; i-- )
				cout<<' ';
			for ( i = 1 ; i <= j ; i++ )
				cout<<c;

			cout<<' ';

			for ( i = 1 ; i <= j ; i++ )
				cout<<c;

			cout<<endl;
		}
	}
	return 0;
}
/*
	39ÒÔÉÏÓÐ¾ªÏ²£¡
*/