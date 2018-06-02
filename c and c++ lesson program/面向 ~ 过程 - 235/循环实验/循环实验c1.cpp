/*1. 编程计算a+aa+aaa+…+aa..a(n个a)的值，a的取值范围为0—9，n的取值范围为0—5。n和a的值都由键盘输入，均为整数。*/
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