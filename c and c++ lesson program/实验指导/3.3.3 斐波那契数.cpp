# include <iostream.h>
# include <cstdio>
int main()
{
	int a,b,c,n,i;
	cout<<"쳲��������а�����0��0��\n\n";
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
		cout<<"쳲��������еĵ�"<<n<<"��Ϊ��"<<c<<endl;
	}
	return 0;
}