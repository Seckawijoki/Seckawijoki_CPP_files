#include<iostream>
using namespace std;

int lcm(int, int);
int gcd(int, int);

int main()
{
	int t, a, b;

	cin >> t;
	while (t--)
	{
		cin >> a >> b;
		cout << gcd(a, b) << ' ' << lcm(a, b) << endl;
	}

	#ifdef LOCAL
	pause();
	#endif

	return 0;
}

int gcd(int a, int b)
{
	int temp;
	if (a < b) //交换两个数，使大数放在a上
	{
		temp = a;
		a = b;
		b = temp;
	}
	while (b != 0) //利用辗除法，直到b为0为止
	{
		temp = a%b;
		a = b;
		b = temp;
	}
	return a;
}

int lcm(int a, int b)
{
	int temp_lcm;
	temp_lcm = a*b / gcd(a, b); //最小公倍数等于两数之积除以最大公约数
	return temp_lcm;
}