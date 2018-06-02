#include<iostream>
#include<cstring>
#include<cmath>
using namespace std;

int change(char s[])
{
	int i, k, len, n;
	len = strlen(s);
	n = k = 0;
	for (i = len - 1; i >= 0; i--)
	{
		if (s[i] >= '0' && s[i] <= '9')
			n += (s[i] - '0') * pow(16, k);
		else
			n += (s[i] - 'A' + 10) * pow(16, k);
		k++;
	}
	return n;
}

int main()
{
	int t; char s[100];

	cin >> t;
	while (t--)
	{
		cin >> s;
		cout << change(s) << endl;
	}

	#ifdef LOCAL
	pause();
	#endif

	return 0;
}