#include<iostream>
using namespace std;
int main()
{
	int a,b,c;
	cin>>a>>b>>c;
	/*
	if ( a >= b && a >= c )
		cout<<a;
	else if ( b > a && b > c )
		cout<<b;
	else if ( c > a && c > b )
		cout<<c ;
		
	*/
	a >= b ? 
		( a >= c ? cout<<a<<endl : cout<<c<<endl ) : 
		( b >= c ? cout<<b<<endl : cout<<c<<endl );

	return 0;
}