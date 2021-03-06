/*
题目描述
设向量X=(x1,x2,…,xn)和Y=(y1,y2…,yn)，
它们之间的加、减分别定义为：
  X+Y=(x1+y1,x2+y2,…,xn+yn)
  X-Y=(x1-y1,x2-y2,…,xn-yn)
编程序定义向量类Vector ,重载运算符“+”、“-”,实现向量之间的加、减运算；
并重载运算符”<<”作为向量的输出操作。

Vector类的基本形式如下：

要求如下：
1.实现Vector类；
2.编写main函数，初始化两个Vector对象的，计算它们之间的加减，并输出结果。

输入
第1行：输入10个int类型的值，初始化第一个Vector对象。
第2行: 输入10个int类型的值，初始化第一个Vector对象。

输出
第1行：2个Vector对象相加后的输出结果。
第2行：2个Vector对象相减后的输出结果。

样例输入
-4 1 0 10 5 -9 8 13 6 2
-11 8 10 17 -6 9 6 7 12 5
样例输出
-15 9 10 27 -1 0 14 20 18 7
7 -7 -10 -7 11 -18 2 6 -6 -3

*/
# include <iostream.h>
class Vector;
Vector operator + ( Vector & , Vector & );
Vector operator - ( Vector & , Vector & );
class Vector
{
private:
	double p[10];
public:
	Vector()
	{
		int i;
		for ( i = 0 ; i < 10 ; i++ )
			p[i] = 0;
	}
	Vector( double z[10] )
	{
		int i;
		for ( i = 0 ; i < 10 ; i++ )
			p[i] = z[i];
	}
	friend Vector operator + ( Vector & , Vector & );
	friend Vector operator - ( Vector & , Vector & );
	friend ostream & operator << ( ostream & , Vector & );
	//use "# include <iostream.h>"
};
Vector operator + ( Vector &v1 , Vector &v2 )
{
	Vector v0;
	int i;
	for ( i = 0 ; i < 10 ; i++ )
		v0.p[i] = v1.p[i] + v2.p[i];
	return v0;
}
Vector operator - ( Vector &v1 , Vector &v2 )
{
	Vector v0;
	int i;
	for ( i = 0 ; i < 10 ; i++ )
		v0.p[i] = v1.p[i] - v2.p[i];
	return v0;
}
ostream & operator << ( ostream &stream , Vector &v )
{
	int i;
	for ( i = 0 ; i < 9 ; i++ )
		stream<<v.p[i]<<' ';
	stream<<v.p[i];
	return stream;
}
int main()
{
	double x[10],y[10];
	int i;
	for ( i = 0 ; i < 10 ; i++ )
		cin>>x[i];
	for ( i = 0 ; i < 10 ; i++ )
		cin>>y[i];
	Vector vx(x);
	Vector vy(y);
	Vector vz;
	vz = vx + vy;
	cout<<vz<<endl;
	vz = vx - vy;
	cout<<vz<<endl;
	return 0;
}