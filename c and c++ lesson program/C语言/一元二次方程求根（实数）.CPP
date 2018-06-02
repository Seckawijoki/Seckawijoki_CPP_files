#include<iostream>
#include<iomanip>
#include<cmath>
using namespace std;

int main()
{
	cout<<"求一元二次方程的两根。请输入叁系数：";
	float a,b,c;
	cin>>a>>b>>c;
	cout<<"x1="<<fixed<<setprecision(2)<<( -b + sqrt( b * b - 4 * a * c ) ) / ( 2 * a )<<endl;
	cout<<"x2="<<fixed<<setprecision(2)<<( -b - sqrt( b * b - 4 * a * c ) ) / ( 2 * a )<<endl;
	//"fixed" = "setiosflags(ios::fixed)"

	return 0;
}
