#include<iostream>
#include<iomanip>
#include<cmath>
using namespace std;
int main()
{
	long double r;
	int n,i;
	cin>>n;
	for ( i = 1 ; i <= n ; i++ )
	{
		cin>>r;
		cout<<setiosflags(ios::showpoint)<<setiosflags(ios::fixed)
										<<setprecision(6)
										<<3.141592653 * r * r
										<<endl;
	}
	return 0;
}