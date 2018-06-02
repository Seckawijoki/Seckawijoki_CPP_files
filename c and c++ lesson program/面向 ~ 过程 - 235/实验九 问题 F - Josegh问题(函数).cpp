# include <stdio.h>
int joseph( int m , int n )
//±³°É£¬Ç×¡£¡£¡£¡£¡£¡£
{
	int i,j,k,a[30] = {0};
	for ( i = 0 ; i < m ; i++ )
		a[i] = i + 1;
	i = -1;
	k = 1;
	while ( 1 )
	{
		for ( j = 0 ; j < n ; )
		{
			i = ( i + 1 )%m;
			if ( a[i] != 0 )
				j++;
		}
		if ( k == m )
			break;
		printf("%d ",a[i]);
		a[i] = 0;
		k++;
	}
	printf("%d\n",a[i]);
	return 1;
}
int main()
{
	int t,x,y;
	scanf("%d",&t);
	while ( t-- )
	{
		scanf("%d%d",&x,&y);
		joseph(x,y);
	}
	return 0;
}