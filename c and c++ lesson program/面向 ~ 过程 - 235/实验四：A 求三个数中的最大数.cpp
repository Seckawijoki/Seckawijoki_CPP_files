# include <iostream>
using namespace std;
int main()
{
	int a,b,c;
	cin>>a>>b>>c;
	a > b ? a = b : 1 ;
	a > c ? a = c : 1 ;
	cout<<a<<endl;
	return 0;
}