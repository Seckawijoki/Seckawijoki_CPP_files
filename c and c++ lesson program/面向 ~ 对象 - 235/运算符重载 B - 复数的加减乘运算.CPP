/*
题目描述
定义一个复数类，通过重载运算符：+、-、*，
实现两个复数之间的各种运算。

要求如下：
1.实现Complex类；
2.编写main函数，初始化两个Complex对象，
计算它们之间的加减乘，并输出结果。

输入
第1行：输入两个int类型的值，
	   分别为第一个Complex对象的实部和虚部。
第2行：输入两个int类型的值，
	   分别为第二个Complex对象的实部和虚部。

输出
第1行：两个Complex对象相加后的输出结果。
第2行：两个Complex对象相减后的输出结果。
第3行：两个Complex对象相乘后的输出结果。

样例输入
10 20
50 40
样例输出
Real=60 Image=60
Real=-40 Image=-20
Real=-300 Image=600
*/
# include <iostream>
# include <cmath>
using namespace std;
class Complex;
Complex operator + ( Complex & , Complex & );
Complex operator - ( Complex & , Complex & );
Complex operator * ( Complex & , Complex & );
class Complex
{
private:
	double real;
	double image;
public:
	Complex( double x = 0, double y = 0 )
	{
		real = x;
		image = y;
	}
	friend Complex operator + ( Complex & , Complex & );
	friend Complex operator - ( Complex & , Complex & );
	friend Complex operator * ( Complex & , Complex & );
	void Display()
	{
		cout<<"Real="<<real<<" Image="<<image<<endl;
	}
};
Complex operator + ( Complex &z1 , Complex &z2 )
{
	Complex temp;
	temp.real = z1.real + z2.real;
	temp.image = z1.image + z2.image;
	return temp;
}
Complex operator - ( Complex &z1 , Complex &z2 )
{
	Complex temp;
	temp.real = z1.real - z2.real;
	temp.image = z1.image - z2.image;
	return temp;
}
Complex operator * ( Complex &z1 , Complex &z2 )
{
	Complex temp;
	temp.real = z1.real * z2.real - z1.image * z2.image;
	temp.image = z1.image * z2.real + z1.real * z2.image;
	return temp;
}
int main()
{
	double a,b,c,d;
	cin>>a>>b>>c>>d;
	Complex z1(a,b),z2(c,d),z3;
	z3 = z1 + z2;
	z3.Display();
	z3 = z1 - z2;
	z3.Display();
	z3 = z1 * z2;
	z3.Display();
	return 0;
}