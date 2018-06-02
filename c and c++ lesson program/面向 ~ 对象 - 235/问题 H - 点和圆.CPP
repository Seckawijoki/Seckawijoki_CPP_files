/*
题目描述
设计一个点类Point，包含属性：x坐标和y坐标，
方法：设定坐标（SetPoint），获取x坐标（GetX），获取y坐标（GetY）
设计一个圆类Circle，
包含属性：圆心坐标x和y、半径r；
方法包括：
1. 设定圆心（SetCenter），设置圆心x坐标和y坐标
2. 设定半径（SetRadius），设置半径长度
3. 计算面积（getArea），计算公式：面积=3.14*r*r
4. 计算周长（getLength），计算公式：周长=2*3.14*r
5. 包含（Contain），判断一个圆是否包含一个点，
计算圆心到这个点的距离，然后和半径做比较，
大于则不包含，小于等于则包含

注意：提交代码时必须用注释划分出三个区域：
类定义、类实现、主函数，如下

//-----类定义------
class XXX
{ 
// 写类定义代码
};
//----类实现------
void Process::XXX()
{ 
// 写类定义代码
};
//-----主函数-----
int main()
{
  //自定义一些变量
  //创建一个圆对象和一个点对象
  //输入圆对象和点对象的属性数值，并做初始化
  //输出圆的面积和圆的周长
  //输出圆是否包含点，包含则输出yes，否则输出no
  return 0;
}

输入
第一行输入圆的三个参数：圆心的x和y坐标，半径
第二行输入点的两个参数：x和y坐标
输出
第一行输出圆的面积和周长，结果之间用空格隔开
第二行输出圆是否包含点，包含则输出yes，否则输出no

在C++中，输出指定精度的参考代码如下：
#include <iostream>
#include <iomanip> //必须包含这个头文件
using namespace std;
void main( )
{
	double a =3.141596;
	cout<<fixed<<setprecision(3)<<a<<endl; //输出小数点后3位
样例输入
1 1 1
2 2
样例输出
3.14 6.28
no
提示
求两点距离的公式 dis =sqrt [ (x1-x2)^2  + (y1-y2)^2 ] ，
 ^2表示平方，sqrt表示开平方根，本公式只是表示含义，
 不是真实代码
在C++使用sqrt函数可以求平方根，头文件包含cmath
*/
# include <stdio.h>
# include <math.h>
double const PI = 3.14;
class Point
{
private:
	double x , y;
public:
	Point(){ x = 0 ; y = 0 ; }
	double GetX(){ return x; }
	double GetY(){ return y; }
	void SetX( double a1 ){ x = a1; }
	void SetY( double a2 ){ y = a2; }
};
class Round
{
private:
	double x , y , r , s , c ;
	Point pp;
public:
	Round(){ x = 0 ; y = 0 ; r = 0 ; s = 0 ; c = 0 ; }
	double GetArea();
	double GetLength();
	void Contain( Point pp );
	double GetX(){ return x; }
	double GetY(){ return y; }
	double GetR(){ return r; }
	void SetX( double a1 ){ x = a1; }
	void SetY( double a2 ){ y = a2; }
	void SetR( double a3 ){ r = a3; }
}; 
//类定义与类实现分开：
double Round::GetArea()
{
	s = PI * r * r;
	return s;
}
double Round::GetLength()
{
	c = 2 * PI * r;
	return c;
}
void Round::Contain( Point pp )
{
	double x1,x2,y1,y2,rr;
	//注意下面的取值方法。
	x1 = GetX();
	y1 = GetY();
	x2 = pp.GetX();
	y2 = pp.GetY();
	rr = GetR();
	double d = sqrt((x1-x2)*(x1-x2)+(y1-y2)*(y1-y2));
	if ( d > rr )
		printf("no\n");
	else
		printf("yes\n");
}
int main()
{
	double x1,y1,r,x2,y2;
	Point pp;
	Round rr;
	scanf("%lf%lf%lf%lf%lf",&x1,&y1,&r,&x2,&y2);
	pp.SetX(x2);
	pp.SetY(y2);
	rr.SetX(x1);
	rr.SetY(y1);
	rr.SetR(r);
	printf("%.2lf %.2lf\n",rr.GetArea(),rr.GetLength());//括号~~
	rr.Contain(pp);
	return 0;
}