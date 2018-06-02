# include <stdio.h>
void zz( int a[3][3] )
{
	int i,j;
	for ( i = 0 ; i < 3 ; i++ )
	{
		for ( j = 0 ; j < 3 ; j++ )
			printf("%d ",a[j][i]);
		printf("\n");
	}
}
void main()
{
	int i,j,a[3][3];
	for ( i = 0 ; i < 3 ; i++ )
		for ( j = 0 ; j < 3 ; j++ )
			scanf("%d",&a[i][j]);
	zz(a);
}