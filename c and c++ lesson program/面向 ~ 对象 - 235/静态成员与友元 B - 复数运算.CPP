/*
题目描述
复数类的声明如下：

要求如下：
<!--[if !supportLists]-->
1.<!--[endif]-->实现复数类和友元函数addCom和outCom。

<!--[if !supportLists]-->
2.参考addCom函数为复数类增加一个友元函数minusCom，
用于实现两个复数的减法

3.<!--[endif]-->在main函数中，
通过友元函数，实现复数的加减法和复数的输出。

输入
第1行：第1个复数的实部和虚部

第2行：需进行运算的次数，注意：是连续运算。
具体结果可参考样例

第3行开始，每行输入运算类型，
以及参与运算的复数的实部与虚部。
“+”表示复数相加，“-”表示复数相减。

输出
每行输出复数运算后的结果，复数输出格式为
“(实部,虚部)”。

样例输入
10 10
3
+ 20 10
- 15 5
+ 5 25
样例输出
(30,20)
(15,15)
(20,40)
*/
# include <stdio.h>
class Complex
{
private:
	double real,imag;
public:
	Complex()
	{
		real = 0;
		imag = 0;
	}
	Complex( double a , double b )
	{
		real = a;
		imag = b;
	}
	Complex( Complex &z )
	{
		real = z.real;
		imag = z.imag;
	}
	friend Complex Addition( Complex z1, Complex z2 );
	friend Complex Subtraction( Complex z1, Complex z2 );
	friend void Display( Complex z );
};
Complex Addition( Complex z1, Complex z2 )
{
	Complex z(z1.real+z2.real,z1.imag+z2.imag);
	return z;
}
Complex Subtraction( Complex z1, Complex z2 )
{
	Complex z(z1.real-z2.real,z1.imag-z2.imag);
	return z;
}
void Display( Complex z )
{
	printf("(%d,%d)\n",int(z.real),int(z.imag));
}
int main()
{
	int t;
	char symbol;
	double a,b;
	scanf("%lf%lf",&a,&b);
	Complex z1(a,b);
	scanf("%d",&t);
	while ( t-- )
	{
		getchar();
		scanf("%c",&symbol);
		scanf("%lf%lf",&a,&b);
		Complex z2(a,b);
			 if ( symbol == '+' )
			z1 = Addition(z1,z2);
		else if ( symbol == '-' )
			z1 = Subtraction(z1,z2);
		Display(z1);
	}
	return 0;
}