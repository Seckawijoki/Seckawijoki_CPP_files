/*
Description
дһ����������һ����λ���֣�Ҫ��������ĸ������ַ���
��ÿ�������ּ�ո�������1990��Ӧ���"1 9 9 0"��

Input
һ����λ��

Output
���ӿո����

Sample Input
1990
Sample Output
1 9 9 0 

*/
# include <iostream>
# include <ctype.h>
using namespace std;
int szzzfc( int x )
{
	int a,b,c,d;
	a = x /1000;
	x -= a * 1000;
	b = x /100;
	x -= b * 100;
	c = x /10;
	d = x %10;
	cout<<toascii(a)<<' '
		<<toascii(b)<<' '
		<<toascii(c)<<' '
		<<toascii(d)<<" \n";
	return 0;
}
int main()
{
	int x;
	cin>>x;
	szzzfc(x);
	return 0;
}