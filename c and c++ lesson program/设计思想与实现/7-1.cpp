# include <stdio.h>
int main()
{
	int i,a[10] , b[] = {34,91,83,56,29,93,56,12,88,72};
	for ( i = 0 ; i < 10 ; i++ )
		a[i] = b[i];
	for ( i = 1 ; i < 10 ; i++ )
		if ( b[0] > b[i] )			
			b[0] = b[i];
	for ( i = 0 ; i < 10 ; i++ )
	{
		if ( b[0] == a[i] )
		{
			printf("最小值 : %d\n",b[i]);
			printf("下标   : %d\n",i);
			break;
		}
	}
	return 0;
}