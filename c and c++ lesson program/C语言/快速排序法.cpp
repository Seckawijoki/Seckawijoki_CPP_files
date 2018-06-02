# include <iostream.h>
void swap( int&a , int&b )
{
	a = a + b;
	b = a - b;
	a = a - b;
}
void qsort( int[] , int , int );
void qsort( int a[] , int left , int right )
{
	int pivot = a[right] , l = left , r = right;
	while ( l < r )
	{
		swap( a[l] , a[r] );
		while ( l < r && a[r] >  pivot )
			--r;
		while ( l < r && a[l] <= pivot )
			++l;
		swap( a[left] , a[r] );
		if ( left < r - 1 )
			qsort( a , left , r - 1 );
		if ( r + 1 < right )
			qsort( a , r + 1 , right );
	}
}
int main()
{
	int i,a[] = {55,2,6,4,32,12,9,73,26,37};
	int length = sizeof( a ) / sizeof( int );
	for ( i = 0 ; i < length ; i++ )
		cout<<a[i]<<",";
	cout<<endl<<endl;

	qsort( a , 0 , length - 1 );

	for ( i = 0 ; i < length ; i++ )
		cout<<a[i]<<",";
	cout<<endl<<endl;
	return 0;
}