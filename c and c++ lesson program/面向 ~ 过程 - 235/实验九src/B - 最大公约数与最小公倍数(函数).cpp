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
	if (a < b) //������������ʹ��������a��
	{
		temp = a;
		a = b;
		b = temp;
	}
	while (b != 0) //����շ������ֱ��bΪ0Ϊֹ
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
	temp_lcm = a*b / gcd(a, b); //��С��������������֮���������Լ��
	return temp_lcm;
}