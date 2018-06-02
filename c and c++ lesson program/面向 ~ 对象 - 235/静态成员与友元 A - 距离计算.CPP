/*
题目描述
Point类的基本形式如下：

请完成如下要求：

1.实现Point类；
2.为Point类增加一个
友元函数double Distance(Point &a, Point &b),
用于计算两点之间的距离。
直接访问Point对象的私有数据进行计算。
3.编写main函数，输入两点坐标值，计算两点之间的距离。

输入
第1行：输入需计算距离的点对的数目
第2行开始，每行依次输入两个点的x和y坐标

输出
每行依次输出一组点对之间的距离
（结果直接取整数部分,不四舍五入 ）

样例输入
2
1 0 2 1
2 3 2 4
样例输出
1
1
*/
# include <stdio.h>
# include <math.h>
class Point
{
private:
	double x,y;
public:
	Point()
	{
		x = 0;
		y = 0;
	}
	Point( double a,double b )
	{
		x = a;
		y = b;
	}
	void SetXY( double a,double b )
	{
		x = a;
		y = b;
	}
	friend double Distance( Point &p1 , Point &p2 );
};
double Distance( Point &p1 , Point &p2 )
{
	return sqrt((p1.x-p2.x)*(p1.x-p2.x)+(p1.y-p2.y)*(p1.y-p2.y));
}
int main()
{
	int t;
	double a,b,c,d;
	scanf("%d",&t);
	while ( t-- )
	{
		scanf("%lf%lf%lf%lf",&a,&b,&c,&d);
		Point p1(a,b);
		Point p2(c,d);
		printf("%d\n",int(Distance(p1,p2)));
	}
	return 0;
}