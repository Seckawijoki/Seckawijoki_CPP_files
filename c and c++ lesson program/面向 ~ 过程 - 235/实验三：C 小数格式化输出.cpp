#include<iostream>
#include<iomanip>
#include<cmath>
using namespace std;
int main()
{
	long double a;
	cin>>a;
	cout<<setw(10)<<setiosflags(ios::right)<<setiosflags(ios::showpoint)<<sqrt(a)<<endl;//设置宽度：默认右对齐。
	cout<<setw(10)<<setiosflags(ios::right)<<setiosflags(ios::showpoint)<<setprecision(8)
																		<<sqrt(a)<<endl;//有效位数。
	cout<<setw(10)<<setiosflags(ios::right)<<setiosflags(ios::showpoint)<<setiosflags(ios::fixed)
																		<<setprecision(8)
																		<<sqrt(a)<<endl;//小数位数。
	return 0;
}