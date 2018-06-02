#include<iostream>           
#include<iomanip>
using namespace std;
int k = 0;
long fib(int n)
{
	cout<<++k<<endl;
	if (n == 1 || n == 2)
		return 1L;
	else
		return fib(n - 1) + fib(n - 2);
}
int main()
{
	int num;
	long sum = 0;
	for (num = 1; num <= 40; ++num)
	{
		sum += fib(num);
		cout<<"sum"<<num<<" = "<<sum<<endl;
	}
	cout << "斐波那契数列前40项和为：" << sum << endl;
	return 0;
}
