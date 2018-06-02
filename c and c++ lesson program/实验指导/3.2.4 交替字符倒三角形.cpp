# include <iostream.h>
# include <cstdio>
int main()
{
	int i,j,n;
	while ( 1 )
	{
		scanf("%d",&n);
		cout<<endl;
		for ( j = 1 ; j <= n ; j++ )
		{		
			for ( i = 1 ; i <= j ; i++ )
				cout<<' ';
			for ( i = 2 * ( n - j ); i >= 0 ; i-- )
				if ( i %2 == 0)
					cout<<'S';
				else 
					cout<<'T';

			cout<<endl;
		}
	}
	return 0;
}
/*
	39ÒÔÉÏÓÐ¾ªÏ²£¡
*/