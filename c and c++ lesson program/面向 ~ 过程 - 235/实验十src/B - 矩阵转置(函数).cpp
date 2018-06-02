#include<iostream>
using namespace std;

void reverse(int m[][3])
{
	int i, j, temp;
	for (i = 0; i < 3; i++)
		for (j = i; j < 3; j++)
		{
			temp = m[i][j];
			m[i][j] = m[j][i];
			m[j][i] = temp;
		}
}

int main()
{
	int M[3][3], i, j;

	for (i = 0; i < 3; i++)
		for (j = 0; j < 3; j++)
			cin >> M[i][j];
	reverse(M);
	for (i = 0; i < 3; i++)
	{
		for (j = 0; j < 3; j++)
			cout << M[i][j] << ' ';
		cout << endl;
	}

	return 0;
}