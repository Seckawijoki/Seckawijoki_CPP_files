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
# include <iostream>
# include <cmath>
# include <iomanip>
using namespace std;
class Pointo
{
private:
	double *x,*y;
public:
	Pointo()
	{
		x = new double(0) ;
		y = new double(0) ;
		cout<<"Constructor.\n";
	}
	Pointo( double x0 , double y0 )
	{ 
		x = new double(x0) ;
		y = new double(y0) ;
		cout<<"Constructor.\n";
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
		cout<<"Distructor.\n";
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
	double d[22];
	for ( i = 0 ; i < size ; i ++ )
		d[i] = kyouri[i];
	for ( i = 0 ; i < size ; i ++ )//i = 1ԭ��~
		if ( d[0] < kyouri[i] )
			 d[0] = kyouri[i];
	for ( i = 0 ; i < size ; i ++ )
		if ( d[0] == kyouri[i] )
			return i;
	return 1;
}
int main()
{
	int i,j,k,t,size,index;
	double a,b,*kyouri,distance[11][11];//������ö�ά���顣
	cin>>t;
	while ( t-- )
	{
		cin>>size;
		Pointo *p;
		p = new Pointo [size];
		kyouri = new double [size*(size-1)];
		for ( i = 0 ; i < size ; i ++ )
		{
			cin>>a>>b;
			p[i].OkuXY(a,b);
		}
		for ( i = 0 , k = 0; i < size ; i ++  )
			for ( j = i+1 ; j < size ; j ++ , k++ )
			{
				kyouri[k] = p[i].ToruKyouri(p[j]);
				distance[i][j] = kyouri[k];
			}
		index = questing_maxture(kyouri,k);//��50%��û�п��Ǵ�����������ʱ��
		for ( i = 0 ; i < size ; i ++ )
			for ( j = i+1 ; j < size ; j ++ )
				if ( distance[i][j] == kyouri[index] )
					cout<<"The longeset distance is "<<fixed<<setprecision(2)<<kyouri[index]<<",between p["<<i<<"] and p["<<j<<"].\n";
		delete [] p;
	}
	return 0;
}