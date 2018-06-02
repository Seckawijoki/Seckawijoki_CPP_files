# include <iostream>
using namespace std;
class Complex;
Complex operator +  ( Complex & , Complex & );
Complex operator -  ( Complex & , Complex & );
ostream & operator << ( ostream & , Complex & );
class Complex
{
private:
	double a;//Ðé²¿
	double b;//Êµ²¿
public:
	Complex()
	{
		a = 0;
		b = 0;
	}
	Complex( double d )
	{
		a = 0;
		b = d;
	}
	Complex( double x , double y )
	{
		a = x;
		b = y;
	}
	Complex  operator = ( double d ) const
	{
		Complex z;
		z.b = d;
		return z;
	}
	friend Complex operator +  ( Complex & , Complex & );
	friend Complex operator -  ( Complex & , Complex & );
	friend ostream & operator << ( ostream & , Complex & );
};
Complex operator + ( Complex &z1 , Complex &z2 )
{
	Complex z0;
	z0.a = z1.a + z2.a;
	z0.b = z1.b + z2.b;
	return z0;
}
Complex operator - ( Complex &z1 , Complex &z2 )
{
	Complex z0;
	z0.a = z1.a - z2.a;
	z0.b = z1.b - z2.b;
	return z0;
}
ostream & operator << ( ostream &stream , Complex &z )
{
	double a = z.a;
	double b = z.b;
	/**/ if ( a ==  0 )
		stream<<b;
	else if ( a == -1 )
	{
		/**/ if ( b >  0 )
			stream<<"-i+"<<b;
		else if ( b == 0 )
			stream<<"-i";
		else if ( b <  0 )
			stream<<"-i" <<b;
	}
	else if ( a ==  1 )
	{
		/**/ if ( b >  0 )
			stream<<"i+"<<b;
		else if ( b == 0 )
			stream<<"i";
		else if ( b <  0 )
			stream<<"i" <<b;
	}
	else
	{
		/**/ if ( b >  0 )
			stream<<a<<"i+"<<b;
		else if ( b == 0 )
			stream<<"i";
		else if ( b <  0 )
			stream<<a<<"i" <<b;
	}
	return stream;
}
int main()
{
	Complex aa(2,5),bb(7,8),cc(0,0);
	cc = aa + bb;
	cout<<" cc = "<<cc<<endl;
	cc = Complex(4.1) + aa;
	cout<<" cc = "<<cc<<endl;
	cc = bb + Complex(5.6);
	cout<<" cc = "<<cc<<endl;
	return 0;
}

