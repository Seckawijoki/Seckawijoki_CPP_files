# include <iostream.h>
# include <cstdio>
int main()
{
	int m,n,y = 1;
	int gcd( int m , int n );
	printf("����������һ��������");
	while ( 1 )
	{
		scanf("%d %d",&m,&n);
		printf("%d��%d����С������Ϊ��",m,n);
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
int gcd( int m , int n )//��Ȼ��ŷ�����㷨���������Լ����
{
	int r = 1;
	while ( 1 )
	{
		r = m %n;//���ԭ����r = m / n;
		if ( r != 0 )
		{
			m = n;
			n = r;
		}
		else
			break;
	}
	return m * n * n / m ;//��Ҫ��������㷨��
	/*
	eg. 
		18 / 12 = 1......6
		 m / n = ��.....r
		 m = n = 12;
		 n = r = 6 ;
		12 / 6 = 2......0
		 m / n = ��.....r

		  ��С������ = m * n / ��
	*/
}