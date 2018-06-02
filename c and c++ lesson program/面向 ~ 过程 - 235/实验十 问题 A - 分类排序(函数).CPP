# include <stdio.h>
void sort( int a[] , int n )
{
	int i,j;
	for ( i = 0 ; i < n ; i++ )
		for ( j = i + 1 ; j < n ; j++ )
		{
			if ( a[i] > a[j] )
			{
				a[i] = a[i] + a[j];
				a[j] = a[i] - a[j];
				a[i] = a[i] - a[j];
			}
		}
}
int find( int a[] , int n , int value )
{
	int i;
	for ( i = 0 ; i < n ; i++ )
		if ( a[i] == value )
			return i;
	return -1;
}
void display( int a[] , int n )
{
	int i;
	for ( i = 0 ; i < n-1 ; i++ )
		printf("%d ",a[i]);
	printf("%d\n",a[i]);
}
void reverse( int a[] , int n )
{
	int i,b[50];
	for ( i = 0 ; i < n ; i++ )
		b[n-1-i] = a[i];
	for ( i = 0 ; i < n ; i++ )
		a[i] = b[i];
}
int main()
{
	int i,x,k,t,a[50];
	scanf("%d",&t);
	while ( t-- )
	{
		for ( i = 0 ; i < 10 ; i++ )
			scanf("%d",&a[i]);
		scanf("%d",&x);
		k = find(a,10,x);
		if ( x %2 && k != -1 )
		{
			for ( i = k ; i < 9 ; i++ )
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
			int j = 0,c[10];
			sort(a,10);
			reverse(a,10);
			for ( i = 0 ; i < 10 ; i++ )
				if ( a[i] %2)
				{
					c[j] = a[i];
					j++;
				}
			for ( i = 0 ; i < 10 ; i++ )
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

/*
	提醒：
	4个函数：（调用的好处）
	升序排序、寻找相同数、输出整数数组、倒序。

	输出整数数组：形式中最后一个没带空格。

	
*/