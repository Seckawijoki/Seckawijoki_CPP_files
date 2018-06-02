#include<iostream>
using namespace std;

int main()
{
	int t, i, a[10], ans;

	cin >> t;
	while (t--)
	{
		for (i = 0; i < 10; i++)
			cin >> a[i];
		ans = 0;
		for (i = 0; i < 10; i++)
			if (a[i] < 0)
				ans++;
		cout << ans << endl;
	}

	return 0;
}