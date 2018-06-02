#include<iostream>
using namespace std;

void bubble(int a[], int size)
{
	int i, temp;
	for (int pass = 1; pass < size; pass++)
	{
		for (i = 0; i < size - pass;i++)
			if (a[i]>a[i + 1])
			{
				temp = a[i];
				a[i] = a[i + 1];
				a[i + 1] = temp;
			}
	}
}

int main()
{
	int t, i, a[10];

	cin >> t;
	while (t--)
	{
		for (i = 0; i < 10; i++)
			cin >> a[i];
		bubble(a, 10);
		for (i = 0; i < 9; i++)
			cout << a[i] << ' ';
		cout << a[i] << endl;
	}

	return 0;
}