#include<iostream>
using namespace std;

long long C(int n, int r)
{
	long long i, ans[100];
	if (r == 0)
		return 1;
	if (r == 1)
		return n;
	ans[0] = 1, ans[1] = n;
	for (i = 2; i <= r; i++)
		ans[i] = ans[i - 1] * (n - i + 1) / i;
	return ans[r];
}

int main()
{
	int t, m, n;
	
	cin >> t;
	while (t--)
	{
		cin >> m >> n;
		cout << C(m, n) << endl;
	}

	return 0;
}