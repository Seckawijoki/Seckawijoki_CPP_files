# include <iostream>
using namespace std;
int main()
{
	int i,b,m;
	cin>>b;
	cout<<2<<endl;
	if ( ! (b %2) )
		b--;
	for ( m = 3 ; m <= b ; m += 2 )
	{	
		for ( i = 3 ; i <= m/2 ; i += 2 )
			if ( m %i == 0 )
				break;
		if ( i >= m/2 )
			cout<<m<<endl;
	}
	return 0;
}