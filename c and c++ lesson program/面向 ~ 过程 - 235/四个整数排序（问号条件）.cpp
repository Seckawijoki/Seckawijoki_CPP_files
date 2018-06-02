/*
题目描述
输入4个整数，要求按从小到大的顺序输出

输入
输入4个无序的整数

输出
输出已排序的4个整数

样例输入
90 -2 6 45
样例输出
-2 6 45 90
*/
# include <iostream>
using namespace std;

int main()
{
	int a,b,c,d;
	cin>>a>>b>>c>>d;
	a > b ? a = a + b , b = a - b , a = a - b : a = a ;
	a > c ? a = a + c , c = a - c , a = a - c : a = a ;
	a > d ? a = a + d , d = a - d , a = a - d : a = a ;

	b > c ? b = b + c , c = b - c , b = b - c : b = b ;
	b > d ? b = b + d , d = b - d , b = b - d : b = b ;

	c > d ? c = c + d , d = c - d , c = c - d : c = c ;

	cout<<a<<" "<<b<<" "<<c<<" "<<d<<endl;

	return 0;
}