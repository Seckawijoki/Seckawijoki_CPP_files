#include<iostream>
using namespace std;

void sort(int a[], int n)
{
	int i, j, temp;
	for (j = 1; j < n; j++)
	{
		for (i = 0; i < n - j; i++)
			if (a[i]>a[i + 1])
			{
				temp = a[i];
				a[i] = a[i + 1];
				a[i + 1] = temp;
			}
	}
}

int find(int a[], int n, int value)
{
	for (int i = 0; i < n; i++)
		if (a[i] == value)
			return i;
	return -1;
}

void reverse(int a[], int n)
{
	int i, b[1000];
	for (i = 0; i < n; i++)
		b[i] = a[i];
	for (i = n - 1; i >= 0; i--)
		a[i] = b[n - i - 1];
}

void display(int a[], int n)
{
	int i;
	for (i = 0; i < n - 1; i++)
		cout << a[i] << ' ';
	cout << a[i] << endl;
}

void del(int a[], int n, int value)
{
	int i, j;
	j = find(a, n, value);
	if (j >= 0)
	{
		for (i = j + 1; i < n; i++)
			a[i - 1] = a[i];
	}
}


int main()
{
	int t, i, num[10], a, odd[10], even[10], j, k;

	cin >> t;
	while (t--)
	{
		for (i = 0; i < 10; i++)
			cin >> num[i];
		cin >> a;
		if (a % 2 && find(num, 10, a) >= 0)
		{
			del(num, 10, a);
			sort(num, 9);
			display(num, 9);
		}
		else if (a % 2 == 0 && find(num, 10, a) == -1)
		{
			num[10] = a;
			sort(num, 11);
			reverse(num, 11);
			display(num, 11);
		}
		else
		{
			j = k = 0;
			for (i = 0; i < 10; i++)
				if (num[i] % 2)
					odd[j++] = num[i];
				else
					even[k++] = num[i];
			sort(odd, j);
			sort(even, k);
			reverse(odd, j);
			reverse(even, k);
			for (i = 0; i < j; i++)
				cout << odd[i] << ' ';
			display(even, k);
		}
	}

	return 0;
}