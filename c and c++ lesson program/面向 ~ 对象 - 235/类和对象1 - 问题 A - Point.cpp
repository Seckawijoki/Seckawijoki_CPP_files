/*
题目描述
下面是一个平面上的点的类定义，
请在类外实现它的所有方法，并生成点测试它。

输入
测试数据的组数 t
第一组测试数据点p1的x坐标   
第一组测试数据点p1的y坐标  
第一组测试数据点p2的x坐标   
第一组测试数据点p2的y坐标
..........

输出
输出p1到p2的距离

样例输入
2
1 2 3 4
-1 0.5 -2 5

样例输出
Distance of Point(1.00,2.00) to Point(3.00,4.00) is 2.83
Distance of Point(-1.00,0.50) to Point(-2.00,5.00) is 4.61
*/
# include <stdio.h>
# include <math.h>
class Point
{
	double x1 , y1;
public:
	Point()
	{ x1 = 0 ; y1 = 0 ; }
	Point( double xx , double yy );
	//有参构造函数，给x,y赋参数的值
	double getX(){ return x1 ; }//返回x的值
	double getY(){ return y1 ; }//返回y的值
	double distance( Point p2 );
	void setX( double xx ){ x1 = xx ; }//设置x的值
	void setY( double yy ){ y1 = yy ; }//设置y的值
};
//类定义与类实现分开：
double Point::distance( Point p2 )
{
	double a = getX();
	double b = getY();
	double c = p2.getX();
	double d = p2.getY();
	long double kyouri = sqrt((a-c)*(a-c)+(b-d)*(b-d));
//	printf("p1( %.2lf , %.2lf ) , p2 ( %.2lf , %.2lf ) \n",x1,y1,a,b);
//	printf("distance = %.2lf\n",kyouri);
	return double(kyouri);
}
int main()
{
	double x1,y1,x2,y2;
	int t;
	scanf("%d",&t);
	Point p1;
	Point p2;
	while ( t-- )
	{
		scanf("%lf %lf",&x1,&y1);
		scanf("%lf %lf",&x2,&y2);
		p1.setX(x1);
		p1.setY(y1);
		p2.setX(x2);
		p2.setY(y2);
		printf("Distance of Point(%.2lf,%.2lf) to Point(%.2lf,%.2lf) is %.2lf\n",p1.getX(),p1.getY(),p2.getX(),p2.getY(),p1.distance(p2));
	}
	return 0;
}
