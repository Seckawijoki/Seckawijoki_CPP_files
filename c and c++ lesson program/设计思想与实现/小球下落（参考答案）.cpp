#include<iostream>
#include<iomanip>
using namespace std;

int main()
{
	int N,i;
	double M,h,l=0;
    cin>>M>>N;
	h=M;
    for(i=1;i<=N;i++) 
    {
		l+=2*h;
        h/=2;
    }
    l-=M;
    cout<<setiosflags(ios::fixed)<<setprecision(2)<<h<<" "<<l<<endl; 
    return 0;
}