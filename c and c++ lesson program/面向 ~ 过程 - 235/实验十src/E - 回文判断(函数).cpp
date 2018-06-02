#include<iostream>
#include<cstring>
using namespace std;

int isPalindrome(char s[])
{
	int i, len;
	len = strlen(s);
	for (i = 0; i < len/2; i++)
	{
		if (s[i] != s[len - i - 1])
			return 0;
	}
	return 1;
}

int main()
{
	int t; char s[100];

	cin >> t;
	while (t--)
	{
		cin >> s;
		if (isPalindrome(s))
			cout << "Yes";
		else
			cout << "No";
		cout << endl;
	}

	return 0;
}