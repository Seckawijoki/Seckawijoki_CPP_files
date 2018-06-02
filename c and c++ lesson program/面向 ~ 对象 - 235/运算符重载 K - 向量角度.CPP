/*
题目描述
定义一个二维vector（向量）类，vector
有两个成员：x、y(横坐标、纵坐标值)，
重载运算符“/”，实现两个向量之间的角度的计算，
即如下图所示求出angle的值。
并输出输入的所有向量中两个向量相差最大的角度为多少。

输入
第1行：向量数目
第2行开始，依次输入每个向量的x和y值（int类型）。

输出
所有向量中相差最大的角度

样例输入
2
1 1 
1 0

样例输出
角度相差最大为45度。

*/
# include <iostream>
# include <cmath>
using namespace std;
# define Pi 3.14159265
class Vector;
double operator / ( Vector & , Vector & );
class Vector
{
private:
	double x,y;
public:
	Vector()
	{
		x = 0;
		y = 0;
	}
	Vector( double a , double b )
	{
		x = a;
		y = b;
	}
	void SetXY( double a , double b )
	{
		x = a;
		y = b;
	}
	friend double operator / ( Vector & , Vector & );
};
double operator / ( Vector &v1 , Vector &v2 )
{
	long double xita1 = acos( v1.x / sqrt( v1.x * v1.x + v1.y * v1.y ));
	long double xita2 = acos( v2.x / sqrt( v2.x * v2.x + v2.y * v2.y ));
	return ( fabs( xita1 - xita2 ) * 180 ) / Pi;
}
int main()
{
	int i,j,t;
	double *m,*n,angle[11][11];
	Vector *vt;
	cin>>t;
	m = new double [t];
	n = new double [t];
	vt = new Vector [t];
	for ( i = 0 ; i < t ; i++ )
	{
		cin>>m[i]>>n[i];
		vt[i].SetXY(m[i],n[i]);
	}
	for ( i = 0 ; i < t ; i++ )
		for ( j = i + 1 ; j < t ; j++ )
		{
			angle[i][j] = vt[i] / vt[j];
		//	cout<<angle[i][j]<<endl;
		}
	double max = 0;
	for ( i = 0 ; i < t ; i++ )
		for ( j = i + 1 ; j < t ; j++ )
			if ( max < angle[i][j] )
				max = angle[i][j];
	cout<<"角度相差最大为"<<max<<"度。\n";
	return 0;
}