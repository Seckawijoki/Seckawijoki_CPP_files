# include <iostream.h>
# include <iomanip.h>

int main(void)

{
	int n,m,line;
	int combination( int n , int m );
	cout<<"请输入要显示杨辉三角的行数：";//限于13行，14行开始便不美观。
	while ( 1 )
	{
		cin>>line;
		for ( m = 1 ; m <= line ; m++ )
		{
			cout<<setw( 3 * line - 2 * m )<<' ';
			for ( n = 1 ; n <= m ; n++ )
				cout<<setw(4)<<combination( n - 1 , m - 1 );
			cout<<endl;
		}
	}
	return 0;
}

int combination( int n , int m )
{
	int i;
	float Cnm = 1;//原来用int，发现中间计算会出现小数，便用float。
	for ( i = 1 ; i <= n ; i++ )
		Cnm = Cnm * ( m + 1 - i ) / i;//原来分母搞错成( n + i - 1 )。

	return int(Cnm);
}