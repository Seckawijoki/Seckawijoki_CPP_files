#include<iostream>
using namespace std;

int main()
{
	int i,j, a[10], num;

	for (i = 0; i <= 8; i++)
		cin >> a[i];
	cin >> num;
	for (i = 0; i <= 8; i++)
	{
		if (num < a[i])
		{
			for (j = 8; j >= i; j--)
				a[j + 1] = a[j];
			a[i] = num;
			break;
		}
	}
	for (i = 0; i <= 9; i++)
		cout << a[i] << endl;

	return 0;
}