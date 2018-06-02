# include <iostream.h>
# include <iomanip.h>

const long double PI = 3.1415926;

int main()

{
	int i = 1;
	double r;
	cout<<setw(10)<<PI<<endl;
	while ( i <= 2 )
	{
		cin>>r;
		cout<<setw(10)<<r<<endl;
		cout<<setw(10)<<long double(PI * r * r)<<endl;
		i++;
	}

	return 0;
}