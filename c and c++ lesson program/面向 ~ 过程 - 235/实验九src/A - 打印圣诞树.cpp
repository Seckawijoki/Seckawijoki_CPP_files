#include<iostream>
using namespace std;

void printTree(int n)
{
	int i, j;
	for (i = 1; i <= n; i++)
	{
		for (j = 1; j <= n - i; j++)
			cout << ' ';
		for (; j <= n; j++)
			cout << '*';
		for (j = 1; j < i; j++)
			cout << '*';
		cout << endl;
	}
}

int main()
{
	int a;

	cin >> a;
	printTree(a);

	return 0;
}