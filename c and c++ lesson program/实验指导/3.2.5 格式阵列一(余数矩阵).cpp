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
			cout<<setw(2)<<j<<setw(2)<<' ';
			for ( i = 1 ; i <= n ; i++ )
				cout<<setw(3)<<( n + i + j - 2 ) %n；
			cout<<endl;
		}
	}
	return 0;
}
/*
	10-26有惊喜！
	26以上有特别。
*/