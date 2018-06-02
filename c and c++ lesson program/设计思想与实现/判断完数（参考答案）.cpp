#include<iostream>
using namespace std;

int main()
{
	int n,i,sum=1;
	cin>>n;
	for(i=2;i<n;i++)
	{
		if(n%i==0)
			sum+=i;
	}
	if(sum==n)
		cout<<"Yes"<<endl;
	else
		cout<<"No"<<endl;
	return 0;
}