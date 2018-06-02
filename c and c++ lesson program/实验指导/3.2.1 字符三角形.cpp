# include <iostream.h>
# include <cstdio>
int main()
{
	char c;
	int i,j,n;
	cout<<"请成组地输入字符与数字的组合：";
	while ( 1 )
	{
		scanf("%c %d",&c,&n);
		for ( j = 1 ; j <= n ; j++ )
		{
			for ( i = n - j ; i >= 1 ; i-- )
				cout<<' ';
			for ( i = 1 ; i <= 2 * j - 1 ; i++ )
				cout<<c;
			cout<<endl;
		}
		cout<<endl;
	}
	return 0;
}