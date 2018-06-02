# include <iostream>
using namespace std;
int main()
{
	int i,j,n;
	cin>>n;
	if ( n > 79 )
		n = 79;
	for ( i = 1 ; i <= n ; i++ )
	{
		for ( j = 1 ; j <= n ; j++ )
			cout<<'#';
	cout<<endl;
	}
	return 0;
}
