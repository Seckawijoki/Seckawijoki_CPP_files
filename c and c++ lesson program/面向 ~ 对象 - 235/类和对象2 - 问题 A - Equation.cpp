/*
��Ŀ����
����һ����Equation����﷽��ax2+bx+c=0��
�������ٰ������·�����
�޲ι��캯�����вι��캯�������ڳ�ʼ��a��b��c��ֵ��
set�����������޸�a��b��c��ֵ��
getRoot������������̵ĸ���

����
����������ݵ�����t
��һ��a��b��c
�ڶ���a��b��c

���
������̵ĸ�

��������
3
2 4 2
2 2 2
2 8 2

�������
x1=x2=-1.00
x1=-0.50+0.87i x2=-0.50-0.87i
x1=-0.27 x2=-3.73
*/
# include <stdio.h>
# include <math.h>
class Equation
{
private:
	double a;
	double b;
	double c;
public:
	Equation()
	{
		a = 1;
		b = -2;
		c = 1;
	}
	Equation( double p , double q , double r )
	{
		a = p;
		b = q;
		c = r;
	}
	void setA( double p ){ a = p; }
	void setB( double q ){ b = q; }
	void setC( double r ){ c = r; }
	void getRoot()
	{
		double delta = b * b - 4 * a * c;
		if ( delta == 0 )
		{
			//......������2a������2.
			printf("x1=x2=%.2lf\n",-b/2/a);
		}
		else if ( delta > 0 )
		{
			printf("x1=%.2lf ",  -b/2/a + sqrt(delta)/2/a );			
			printf("x2=%.2lf\n", -b/2/a - sqrt(delta)/2/a );			
		}
		else if ( delta < 0 )
		{
			printf("x1=%.2lf+%.2lfi ",  -b/2/a , sqrt(-delta)/2/a );			
			printf("x2=%.2lf-%.2lfi\n", -b/2/a , sqrt(-delta)/2/a );			
		}
	}
};
int main()
{
	double a,b,c;
	int t;
	scanf("%d",&t);
	while ( t-- )
	{
		scanf("%lf %lf %lf",&a,&b,&c);
		Equation some(a,b,c);
		some.getRoot();
	}
	return 0;
}