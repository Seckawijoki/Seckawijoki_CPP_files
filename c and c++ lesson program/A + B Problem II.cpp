# include <iostream>
# include <string>
using namespace std;
int main()
{
	int n, k = 1;
	cin>>n;
	while ( n-- )
	{
		int i, j;
		string a, b, aa, bb;
		int c[1000], d[1000], e[1000], f[1000];
		cin>>a>>b;
		aa = a;
		bb = b;
		int la = a.length();
		int lb = b.length();
		int length = la > lb ? la : lb;
		for ( i = 0 ; i < la ; ++i )
			c[i] = a[la-1-i] - '0';
		for ( i = 0 ; i < lb ; ++i )
			d[i] = b[lb-1-i] - '0';
		if ( la >= lb )
			for ( i = lb ; i < la ; ++i )
				d[i] = 0;
		else
			for ( i = la ; i < lb ; ++i )
				c[i] = 0;
		for ( i = 0 ; i < length ; ++i )
			f[i] = c[i] + d[i];
		for ( i = 0 ; i < length ; ++i )
		{
			if ( f[i] > 9 )
			{
				f[i] -= 10;
				if ( f[i+1] >= 0 )
					++f[i+1];
				else
					f[i+1] = 1;
			}
		}
		if ( f[length-1] > 9 || f[length] == 1 )
		{
			
			for ( i = 0 ; i <= length ; ++i )
				e[i] = f[length-i];
		}
		else
		{
			cout<<a[length]<<endl;
			for ( i = 0 ; i < length ; ++i )
				e[i] = f[length-1-i];
		}
		for ( j = 0 ; j < i ; ++j )
			a[j] = e[j] + '0';
		a[j] = '\0';
		cout<<"Case "<<k++<<":\n"<<aa<<" + "<<bb<<" = "<<a<<"\n\n";
	}
	return 0;
}
/*

3
4321 2349
99 1
91 10

2
1 2
112233445566778899 998877665544332211

*/
