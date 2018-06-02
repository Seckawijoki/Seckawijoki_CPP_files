# include <iostream.h>
class RMB
{
protected:
	unsigned yuan;
	unsigned jf;
public:
	RMB( unsigned int d , unsigned int c )
	{
		yuan = d;
		jf = c;
		while ( jf >= 100 )
		{
			yuan++;
			jf -= 100;
		}
	}
	RMB operator + ( RMB &s )
	{
		unsigned int c = jf + s.jf;
		unsigned int d = yuan + s.yuan;
		RMB result(d,c);
		return result;
	}
	RMB &operator ++ ()
	{
		jf++;
		if ( jf >= 100 )
		{
			jf -= 100;
			yuan++;
		}
		return *this;
	}
	RMB & operator += ( const RMB &s )
	{
		jf += s.jf;
		yuan += s.yuan;
		if ( jf >= 100 )
		{
			jf -= 100;
			yuan++;
		}
		return *this;
	}
	RMB & operator += ( double m )
	{
		int myuan = m / 100;
		int mjf =  ( m - myuan ) / 100;
		jf += mjf;
		yuan += myuan;
		if ( jf >= 100 )
		{
			jf -= 100;
			yuan++;
		}
		return *this;
	}
	RMB & operator -= ( const RMB &s )
	{
		jf -= s.jf;
		yuan -= s.yuan;
		if ( jf <  0 )
		{
			jf += 100;
			yuan--;
		}
		return *this;
	}
	RMB & operator -= ( double m )
	{
		int myuan = m / 100;
		int mjf =  ( m - myuan ) / 100;
		jf -= mjf;
		yuan -= myuan;
		if ( jf <  0 )
		{
			jf += 100;
			yuan--;
		}
		return *this;
	}
	friend ostream & operator << ( ostream & , RMB & );
	friend RMB operator * ( const RMB & , double );
	friend RMB operator * ( double , const RMB & );
};
RMB operator * ( const RMB &s , double d )
{
	double money = s.yuan + s.jf / 100;
	double multiple = money * d;
	multiple += 0.005;
	RMB result( unsigned int(multiple) , multiple / 100 );
	return result;
}
RMB operator * ( double d , const RMB &s )
{
	double money = s.yuan + s.jf / 100;
	double multiple = money * d;
	multiple += 0.005;
	RMB result( unsigned int(multiple) , multiple / 100 );
	return result;
}
ostream & operator << ( ostream &stream , RMB &s )
{
	stream<<( s.yuan + s.jf / 100.0 );
	return stream;
}
int main()
{
	RMB d1(1,60);
	RMB d2(2,50);

	RMB d3(0,0);
	cout<<d3<<endl;

	d3 = d1 + d2;
	cout<<d3<<endl;

	++d3;
	cout<<d3<<endl;

	d3 += d1;
	cout<<d3<<endl;

	d3 += 1.56;
	cout<<d3<<endl;

	d3 += d1 * 2.90;
	cout<<d3<<endl;

	return 0;
}
