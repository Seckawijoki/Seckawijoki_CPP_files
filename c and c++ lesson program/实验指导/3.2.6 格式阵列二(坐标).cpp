# include <iostream.h>
# include <cstdio>
# include <iomanip.h>
int main()
{
	int i,j,n;
	while ( 1 )
	{
		scanf("%d",&n);
		for ( j = 1 ; j <= n ; j++ )
		{
			for ( i = 1 ; i <= n ; i++ )
				cout<<setw(3)<<'('<<j<<','<<i<<')';
			cout<<endl;
		}
		cout<<endl;
	}
	return 0;
}
/*
	9ÒÔÉÏÓÐ¾ªÏ²£¡
*/