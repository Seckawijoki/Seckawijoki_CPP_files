/*
题目描述
已知一个复数包含实数部和虚数部，操作包括初始化、输出、加、减，具体实现要求如下：
1.用成员函数的方式实现运算符“+”和运算符"-"的重载，实现两个复数对象的相加或相减。
2.用构造函数的方法实现对象的初始化，用输出函数来完成对象的输出

输入
第一行输入t表示有t个示例
第二行输入第一个复数的实数部和虚数部
第三行输入第二个复数的实数部和虚数部
依次类推，每两行输入下一个示例的两个复数

输出
对于每个示例，
第一行输出两个复数相加的结果，
第二行输出两个复数相减的结果，是第一个复数减去第二个复数

样例输入
3
4 4
2 2
3 -5
4 5
6 7
6 8

样例输出
6+6i
2+2i
7
-1-10i
12+15i
-i

*/
# include <stdio.h>
class Complex
{
private:
	int a;
	int b;
public:
	Complex( int x = 0 , int y = 0 )
	{
		a = x;
		b = y;
	}
	Complex operator + ( Complex &z  )
	{
		Complex temp;
		temp.a = this->a + z.a ;
		temp.b = this->b + z.b ;
		return temp;
	}
	Complex operator - ( Complex &z  )
	{
		Complex temp;
		temp.a = this->a - z.a ;
		temp.b = this->b - z.b ;
		return temp;
	}
	void Display()
	{
		if ( a == 0 )
		{
			if ( b == 0 )
				printf("0\n");
			else if ( b ==  1 )
				printf( "i\n");
			else if ( b == -1 )
				printf("-i\n");
			else
				printf("%di\n",b);
		}
		else
		{
			if ( b == 0 )
				printf("%d\n",a);
			else if ( b ==  1 )
				printf( "%d+i\n",a);
			else if ( b == -1 )
				printf("%d-i\n",a);
			else if ( b > 0 )
				printf("%d+%di\n",a,b);
			else if ( b < 0 )
				printf("%d%di\n",a,b);
		}
	}
};
int main()
{
	int t,a1,b1,a2,b2;
	scanf("%d",&t);
	while ( t-- )
	{
		scanf("%d%d%d%d",&a1,&b1,&a2,&b2);
		Complex z1(a1,b1),z2(a2,b2),z3;
		z3 = z1 + z2;
		z3.Display();
		z3 = z1 - z2;
		z3.Display();
	}
	return 0;
}