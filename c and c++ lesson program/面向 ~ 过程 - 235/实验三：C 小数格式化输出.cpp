#include<iostream>
#include<iomanip>
#include<cmath>
using namespace std;
int main()
{
	long double a;
	cin>>a;
	cout<<setw(10)<<setiosflags(ios::right)<<setiosflags(ios::showpoint)<<sqrt(a)<<endl;//���ÿ�ȣ�Ĭ���Ҷ��롣
	cout<<setw(10)<<setiosflags(ios::right)<<setiosflags(ios::showpoint)<<setprecision(8)
																		<<sqrt(a)<<endl;//��Чλ����
	cout<<setw(10)<<setiosflags(ios::right)<<setiosflags(ios::showpoint)<<setiosflags(ios::fixed)
																		<<setprecision(8)
																		<<sqrt(a)<<endl;//С��λ����
	return 0;
}