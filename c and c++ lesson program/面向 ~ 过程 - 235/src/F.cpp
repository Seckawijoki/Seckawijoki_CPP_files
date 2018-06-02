#include<iostream>
using namespace std;

int main()
{
	int i, j, a[20];bool ans[20];

	for (i = 0; i < 20; i++)
		ans[i] = false;
	for (i = 0; i < 20; i++)
		cin >> a[i];
	for (i = 0; i < 20; i++)
		for (j = 0; j < 20; j++)
		{
			if (j == i)
				continue;
			if (a[i] % a[j] == 0)
			{
				ans[i] = true;
				break;
			}
		}
	for (i = 0; i < 20; i++)
		if (ans[i])
			cout << a[i] << endl;

	return 0;
}