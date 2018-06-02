/*
题目描述
建立一个类Equation，表达方程ax2+bx+c=0。
类中至少包含以下方法：
无参构造函数与有参构造函数，用于初始化a、b、c的值；
set方法，用于修改a、b、c的值；
getRoot方法，求出方程的根。

输入
输入测试数据的组数t
第一组a、b、c
第二组a、b、c

输出
输出方程的根

样例输入
3
2 4 2
2 2 2
2 8 2

样例输出
x1=x2=-1.00
x1=-0.50+0.87i x2=-0.50-0.87i
x1=-0.27 x2=-3.73
*/
# include <stdio.h>
# include <math.h>
class Equation
{
private:
	double a;
	double b;
	double c;
public:
	Equation()
	{
		a = 1;
		b = -2;
		c = 1;
	}
	Equation( double p , double q , double r )
	{
		a = p;
		b = q;
		c = r;
	}
	void setA( double p ){ a = p; }
	void setB( double q ){ b = q; }
	void setC( double r ){ c = r; }
	void getRoot()
	{
		double delta = b * b - 4 * a * c;
		if ( delta == 0 )
		{
			//......忘了是2a而不是2.
			printf("x1=x2=%.2lf\n",-b/2/a);
		}
		else if ( delta > 0 )
		{
			printf("x1=%.2lf ",  -b/2/a + sqrt(delta)/2/a );			
			printf("x2=%.2lf\n", -b/2/a - sqrt(delta)/2/a );			
		}
		else if ( delta < 0 )
		{
			printf("x1=%.2lf+%.2lfi ",  -b/2/a , sqrt(-delta)/2/a );			
			printf("x2=%.2lf-%.2lfi\n", -b/2/a , sqrt(-delta)/2/a );			
		}
	}
};
int main()
{
	double a,b,c;
	int t;
	scanf("%d",&t);
	while ( t-- )
	{
		scanf("%lf %lf %lf",&a,&b,&c);
		Equation some(a,b,c);
		some.getRoot();
	}
	return 0;
}