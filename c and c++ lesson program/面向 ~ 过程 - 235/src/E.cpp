#include<iostream>
using namespace std;

int main()
{
	int t, i,j, a[10], key;

	cin >> t;
	while (t--)
	{
		for (i = 0; i < 10; i++)
			cin >> a[i];
		cin >> key;
		for (i = 0; i < 10; i++)
		{
			if (a[i] == key)
			{
				for (j = i; j <= 8; j++)
					a[j] = a[j + 1];
				break;
			}
		}
		if (i == 10)
			cout << "Not found\n";
		else
		{
			for (i = 0; i < 8; i++)
				cout << a[i] << ' ';
			cout << a[i] << endl;
		}

	}

	return 0;
}