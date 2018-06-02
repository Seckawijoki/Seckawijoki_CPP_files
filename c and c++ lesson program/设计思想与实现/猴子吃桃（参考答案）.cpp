#include<iostream>
using namespace std;

int main()
{
	int N,i,a=1;
	cin>>N;
	for(i=1;i<N;i++)
		a=(a+1)*2;
	cout<<a<<endl;
	return 0;
}