/*
题目描述
编写一个程序，定义抽象基类Shape，在Shape类中定义虚函数Area()；
由它派生出3个派生类：
Circle(圆形)、Square(正方形)、Rectangle(矩形)。
用虚函数分别计算几种图形面积。
1、要求输出结果保留两位小数。
2、要求用基类指针数组，使它每一个元素指向一个派生类对象。

输入
测试数据的组数 t
第一组测试数据中圆的半径
第一组测测试数据中正方形的边长
第一组测试数据中矩形的长、宽
.......
第 t 组测试数据中圆的半径
第 t 组测测试数据中正方形的边长
第 t 组测试数据中矩形的长、宽

输出
第一组数据中圆的面积
第一组数据中正方形的面积
第一组数据中矩形的面积
......
第 t 组数据中圆的面积
第 t 组数据中正方形的面积
第 t 组数据中矩形的面积

样例输入
2
1.2
2.3
1.2 2.3
2.1
3.2
1.23 2.12

样例输出
4.52
5.29
2.76
13.85
10.24
2.61

*/
# include <stdio.h>
const double Pi = 3.1415926;
class Shape
{
public:
	virtual double Area() = 0;
};
class Circle:public Shape
{
protected:
	double r;
public:
	Circle()
	{
		r = 0;
	}
	Circle( double r0 )
	{
		r = r0;
	}
	virtual double Area()
	{
		return Pi * r * r;
	}
};
class Square:public Shape
{
protected:
	double a;
public:
	Square()
	{
		a = 0;
	}
	Square( double a0 )
	{
		a = a0;
	}
	virtual double Area()
	{
		return a * a;
	}
};
class Rectangle:public Shape
{
protected:
	double b,c;
public:
	Rectangle()
	{
		b = 0;
		c = 0;
	}
	Rectangle( double b0 , double c0 )
	{
		b = b0;
		c = c0;
	}
	virtual double Area()
	{
		return b * c;
	}
};
int main()
{
	int t;
	double r,a,b,c;
	scanf("%d",&t);
	Shape *variousShapes;
	while ( t-- )
	{
		scanf("%lf%lf%lf%lf",&r,&a,&b,&c);

		Circle circle(r);
		variousShapes = &circle;
		printf("%.2lf\n",variousShapes->Area());

		Square square(a);
		variousShapes = &square;
		printf("%.2lf\n",variousShapes->Area());

		Rectangle rectangle(b,c);
		variousShapes = &rectangle;
		printf("%.2lf\n",variousShapes->Area());
	}
	return 0;
}
