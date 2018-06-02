# include <stdio.h>
int main()
{
	int i,j,t,n,a[11][11],s;
	scanf("%d",&t);
	while ( t-- )
	{
		scanf("%d",&n);
		for ( i = 0 ; i < n ; i++ )
			for ( j = 0 ; j < n ; j++ )
				scanf("%d",&a[i][j]);
		for ( i = 0 , s = 0 ; i < n ; i++ )
			s += a[i][i];
		printf("%d ",s);
		for ( i = 0 , s = 0 ; i < n ; i++ )
			s += a[i][n-1-i];
		printf("%d\n",s);
	}
	return 0;
}