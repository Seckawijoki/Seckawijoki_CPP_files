/*
题目描述
定义一个三角形类CTriangle，属性包含三条边，面积，
用动态数组表示的三角形类型(等腰、等边、直角、一般三角形)。
行为包括构造，析构函数；
判断能否构成三角形以及其类型的函数，计算面积的函数等。
然后编写一个主函数,测试所定义的CTriangle类。

输入
测试数据的组数
第一组边1 第一组边2 第一组边3
第二组边1 第二组边2 第二组边3
......

输出
第一个三角形类型，面积
第二个三角形类型，面积
......

样例输入
3
3.0 2.0 6.0
3.0 4.0 5.0
1.0 1.0 1.414
样例输出
No triangle
right triangle, 6
isosceles right triangle, 0.5
*/
# include <iostream>
# include <cstring>
# include <cmath>
using namespace std;
class Sankakkei//三角形：triangle,三角形（さんかっけい）
{
private:
	double a;//边长：side,辺(あたり)
	double b;
	double c;
	double menseki;//面积：area,面積(めんせき)
	char *taipu;
public:
	Sankakkei()
	{
		a = 0;
		b = 0;
		c = 0;
		menseki = 0;
	}
	Sankakkei( double x , double y , double z )
	{
		a = x;
		b = y;
		c = z;
	}
	void OkuAtari( double x , double y , double z )
	{
		a = x;
		b = y;
		c = z;
	}
	void SankakkeiNoTaipu()
	{
		taipu = new char [33];
		if ( a + b > c && a + c > b && b + c > a )
		{
			if ( a == b && a == c  )
				strcpy(taipu,"equilateral triangle\0");
			else
			{
				if ( a == b && a != c || a == c && a != b || b == c && b != a )
				{
					if ( fabs(a*a + b*b - c*c) < 1e-3 || fabs(a*a + c*c - b*b) < 1e-3 || fabs(b*b + c*c - a*a) < 1e-3 ) 
						//建议用两者差的绝对值小于10的-3次方，小于0.001默认直角三角形。
						strcpy(taipu,"isosceles right triangle\0");
					else 
						strcpy(taipu,"isosceles triangle\0");
				}
				else
				{
					if ( fabs(a*a + b*b - c*c) < 1e-3 || fabs(a*a + c*c - b*b) < 1e-3 || fabs(b*b + c*c - a*a) < 1e-3 ) 
						strcpy(taipu,"right triangle\0");
					else 
						strcpy(taipu,"normal triangle\0");

				}
			}
		}
		else
			strcpy(taipu,"No triangle\0");
	}
	void KeisanMenseki()//计算：calculate,計算(けいさん)
	{
		if ( strcmp(taipu,"No triangle\0") == 0 )
			menseki = 0;
		else
		{
			double p = ( a + b + c ) / 2;
			menseki = sqrt(p*(p-a)*(p-b)*(p-c));
		}
	}
	void MiseruTaipu()
	{
		if ( menseki == 0 )
			cout<<taipu<<endl;
		else
			cout<<taipu<<", "<<menseki<<endl;
			//用C++便于输出正常小数。
	}

};
int main()
{
	int t;
	double x,y,z;
	cin>>t;
	while ( t-- )
	{
		cin>>x>>y>>z;
		Sankakkei triangle(x,y,z);
		triangle.SankakkeiNoTaipu();
		triangle.KeisanMenseki();
		triangle.MiseruTaipu();
	}
	return 0;
}