# include <iostream.h>
# include <iomanip.h>
# include <math.h>
# include <cstdio>
int main()
{
	long n;
	int second( long n );
	printf("请输入多个整数：");
	while ( 1 )
	{
		scanf("%d",&n);
		second( n );
	}
	return 0;
}

int second( long n )
{
	int i,a[32];
	cout<<n<<"的32位二进制码为：";
	if ( n >= 0)
	{
		for ( i = 0 ; i <= 31 ; i++ )
		{
			a[i] = n %2;
			n /= 2;
			//这个地方原来除以2的幂是不对的。
		}
		for ( i = 31 ; i >= 0 ; i-- )
		{
			cout<<a[i];
		}
	}
	
	else	//负数的相当于其绝对值少1，再各个位取反。
	{
		n = abs( n ) - 1;
		for ( i = 0 ; i <= 31 ; i++ )
		{
			a[i] = n %2;
			n /= 2;
		}
		for ( i = 31 ; i >= 0 ; i-- )
		{
			cout<<( a[i] ? 0 : 1 );
		}
	}
	cout<<endl;
	return 1;
}
