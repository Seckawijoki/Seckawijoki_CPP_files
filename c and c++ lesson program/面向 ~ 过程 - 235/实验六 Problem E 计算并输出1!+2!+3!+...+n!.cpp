/*
Description
����n�����㲢���n��׳˵ĺ�

Input
n

Output
n��׳˵ĺ�

Sample Input
4

Sample Output
33
*/
# include <iostream>
using namespace std;
int main()
{
	int i,n,sum = 0;
	cin>>n;
	int mul( int i );
	for ( i = 1 ; i <= n ; i++ )
		sum += mul( i );
	cout<<sum<<endl;
	return 1;
}
int mul( int i )
{
	if ( i <= 1 )
		return 1;
	return mul( i - 1 ) * i;
}