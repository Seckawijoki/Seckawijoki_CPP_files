/*1. ��̼���a+aa+aaa+��+aa..a(n��a)��ֵ��a��ȡֵ��ΧΪ0��9��n��ȡֵ��ΧΪ0��5��n��a��ֵ���ɼ������룬��Ϊ������*/
#include<iostream>
using namespace std;

int main()
{
	double term=0, sum=0;
	int a,i,n;
	//cout<<"please input a,n: ";
	cin>>a;
	cin>>n;
	 for(i=1; i<=n;i++)
	 {
		 term= term*10+a;
		 sum+=term;
	 }

	 cout<<sum<<endl;
	return 0;
}