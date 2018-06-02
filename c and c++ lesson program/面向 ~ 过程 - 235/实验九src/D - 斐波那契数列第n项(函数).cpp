#include<iostream>
using namespace std;

int Fn(int n)
{
	int i, a[100000];
	a[0] = 0; a[1] = 0; a[2] = 1;
	for (i = 2; i < n; i++)
		a[i + 1] = a[i] + a[i - 1];
	return a[n];
}

int main()
{
	int n;

	cin >> n;
	cout << Fn(n + 1) << endl;

	return 0;
}