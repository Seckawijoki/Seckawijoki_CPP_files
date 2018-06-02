#include<iostream>
using namespace std;

int main()
{
	int t, i, a[10], key;

	cin >> t;
	while (t--)
	{
		for (i = 0; i < 10; i++)
			cin >> a[i];
		cin >> key;
		for (i = 0; i < 10; i++)
		{
			if (a[i] == key)
				break;
		}
		if (i >= 10)
			cout << "Not found\n";
		else
			cout << i << endl;
	}

	return 0;
}