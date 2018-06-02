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

  a = a + b
  b = a - b
  a = a - b
*/
# include <iostream>
using namespace std;

int main()
{
	int a,b,c,d;
	cout<<"请输入四个整数：";
	cin>>a>>b>>c>>d;
	a > b ? a = a + b , b = a - b , a = a - b : 1 ;
	a > c ? a = a + c , c = a - c , a = a - c : 1 ;
	a > d ? a = a + d , d = a - d , a = a - d : 1 ;

	b > c ? b = b + c , c = b - c , b = b - c : 1 ;
	b > d ? b = b + d , d = b - d , b = b - d : 1 ;

	c > d ? c = c + d , d = c - d , c = c - d : 1 ;

	cout<<"\n这四个整数从小到大的排序为："<<a<<" "<<b<<" "<<c<<" "<<d<<endl;

	return 0;
}