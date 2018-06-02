/*
题目描述
定义一个三维点Point类，利用友元函数重载"++"和"--"运算符，
并区分这两种运算符的前置和后置运算。

要求如下：
1.实现Point类；
2.编写main函数，初始化1个Point对象，
将这个对象++或--后赋给另外一个对象，
并输出计算后对象的坐标信息。

输入
第1行：输入三个int类型的值，分别为一个Point对象p1的x,y,z坐标。

输出
第1行：Point对象p1后置++之后的坐标信息输出。
第2行：Point对象p1后置++操作后
	   赋给另外一个Point对象p2的坐标信息。
第3行开始，依次输出前置++，后置--，前置--运算的坐标信息，
           输出格式与后置++一样。
样例输入
10 20 30

样例输出
x=11 y=21 z=31
x=10 y=20 z=30
x=11 y=21 z=31
x=11 y=21 z=31
x=9 y=19 z=29
x=10 y=20 z=30
x=9 y=19 z=29
x=9 y=19 z=29
*/
# include <iostream>
using namespace std;
class SpacePoint;
SpacePoint operator ++ ( SpacePoint & );
SpacePoint operator ++ ( SpacePoint & , int );
SpacePoint operator -- ( SpacePoint & );
SpacePoint operator -- ( SpacePoint & , int );
class SpacePoint
{
private:
	double x;
	double y;
	double z;
public:
	SpacePoint( double a = 0, double b = 0, double c = 0 )
	{
		x = a;
		y = b;
		z = c;
	}
	
	void Display()
	{
		cout<< "x="<<x
			<<" y="<<y
			<<" z="<<z<<endl;
	}
	friend SpacePoint operator ++ ( SpacePoint & );
	friend SpacePoint operator ++ ( SpacePoint & , int );
	friend SpacePoint operator -- ( SpacePoint & );
	friend SpacePoint operator -- ( SpacePoint & , int );
	SpacePoint operator =  ( SpacePoint &q )
	{
		x = q.x;
		y = q.y;
		z = q.z;
		return *this;
	}
};
SpacePoint operator ++ ( SpacePoint &p )
{
	p.x++;
	p.y++;
	p.z++;
	return p;
}
SpacePoint operator ++ ( SpacePoint &p , int )
{
	SpacePoint q;
	q.x = p.x;
	q.y = p.y;
	q.z = p.z;
	p.x++;
	p.y++;
	p.z++;
	return q;
}
SpacePoint operator -- ( SpacePoint &p )
{
	p.x--;
	p.y--;
	p.z--;
	return p;
}
SpacePoint operator -- ( SpacePoint &p , int )
{
	SpacePoint q;
	q.x = p.x;
	q.y = p.y;
	q.z = p.z;
	p.x--;
	p.y--;
	p.z--;
	return q;
}
int main()
{
	double a,b,c;
	cin>>a>>b>>c;
	SpacePoint p1(a,b,c),p2;

	(++p1).Display();
	--p1;
	p2 = p1;
	(p2).Display();

	(++p2).Display();
	(p2--).Display();
	(--p2).Display();

	(++p2).Display();
	(--p2).Display();
	(p2--).Display();
	return 0;
}