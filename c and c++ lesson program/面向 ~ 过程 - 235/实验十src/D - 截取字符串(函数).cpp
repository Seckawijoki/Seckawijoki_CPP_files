#include<iostream>
#include<cstring>
using namespace std;

int substr(char str1[], char str2[], int index)
{
	int i, j, len;
	len = strlen(str1);
	if (index >= len)
		return 0;
	for (i = index, j = 0; i < len; i++)
		str2[j++] = str1[i];
	str2[j] = '\0';
	return 1;
}

int main()
{
	int t, i;

	cin >> t;
	while (t--)
	{
		char s1[100], s2[100];
		do{
			cin.getline(s1, 100);
		} while (s1[0] == '\0');
		cin >> i;
		if (i>=0 && substr(s1, s2, i))
			cout << s2;
		else
			cout << "IndexError";
		cout << endl;
	}

	return 0;
}