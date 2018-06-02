/*
题目描述
编写一个复数类，能实现加、减运算，能输出复数的信息。
要求至少包含以下方法：
1、缺省（无参）构造函数，设置实部与虚部为1；
2、有参构造函数，给实部与虚部赋值；
3、加法运算，返回两个复数的和；
4、减法运算，返回两个复数的差；
5、输出方法，输出当前复数的值

输入
测试数据的组数t 
第一组的两个复数的实部 虚部 实部 虚部
第二组的两个复数的实部 虚部 实部 虚部 
...... 

输出
第一组两个复数的和 
第一组两个复数的差 

样例输入
4
2 1 2 1
2 1 2 -1
3 1 2 -6
3 3 2 2

样例输出
sum:4+2i
remainder:0
sum:4
remainder:2i
sum:5-5i
remainder:1+7i
sum:5+5i
remainder:1+i
*/
# include <stdio.h>
class Complex
{
private:
     int a , b;
public:
	Complex()				{a = 1;b = 1;}
	Complex( int m , int n ){a = m;b = n;}
	Complex add( Complex &r )
	{
		Complex sum;
		sum.a = a + r.a;
		sum.b = b + r.b;
		sum.add_display(sum);
		return sum;
	}
	Complex sub( Complex &r )
	{
		Complex remainder;
		remainder.a = a - r.a;
		remainder.b = b - r.b;
		remainder.sub_display(remainder);
		return remainder;
	}
    void add_display( Complex &rr )
	{
		     if ( rr.a == 0 )
		{
			//考虑实部的0，虚部的0，+1和-1；
			     if ( rr.b ==  0 )
				printf("sum:0\n");
			else if ( rr.b ==  1 )
				printf("sum:i\n");
			else if ( rr.b == -1 )
				printf("sum:-i\n");
			else if ( rr.b <   0 )
				printf("sum:-%di\n",-rr.b);
			else if ( rr.b >   0 )
				printf("sum:%di\n", rr.b);
		}
		else if ( rr.a != 0 )
		{
			     if ( rr.b == 0 )
				printf("sum:%d\n",rr.a);
			else if ( rr.b ==  1 )
				printf("sum:%d+i\n",rr.a);
			else if ( rr.b == -1 )
				printf("sum:%d-i\n",rr.a);
			else if ( rr.b <  0 )
				printf("sum:%d-%di\n",rr.a,-rr.b);
			else if ( rr.b >  0 )
				printf("sum:%d+%di\n",rr.a, rr.b);
		}
	}
	void sub_display( Complex &rr )
	{
		     if ( rr.a == 0 )
		{
			     if ( rr.b ==  0 )
				printf("remainder:0\n");
			else if ( rr.b ==  1 )
				printf("remainder:i\n");
			else if ( rr.b == -1 )
				printf("remainder:-i\n");
			else if ( rr.b <   0 )
				printf("remainder:-%di\n",-rr.b);
			else if ( rr.b >   0 )
				printf("remainder:%di\n", rr.b);
		}
		else if ( rr.a != 0 )
		{
			     if ( rr.b == 0 )
				printf("remainder:%d\n",rr.a);
			else if ( rr.b ==  1 )
				printf("remainder:%d+i\n",rr.a);
			else if ( rr.b == -1 )
				printf("remainder:%d-i\n",rr.a);
			else if ( rr.b <  0 )
				printf("remainder:%d-%di\n",rr.a,-rr.b);
			else if ( rr.b >  0 )
				printf("remainder:%d+%di\n",rr.a, rr.b);
		}
	}
};
int main()
{
	int a,b,c,d;
	int t;
	scanf("%d",&t);
	while ( t-- )
	{
		scanf("%d%d%d%d",&a,&b,&c,&d);
		Complex z1(a,b);
		Complex z2(c,d);
		z1.add(z2);
		z1.sub(z2);
	}
	return 0;
}