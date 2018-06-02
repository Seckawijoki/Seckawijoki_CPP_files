# include <stdio.h>
void sort( int a[] , int n )
{
	int i,j;
	for ( i = 0 ; i < n ; i ++ )
		for ( j = i + 1 ; j < n ; j ++ )
			if ( a[i] > a[j] )
			{			
				a[i] = a[i] + a[j];
				a[j] = a[i] - a[j];
				a[i] = a[i] - a[j];				
			}
}
int find( int a[] , int n , int x )
{
	int i;
	for ( i = 0 ; i < n ; i ++ )
		if ( a[i] == x )
			return i;//应返回下标。
	return -1;
}
void display( int a[] ,int n )
{
	int i;
	for ( i = 0 ; i < n - 1; i ++ )
		printf("%d ",a[i]);
	printf("%d\n",a[i]);
}
void reverse( int a[], int n )
{
	int i,b[11];
	for ( i = 0 ; i < n ; i ++ )
		b[i] = a[i];
	for ( i = 0 ; i < n ; i ++ )
		a[i] = b[n-1-i];
}
int main()
{
	int t,i,a[11],k,x;
	scanf("%d",&t);
	while ( t-- )
	{
		for ( i = 0 ; i < 10 ; i ++ )
			scanf("%d",&a[i]);
		scanf("%d",&x);
		k = find(a,10,x);
		if ( x %2 && k != -1 )
		{
			for ( i = k ; i < 9 ; i ++ )//写成i < 10 了 (=.=)！
				a[i] = a[i+1];
			sort(a,9);
			display(a,9);
		}
		else if ( x %2 == 0 && k == -1 )
		{
			a[10] = x;
			sort(a,11);
			reverse(a,11);
			display(a,11);
		}
		else
		{
			int j = 0,c[11];
			sort(a,10);//复制忘了改 - -!
			reverse(a,10);//复制忘了改 - -!
			for ( i = 0 ; i < 10 ; i ++ )
				if ( a[i] %2 ) 
				{
					c[j] = a[i];
					j++;
				}
			for ( i = 0 ; i < 10 ; i ++ )
				if ( a[i] %2 == 0 ) 
				{
					c[j] = a[i];
					j++;
				}
			display(c,10);
		}
	}
	return 0;
}