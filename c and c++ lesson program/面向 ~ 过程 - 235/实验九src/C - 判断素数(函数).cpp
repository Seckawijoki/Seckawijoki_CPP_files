#include<iostream>
using namespace std;

bool isPrime(int n) 
{
	int i;
	if (n <= 1) 
		return false;  
	if (n == 2) 
		return true;    
	if (n%2 == 0) // 所有偶数都不是素数
		return false;  
	for (i = 3; i * i <= n; i += 2)    //  只需要检查奇数  
	{
		if (n%i == 0)
			return false;
	}
	return true;
}

int main()
{
	int t, a;

	cin >> t;
	while (t--)
	{
		cin >> a;
		if (isPrime(a))
			cout << "prime\n";
		else
			cout << "not prime\n";
	}

	return 0;
}