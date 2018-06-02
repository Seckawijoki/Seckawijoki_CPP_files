# include <iostream.h>
# include <cstdio>
int main()
{
	int a,b,c,n,i;
	cout<<"斐波那契数列包括第0项0。\n\n";
	while ( 1 )
	{
		scanf("%d",&n);
		a = 0;
		b = 1;
		c = 0;
		for ( i = 1 ; i < n ; i++ )
		{
			c = a + b;
			a = b;
			b = c;
		}
		cout<<"斐波那契数列的第"<<n<<"项为："<<c<<endl;
	}
	return 0;
}