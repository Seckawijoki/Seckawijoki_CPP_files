/*
题目描述
定义一个CPoint点类，包含数据成员x,y（坐标点）。
以CPoint为基类，派生出一个圆形类CCircle，
增加数据成员r(半径）和一个计算圆面积的成员函数。

再以CCircle做为直接基类，派生出一个圆柱体类CCylinder，
增加数据成员h(高)和一个计算体积的成员函数。

生成圆和圆柱体对象，调用成员函数计算面积或体积并输出结果。

输入
输入圆的圆心位置、半径
输入圆柱体圆心位置、半径、高

输出
输出圆的圆心位置 半径
输出圆面积
输出圆柱体的圆心位置 半径 高
输出圆柱体体积

样例输入
0 0 1
1 1 2 3

样例输出
Circle:(0,0),1
Area:3.14
Cylinder:(1,1),2,3
Volume:37.68
*/
# include <iostream>
# include <cmath>
using namespace std;
class Point
{
protected:
	double x,y;
public:
	Point()
	{
		x = 0;
		y = 0;
	}
	Point( double a , double b )
	{
		x = a;
		y = b;
	}
	void Display()
	{
		cout<<'('<<x<<','<<y<<")";
	}
};
class Circle:public Point
{
protected:
	double radius;
public:
	Circle()
	{
		radius = 0;
	}
	Circle( double a , double b , double r ):Point(a,b)
	{
		radius = r;
	}
	double GetArea()
	{
		return 3.14*radius*radius;
	}
	void Display()
	{
		cout<<"Circle:";
		Point::Display();
		cout<<','<<radius<<endl;
	}
};
class Cylinder:public Circle
{
protected:
	double height;
public:
	Cylinder()
	{
		height = 0;
	}
	Cylinder( double a , double b , double r , double h ):Circle(a,b,r)
	{
		height = h;
	}
	double GetVolume()
	{
		return GetArea()*height;
	}
	void Display()
	{
		cout<<"Cylinder:";
		Point::Display();
		cout<<','<<radius<<','<<height<<endl;
	}
};
int main()
{
	double a,b,r,h;

	cin>>a>>b>>r;
	Circle round(a,b,r);
	round.Circle::Display();
	cout<<"Area:"<<round.GetArea()<<endl;

	cin>>a>>b>>r>>h;
	Cylinder cylinder(a,b,r,h);
	cylinder.Cylinder::Display();
	cout<<"Volume:"<<cylinder.GetVolume()<<endl;
	return 0;
}