/*
题目描述
Fraction类的基本形式如下：

要求如下：
1.实现Fraction类；common_divisor()和contracted()函数体可为空，不实现具体功能。
2.编写main函数，初始化两个Fraction对象的，计算它们之间的加减乘除。

输入
第1行：依次输入第1个和第2个Fraction对象的分子和分母值。

输出
每行依次分别输出加减乘除计算后的Fraction对象（直接输出分数值，不需要约简）。

样例输入
1 3 2 5
样例输出
fraction=11/15
fraction=-1/15
fraction=2/15
fraction=5/6
*/
# include <stdio.h>
class Fraction
{
private:
	int numberator;
	int denominator;
	int common_divisor(){}
	void contracted(){}
public:
	Fraction( int x = 0 , int y = 0 )
	{
		numberator = x;
		denominator = y;
	}
	Fraction( Fraction &f )
	{
		numberator = f.numberator;
		denominator = f.denominator;
	}
	Fraction operator + ( Fraction &f  )
	{
		Fraction temp;
		temp.numberator = numberator * f.denominator + denominator * f.numberator;
		temp.denominator = denominator * f.denominator ;
		return temp;
	}
	Fraction operator - ( Fraction &f  )
	{
		Fraction temp;
		temp.numberator = numberator * f.denominator - denominator * f.numberator;
		temp.denominator = denominator * f.denominator ;
		return temp;
	}
	Fraction operator * ( Fraction &f  )
	{
		Fraction temp;
		temp.numberator = numberator * f.numberator ;
		temp.denominator = denominator * f.denominator ;
		return temp;
	}
	Fraction operator / ( Fraction &f  )
	{
		Fraction temp;
		temp.numberator = numberator * f.denominator ;
		temp.denominator = denominator * f.numberator ;
		return temp;
	}
	void Display()
	{
		printf("fraction=");
		if ( numberator == 0 )
		{
			printf("0\n");
		}
		else if ( numberator <  0 )
		{
			if ( denominator ==  1 )
				printf("%d\n", numberator);
			else if ( denominator == -1 )
				printf("%d\n",-numberator);
			else if ( denominator > 0 )
				printf("%d/%d\n",numberator,denominator);
			else if ( denominator < 0 )
				printf("%d/%d\n",-numberator,-denominator);
		}
		else if ( numberator >  0 )
		{
			if ( denominator ==  1 )
				printf("%d\n", numberator);
			else if ( denominator == -1 )
				printf("%d\n",-numberator);
			else if ( denominator > 0 )
				printf("%d/%d\n",numberator,denominator);
			else if ( denominator < 0 )
				printf("%d/%d\n",-numberator,denominator);
		}
	}
};
int main()
{
	int a1,b1,a2,b2;
	scanf("%d%d%d%d",&a1,&b1,&a2,&b2);
	Fraction f1(a1,b1),f2(a2,b2),f3;
	f3 = f1 + f2;
	f3.Display();
	f3 = f1 - f2;
	f3.Display();
	f3 = f1 * f2;
	f3.Display();
	f3 = f1 / f2;
	f3.Display();
	return 0;
}