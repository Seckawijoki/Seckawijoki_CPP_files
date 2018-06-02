# include <stdio.h>
void isort( int* a , int size );
void isort( int a[] , int size )
{
	int t,i,j,x;
	for ( i = 1 ; i < size ; i++ )
	{
		t = a[i];
		x = i - 1;
		while ( x >= 0 && a[x] > t )
		{
			a[x+1] = a[x];
			x--;
		}
		a[x+1] = t;
		for ( j = 0 ; j < size ; j++ )
		{
			printf("%3d,",a[j]);
			if ( j == i )
				printf(" | ");
		}
		printf("\n");
	}
}
int main()
{
	int a[] = {55,2,6,4,32,12,9,73,26,37};
	int length = sizeof( a ) / sizeof( int );
	printf(" | ");
	for ( int i = 0 ; i < length ; i++ )
		printf("%3d,",a[i]);
	printf("\n\n");
	isort( a , length );
	return 0;
}