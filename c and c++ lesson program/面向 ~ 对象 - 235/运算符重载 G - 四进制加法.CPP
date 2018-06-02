# include <iostream>
# include <cstdio>
using namespace std;
class Quaternary;
Quaternary operator + ( Quaternary & , Quaternary & );
int CalculatingDigits( int );
class Quaternary
{
private:
	int number;
public:
	Quaternary()
	{
		number = 0;
	}
	Quaternary( int n )
	{
		number = n;
	}
	Quaternary( Quaternary &copy )
	{
		number = copy.number;
	}
	void SetN( int n )
	{
		number = n;
	}
	void Display()
	{
		printf("%d\n",number);
	}
	friend Quaternary operator + ( Quaternary & , Quaternary & );
	friend int CalculatingDigits( int );
};
Quaternary operator + ( Quaternary &one , Quaternary &two )
{
	int addition = one.number + two.number;
	int digit = CalculatingDigits(addition);
	int *p = new int [digit+1];
	int copy = addition;
	int i,k = 1;
	for ( i = 0 ; i < digit ; i++ )
	{
		p[i] = copy %10;
		copy /= 10;
	}
	p[i] = 0;
	for ( i = 0 ; i < digit ; i++ )
	{
		if ( p[i] >= 4 )
		{
			p[i+1]++;
			p[i] -= 4;
		}
	}
	copy = 0;
	for ( i = 0 ; i < digit + 1; i++ )
	{
		copy += p[i] * k;
		k *= 10;
	}
	Quaternary temp(copy);
	return temp;
}
int CalculatingDigits( int n )
{
	int sum = 0;
	while ( n )
	{
		sum++;
		n /= 10;
	}
	return sum;
}
int main()
{
	int t,n;
	Quaternary q1,q2;
	scanf("%d",&t);
	t--;
	scanf("%d",&n);
	q1.SetN(n);
	while ( t-- )
	{
		scanf("%d",&n);
		q2.SetN(n);
		q1 = q1 + q2;
	}
	q1.Display();
	return 0;
}
/*
题目描述
定义一个四进制的类，重定义“+”号实现四进制数的累加。

输入
第一行输入所需要的四进制数的个数
第二行开始，依次输入四进制数

输出
所有输入四进制quaternary数累加的和


样例输入
3
13
2
21
样例输出
102

*/