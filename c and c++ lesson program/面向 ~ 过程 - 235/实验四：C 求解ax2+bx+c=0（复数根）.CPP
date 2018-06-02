#include<iostream>
#include<iomanip>
#include<cmath>
using namespace std;
int main()
{
	double x,del;
	int a,b,c,i = 0;
	cout<<"请依次输入一元二次方程的三个系数a,b,c：";
	cin>>a>>b>>c;
	if ( b * b - 4 * a * c >= 0 )
		del = sqrt( b * b - 4 * a * c );//已开方的delta
	else 
	{
		del = sqrt( 4 * a * c - b * b );
		i = 1;
	}
	cout<<"\nx1="<<setiosflags(ios::showpoint)<<setiosflags(ios::fixed)
												<<setprecision(3)
												<<double( -b ) / 2 / a 
												<<'+'
												<<del / 2 / a;
	if ( i )
		cout<<'i';
	cout<<'\n';
	cout<<"x2="<<setiosflags(ios::showpoint)<<setiosflags(ios::fixed)
												<<setprecision(3)
												<<double( -b ) / 2 / a  
												<<'-'
												<<del / 2 / a;
	if ( i )
		cout<<'i';

	return 0;
}