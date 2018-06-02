#include<iostream>
using namespace std;

int fn(int n)
{
	if (n == 0)
		return 0;
	else if (n == 1)
		return 1;
	return fn(n - 1) + fn(n - 2);
}

int main()
{
	int n;

	cin >> n;
	cout << fn(n) << endl;

	return 0;
}