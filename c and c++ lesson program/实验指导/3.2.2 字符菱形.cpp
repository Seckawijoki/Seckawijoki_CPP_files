# include <iostream>
using namespace std;
int main()
{
	char c;
	int i,j,n;
	while ( 1 )
	{
		//scanf("%c %d",&c,&n);
		cin>>c>>n;
		for ( j = 1 ; j <= n ; j++ )
		{
			//for ( i = n - j ; i >= 1 ; i-- )
			for ( i = 1 ; i <= n - j ; ++i )
				cout<<' ';//printf(" ");
			for ( i = 1 ; i <= 2 * j - 1 ; i++ )
				cout<<c;
			cout<<endl;
		}
		for ( j = n - 1 ; j >= 1 ; j-- )
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
