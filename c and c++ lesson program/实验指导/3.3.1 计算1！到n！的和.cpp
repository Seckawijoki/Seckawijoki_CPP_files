# include <iostream.h>
# include <cstdio>
int main()
{
	int i,n,sum;
	while ( 1 )
	{
		scanf("%d",&n);
		sum = 0;//ע�����㡣
		int multiple( int i );
		for ( i = 1 ; i <= n ; i++ )
			sum += multiple(i);
		cout<<"�����1����"<<n<<"���ĺ�Ϊ��"<<sum<<endl;
	}
	return 0;
}
int multiple( int i )
{
	if ( i == 1 )
		return 1;
	return ( i - 1 ) * i;
}