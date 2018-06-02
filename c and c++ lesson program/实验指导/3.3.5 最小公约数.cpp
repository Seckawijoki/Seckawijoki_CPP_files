# include <iostream.h>
# include <cstdio>
int main()
{
	int m,n,y = 1;
	int gcd( int m , int n );
	printf("请成组地输入一对整数：");
	while ( 1 )
	{
		scanf("%d %d",&m,&n);
		printf("%d和%d的最小公倍数为：",m,n);
		if ( m < n )
		{
			m = m + n;
			n = m - n;
			m = m - n;
		}
		y = gcd( m , n );
		printf("%d\n\n",y);
	}

	return 0;
}
int gcd( int m , int n )//依然用欧几里算法，先求最大公约数。
{
	int r = 1;
	while ( 1 )
	{
		r = m %n;//搞错。原来：r = m / n;
		if ( r != 0 )
		{
			m = n;
			n = r;
		}
		else
			break;
	}
	return m * n * n / m ;//重要是这里的算法。
	/*
	eg. 
		18 / 12 = 1......6
		 m / n = 商.....r
		 m = n = 12;
		 n = r = 6 ;
		12 / 6 = 2......0
		 m / n = 商.....r

		  最小公倍数 = m * n / 商
	*/
}