/*
题目描述
上面是我们曾经练习过的一个习题，
请在原来代码的基础上作以下修改：
1、增加自写的拷贝构造函数；
2、增加自写的析构函数；
3、将getDisTo方法的参数修改为getDisTo(const Point &p)；
4、根据下面输出的内容修改相应的构造函数。
然后在主函数中根据用户输入的数目建立Point数组，
求出数组内距离最大的两个点之间的距离值。

输入
测试数据的组数 t
第一组点的个数
第一个点的 x坐标 y坐标
第二个点的 x坐标 y坐标
...........

输出
输出第一组距离最大的两个点以及其距离
...........

样例输入
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

样例输出
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
	double a,b,*kyouri,*distance;//距离可用二维数组。
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