#include<iostream>
#include<iomanip>
using namespace std;

int main()
{
	int N,i;
	double temp,up=1,down=1,sum=0;
	cin>>N;
	for(i=1;i<=N;i++)
	{
		temp=up;
		up+=down;
		down=temp;
		sum+=up/down;
	}
	cout<<setiosflags(ios::fixed)<<setprecision(2)<<sum<<endl;
	return 0;
}