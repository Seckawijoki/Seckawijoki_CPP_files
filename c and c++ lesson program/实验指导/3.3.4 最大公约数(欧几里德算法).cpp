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
		printf("%d��%d�����Լ��Ϊ��",m,n);
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
int gcd( int m , int n )//ŷ�����㷨��
{
	int r = 1;
/*
	while ( 1 )
	{
		r = m %n;//���ԭ����r = m / n;
		if ( r )
		{
			m = n;
			n = r;
		}
		else
			break;
	}
	return n;
*/
	while ( n )
	{
		r = m %n;
		m = n;
		n = r;
	}
	return m;
}