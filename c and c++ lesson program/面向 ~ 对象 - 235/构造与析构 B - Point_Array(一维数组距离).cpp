/*
��Ŀ����
����������������ϰ����һ��ϰ�⣬
����ԭ������Ļ������������޸ģ�
1��������д�Ŀ������캯����
2��������д������������
3����getDisTo�����Ĳ����޸�ΪgetDisTo(const Point &p)��
4��������������������޸���Ӧ�Ĺ��캯����
Ȼ�����������и����û��������Ŀ����Point���飬
��������ھ�������������֮��ľ���ֵ��

����
�������ݵ����� t
��һ���ĸ���
��һ����� x���� y����
�ڶ������ x���� y����
...........

���
�����һ����������������Լ������
...........

��������
2
4
0 0
5 0
5 5
2 10
3
-1 -8
0 9
5 0

�������
Constructor.
Constructor.
Constructor.
Constructor.
The longeset distance is 10.44,between p[1] and p[3].
Distructor.
Distructor.
Distructor.
Distructor.
Constructor.
Constructor.
Constructor.
The longeset distance is 17.03,between p[0] and p[1].
Distructor.
Distructor.
Distructor.
*/
# include <stdio.h>
# include <math.h>
class Pointo
{
private:
	double *x,*y;
public:
	Pointo()
	{
		x = new double(0) ;
		y = new double(0) ;
		printf("Constructor.\n");
	}
	Pointo( double x0 , double y0 )
	{ 
		x = new double(x0) ;
		y = new double(y0) ;
		printf("Constructor.\n");
	}
	double ToruX(){ return *x; }
	double ToruY(){ return *y; }
	void OkuX( double x0 ){ *x = x0; }
	void OkuY( double y0 ){ *y = y0; }
	void OkuXY(double x0 , double y0 )
	{
		*x = x0;
		*y = y0;
	}
	Pointo( Pointo &p )
	{
		double *a = p.x;
		double *b = p.y;
		x = new double(*a) ;
		y = new double(*b) ;
	}
	~Pointo()
	{
		delete []x;
		delete []y;
		printf("Distructor.\n");
	}
	double ToruKyouri( const Pointo &p )
	{
		double *a = p.x;
		double *b = p.y;
		return sqrt((*x-*a)*(*x-*a) + (*y-*b)*(*y-*b));
	}
};
int questing_maxture( double *kyouri , int size )
{
	int i;
	double d[11];
	for ( i = 0 ; i < size ; i ++ )
		d[i] = kyouri[i];
	for ( i = 1 ; i < size ; i ++ )
		if ( d[0] < kyouri[i] )
			 d[0] = kyouri[i];
	for ( i = 0 ; i < size ; i ++ )
		if ( d[0] == kyouri[i] )
			return i;
}
int main()
{
	int i,j,k,t,size,index,temp;
	double a,b,*kyouri,*distance;//������ö�ά���顣
	scanf("%d",&t);
	while ( t-- )
	{
		scanf("%d",&size);
		Pointo *p;
		p = new Pointo [size];
		kyouri = new double [size*(size-1)];
		distance = new double [size*(size-1)];
		for ( i = 0 ; i < size ; i ++ )
		{
			scanf("%lf %lf",&a,&b);
			p[i].OkuXY(a,b);
		}
		for ( i = 0 , k = 0; i < size ; i ++ )
			for ( j = i+1 ; j < size ; j ++ )
			{
				kyouri[k] = p[i].ToruKyouri(p[j]);
				distance[k] = kyouri[k];
				k++;
			}
		index = questing_maxture(kyouri,k);
		for ( i = 0 , k = 0 , temp = 0; i < size ; i ++ )
		{
			for ( j = i+1 ; j < size ; j ++ , k ++)
				if ( distance[index] == kyouri[k] )
				{	
					temp++;
					break;
				}
				if ( temp )break;
		}
		printf("The longeset distance is %.2lf,between p[%d] and p[%d].\n",kyouri[k],i<j?i:j,i>j?i:j);
		delete []p;
	}
	return 0;
}