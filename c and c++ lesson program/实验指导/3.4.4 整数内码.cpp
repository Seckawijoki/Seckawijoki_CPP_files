# include <iostream.h>
# include <iomanip.h>
# include <math.h>
# include <cstdio>
int main()
{
	long n;
	int second( long n );
	printf("��������������");
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
	cout<<n<<"��32λ��������Ϊ��";
	if ( n >= 0)
	{
		for ( i = 0 ; i <= 31 ; i++ )
		{
			a[i] = n %2;
			n /= 2;
			//����ط�ԭ������2�����ǲ��Եġ�
		}
		for ( i = 31 ; i >= 0 ; i-- )
		{
			cout<<a[i];
		}
	}
	
	else	//�������൱�������ֵ��1���ٸ���λȡ����
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
