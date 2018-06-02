/*
��Ŀ����
������һ��ƽ���ϵĵ���ඨ�壬
��������ʵ���������з����������ɵ��������

����
�������ݵ����� t
��һ��������ݵ�p1��x����   
��һ��������ݵ�p1��y����  
��һ��������ݵ�p2��x����   
��һ��������ݵ�p2��y����
..........

���
���p1��p2�ľ���

��������
2
1 2 3 4
-1 0.5 -2 5

�������
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
	//�вι��캯������x,y��������ֵ
	double getX(){ return x1 ; }//����x��ֵ
	double getY(){ return y1 ; }//����y��ֵ
	double distance( Point p2 );
	void setX( double xx ){ x1 = xx ; }//����x��ֵ
	void setY( double yy ){ y1 = yy ; }//����y��ֵ
};
//�ඨ������ʵ�ַֿ���
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
