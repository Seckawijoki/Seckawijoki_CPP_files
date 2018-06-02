# include <iostream>
using namespace std;
int main()
{
	int i,j,n;
	cin>>n;
	for ( i = 1 ; i <= n ; i++ )
	{
		for ( j = n - i ; j >= 1 ; j-- )
			cout<<' ';
		for ( j = 1 ; j <= ( 2 * i - 1 ) ; j++ )
			cout<<'#';
		cout<<endl;
	}
	return 0;
}