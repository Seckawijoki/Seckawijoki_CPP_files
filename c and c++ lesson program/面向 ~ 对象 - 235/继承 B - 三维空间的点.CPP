/*
题目描述
定义一个平面上的点C2D类，
它含有一个getDistance()的成员函数，计算该点到原点的距离；
从C2D类派生出三维空间的点C3D类，
它的getDistance()成员函数计算该点到原点的距离。
试分别生成一个C2D和C3D的对象，计算它们到原点的距离。
三维空间的两点（x, y, z）和（x1, y1, z1）的距离公式如下：
[(x-x1)^2+(y-y1)^2+(z-z1)^2]^(1/2) 

输入
第一行二维坐标点位置
第二行三维坐标点位置1
第三行三维坐标点位置2

输出
第一行二维坐标点位置到原点的距离
第二行三维坐标点位置1到原点的距离
第三行三维坐标点位置2到原点的距离
第四行三维坐标点位置2赋值给二维坐标点变量后，
二维坐标点到原点的距离

样例输入
3 4
3 4 5
6 8 8
样例输出
5
7.07107
12.8062
10
*/
# include <iostream>
# include <cmath>
using namespace std;
class TwoDimensionalPoint
{
protected:
	double x,y;
public:
	TwoDimensionalPoint()
	{
		x = 0;
		y = 0;
	}
	TwoDimensionalPoint( double a , double b )
	{
		x = a;
		y = b;
	}
	double GetDistance()
	{
		return sqrt( x*x + y*y );
	}
};
class ThreeDimensionalPoint:public TwoDimensionalPoint
{
private:
	double z;
public:
	ThreeDimensionalPoint()
	{
		z = 0;
	}
	ThreeDimensionalPoint( double a , double b , double c ):TwoDimensionalPoint(a,b)
	{
		z = c;
	}
	double GetDistance()
	{
		return sqrt( x*x + y*y + z*z );
	}
};
int main()
{
	double a,b,c;

	cin>>a>>b;
	TwoDimensionalPoint point2D(a,b);
	cout<<point2D.GetDistance()<<endl;

	cin>>a>>b>>c;
	ThreeDimensionalPoint point3D1(a,b,c);
	cout<<point3D1.GetDistance()<<endl;

	cin>>a>>b>>c;
	ThreeDimensionalPoint point3D2(a,b,c);
	cout<<point3D2.GetDistance()<<endl;
	cout<<point3D2.TwoDimensionalPoint::GetDistance()<<endl;

	return 0;
}
